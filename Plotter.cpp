#include <cstring>

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <QPointF>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include "Plotter.h"

#include "Interpreter.h"

#include "Sculptor.h"

#include "PutVoxel.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "PutBox.h"

#include "CutVoxel.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "CutBox.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    sculptorDimensionX = sculptorDimensionY = sculptorDimensionZ = 30;
    sculptor = new Sculptor(sculptorDimensionX, sculptorDimensionY, sculptorDimensionZ);
    method = dim = x = y = z = rad = r = ry = rx = rz = g = b = 0;
    a = 255;
    plan = XY;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter pa(this);
    QPen pen;
    QBrush brush;

    int dim1, dim2;

    pen.setColor(QColor(0, 0, 0, 70));
    pen.setWidth(1);

    brush.setColor(QColor(255,255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pa.setPen(pen);
    pa.setBrush(brush);

    p.clear();
    p = sculptor -> readMx(dim,plan);

    dim1 = width()/p[0].size();
    dim2 = height()/p.size();
    if(dim1 >= dim2){
        square = dim2;
    } else {
        square = dim1;
    }

    for(unsigned int i = 0; i < p.size(); i++){
        for(unsigned int j = 0; j < p[0].size(); j++){
          QRectF rectangle(i*square, j*square, square, square);
          brush.setStyle(Qt::SolidPattern);
          if(p[i][j].isOn){
            brush.setColor(QColor(p[i][j].r, p[i][j].g, p[i][j].b, p[i][j].a));
          }else{
            brush.setColor(QColor(255, 255, 255, 255));
          }
          pa.setBrush(brush);
          pa.drawRoundedRect(rectangle, 3.0, 3.0);
       }
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event){
    if(!(event->button() == Qt::LeftButton)){
        press = false;
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event) {
    if(!press){ return; }
    mouseEvents(event);
}

void Plotter::mousePressEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton){ return; }
    mouseEvents(event);
}

void Plotter::changeRed(int red) { r = red; }
void Plotter::changeGreen(int green) { g = green; }
void Plotter::changeBlue(int blue) { b = blue; }
void Plotter::changeAlpha(int alpha) { a = alpha; }

void Plotter::changeDimx(int size) { x = size; }
void Plotter::changeDimy(int size) { y = size; }
void Plotter::changeDimz(int size) { z = size; }

void Plotter::changeRad(int rd) { rad=rd; }

void Plotter::changeRx(int radx) { rx=radx; }
void Plotter::changeRy(int rady) { ry=rady; }
void Plotter::changeRz(int radz) { rz=radz; }

void Plotter::changeSlice(int pln) { dim = pln; repaint(); }

void Plotter::shape(int method){
    if(!(px < sculptorDimensionX && py < sculptorDimensionY && pz < sculptorDimensionZ)) return;

    float red = (float)(r/255.0);
    float green = (float)(g/255.0);
    float blue = (float)(b/255.0);
    float alpha = (float)(a/255.0);

    switch(method) {
        case PVoxel:
          (new PutVoxel(px, py, pz, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CVoxel:
          (new CutVoxel(px, py, pz)) -> draw(*sculptor);
          break;
        case PBox:
          (new PutBox(px,(px+x),py,(py+y),pz,(pz+z), red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CBox:
          (new CutBox(px,(px+x),py,(py+y),pz,(pz+z))) -> draw(*sculptor);
          break;
        case PSphere:
          (new PutSphere(px, py, pz, rad, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CSphere:
          (new CutSphere(px, py, pz, rad)) -> draw(*sculptor);
          break;
        case PEllipsoid:
          (new PutEllipsoid(px, py, pz, rx, ry, rz, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CEllipsoid:
          (new CutEllipsoid(px, py, pz, rx, ry, rz)) -> draw(*sculptor);
          break;
    }
    repaint();
}

void Plotter::Off(){
    QString pathFile;
    QMessageBox box;
    QString msg;

    try {
      pathFile = QFileDialog::getSaveFileName(this, tr("Save file OFF"), "../", tr("OFF Files (*.off)"));
      if(pathFile != QString("")){
          this -> sculptor -> writeOFF(pathFile.toStdString());
          msg = "OFF file created successfully!";
          box.setText(msg);
          box.exec();
      }else{
          msg = "A path is required to save the OFF file.";
          box.setText(msg);
          box.exec();
      }
   } catch (const std::out_of_range& err) {
      msg = "[Error] An error occurred while reading/writing the off file..";
      box.setText(msg);
      box.exec();
   }
}

void Plotter::mouseEvents(QMouseEvent *event){
    press = true;

    emit clickX(event->position().x());
    emit clickY(event->position().y());

    mx = (event->position().x())/square;
    my = (event->position().y())/square;

    emit moveX(mx);
    emit moveY(my);

    switch(plan) {
      case XY:
        px = mx; py = my; pz = dim;
        break;
      case YZ:
        px = dim; py = mx; pz = my;
        break;
       case ZX:
        px = my; py = dim; pz = mx;
        break;
    }
    Plotter::shape(method);
}

void Plotter::clearAll(){
    sculptor -> clearAll();
    repaint();
}

void Plotter::openConseptualizationFile(QString path){
    sculptor->~Sculptor();

    Interpreter interpreter;

    std::vector<GeometricFigure*> figures = interpreter.parse(path.toStdString());
    sculptorDimensionX = interpreter.getDimX();
    sculptorDimensionY = interpreter.getDimY();
    sculptorDimensionZ = interpreter.getDimZ();
    sculptor = new Sculptor(sculptorDimensionX, sculptorDimensionY, sculptorDimensionZ);
    for(unsigned int i=0; i < figures.size(); i++){
      figures[i] -> draw(*sculptor);
    }

    repaint();
}
