#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"
#include "Sculptor.h"
#include "Plotter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//! Class MainWindow
/*!
 * @brief The MainWindow class is responsible for performing various functions related to changes in variables by the user through the interface;
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! MainWindow class constructor.
    /*!
    * Acts as default constructor;
    **/
    MainWindow(QWidget *parent = nullptr);

    //! Destructor of the MainWindow class.
    /*!
    * Acts as the default destructor;
    **/
    ~MainWindow();
public slots:
    //! Public slot selectPlane 
    /*!
    * Performs various actions when resizing the sculptor;
    **/
    void selectPlane();
    //! Public slot changeRed 
    /*!
    * manipulates elements that need the color red;
    **/
    void changeRed(int);
    //! Public slot changeBlue 
    /*!
    * manipulates elements that need the blue color;
    **/
    void changeBlue(int);
    //! Public slot changeGreen 
    /*!
    * manipulates elements that need the color green;
    **/
    void changeGreen(int);
    //! Public slot changeAlpha 
    /*!
    * apply transparency
    **/
    void changeAlpha(int);
    //! Public slot changeXY 
    /*!
    * Ativa o plano XY como plano visível;
    **/
    void changeXY();
    //! Public slot changeYZ 
    /*!
    * Activate the XZ plane as a visible plane;
    **/
    void changeYZ();
    //! Public slot changeZX 
    /*!
    * Activates the ZX plane as a visible plane;
    **/
    void changeZX();
    //! Public slot pVoxel 
    /*!
    * Enables the construction of voxels with the PutVoxel model.
    **/
    void pVoxel();
    //! Public slot cVoxel 
    /*!
    * Enables the construction of voxels with the CutVoxel model.
    **/
    void cVoxel();
    //! Public slot pBox 
    /*!
    * Enables the construction of voxels with the PutBox model.
    **/
    void pBox();
    //! Public slot cBox 
    /*!
    * Enables the construction of voxels with the CutBox model.
    **/
    void cBox();
    //! Public slot pShpere 
    /*!
    * Enables the construction of voxels with the PutSphere model.
    **/
    void pShpere();
    //! Public slot cShpere 
    /*!
    * Enables the construction of voxels with the CutSphere model.
    **/
    void cShpere();
    //! Public slot pEllip 
    /*!
    * Enables the construction of voxels with the PutEllipsoid model.
    **/
    void pEllip();
    //! Public slot cEllip 
    /*!
    * Enables the construction of voxels with the CutEllipsoid model.
    **/
    void cEllip();
    //! Public slot geomview 
    /*!
    * It allows, after saving the OFF file generated in the application, selecting it and opening it in the GeomeView viewer.
    **/
    void geomview();
    //! Public slot meshlab 
    /*!
    * It allows, after saving the OFF file generated in the application, selecting it and opening it in the MeshLab viewer.
    **/
    void meshlab();

private slots:
    //! Private slot on_actionQuit_triggered 
    /*!
    * Close application;
    **/
    void on_actionQuit_triggered();
    //! Private slot on_actionCriar_arquivo_OFF_triggered 
    /*!
    * Requests path to generate the off file from the created sculpture.
    **/
    void on_actionCriar_arquivo_OFF_triggered();
    //! Private slot on_actionClear_all_triggered 
    /*!
    * Clean everything already drawn
    **/
    void on_actionClear_all_triggered();
    //! Private slot on_actionClear_all_triggered 
    /*!
    * Interpret conceptualization files and show in the flattened views widget
    **/
    void on_actionOpen_conceptualization_file_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
