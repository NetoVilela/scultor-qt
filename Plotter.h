#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QString>
#include "Sculptor.h"
#include "vector"
#include <iostream>
#include <cstring>

/*!
* @brief Enum for definition and better interpretation of available types and models of drawings
*/
enum{ PVoxel, CVoxel, PBox, CBox, PSphere, CSphere, PEllipsoid, CEllipsoid };


//! Class Plotter
/*!
* @brief The Plotter class is related to the creation and constant alteration of the drawing compound;
*/
class Plotter : public QWidget{
    Q_OBJECT

public:
    Sculptor *sculptor;     /**< sculptor is the Sculptor called for the first time when the program is opened;*/
    int method;             /**< method is the drawing form chosen by the user. PutVoxel is set to default; */
    int dim;                /**< dim is the dimension deleted by the user; */
    int plan;               /**< plan is the user-selected plan; */
    int sculptorDimensionX; /**< Size in x of the sculptor; */
    int sculptorDimensionY; /**< Size in y of the sculptor; */
    int sculptorDimensionZ; /**< Size in z of the sculptor; */
    int r;                  /**< r stores the channel value r(red); */
    int g;                  /**< g stores the channel value g(green); */
    int b;                  /**< b stores the channel value b(blue); */
    int a;                  /**< a stores the value of transparency; */
    int rad;                /**< rad stores the radius of the sphere */
    int rx;                 /**< rx stores the x-radius of the ellipsoid; */
    int ry;                 /**< ry stores the y-radius of the ellipsoid; */
    int rz;                 /**< rz stores the z-radius of the ellipsoid; */
    int x;                  /**< x stores the x dimensions of the box; */
    int y;                  /**< y stores the y dimensions of the box; */
    int z;                  /**< z stores the z dimensions of the box; */
    int h;                  /**< h stores the height of blank squares; */
    int w;                  /**< w stores the width of blank squares; */

    //! Plotter class constructor.
    /*!
    * Acts as default constructor;
    **/
    explicit Plotter(QWidget *parent = nullptr);
    //! Public method paintEvent
    /*!
    * @brief paintEvent is an event that draws an array of cubes and links them by slashes;
    * @param event is the event that is being handled.
    */
    void paintEvent(QPaintEvent *event);
    //! Public method mousePressEvent
    /*!
    * @brief mousePressEvent is an event that activates the isOn property of a voxel upon mouse click;
    * @param event is the event that is being handled.
    */
    void mousePressEvent(QMouseEvent *event);
    //! Public method mouseReleaseEvent
    /*!
    * @brief mouseReleaseEvent is an event that performs necessary actions (stops assigning the isOn property to voxels) after the left mouse button is released;
    * @param event is the event that is being handled.
    */
    void mouseReleaseEvent(QMouseEvent *event);
    //! Public method mouseMoveEvent
    /*!
    * @brief mouseMoveEvent is an event that performs actions when the mouse moves and the left button is pressed;
    * @param event is the event that is being handled.
    */
    void mouseMoveEvent(QMouseEvent *event);
    //! Public method shape
    /*!
    * @brief shape determines which geometric shape will be used, whether it has a "cut" or "put" property. There are 8 ways in total;
    * @param method stores the geometric shape chosen by the user;
    */
    void shape(int method);
private:
    std::vector<std::vector<Voxel>> p; /**< Array of voxels with on-screen sampling information */
    int square;                        /**< sets the dimension of rendered frames */
    int px;                            /**< Click position on the X axis */
    int py;                            /**< Click position on the Y axis */
    int pz;                            /**< Click position on the Z axis */
    bool press;                        /**< Stores information whether the user is clicking or not */
    bool enter;                        /**< stores information if events are taking place inside the widget */
    ///Mouse coordinates.
    int mx; /**< Mouse coordinates on the x axis */
    int my; /**< Mouse coordinates on the y axis */
    //! Private method mouseEvents
    /*!
    * @brief Generic and private mouseEvents function for handling mouse events within the widget.
    * @param event is the event that is being handled.
    */
    void mouseEvents(QMouseEvent *event);
signals:
    //! Signal moveX
    /*!
    * @brief Armazena as posições do mouse em X;
    */
    void moveX(int);
    //! Signal moveY
    /*!
    * @brief Armazena as posições do mouse em Y;
    */
    void moveY(int);
    //! Signal clickX
    /*!
    * @brief Armazena as posições em X que houve click;
    */
    void clickX(int);
    //! Signal clickY
    /*!
    * @brief Armazena as posições em Y que houve click;
    */
    void clickY(int);
    //! Signal planeChosen
    /*!
    * @brief planeChosen Armazena o plano escolhido;
    */
    void planeChosen(int);

public slots:
    //! Public Slot changeDimx
    /*!
    * @brief Stores dimension information in x;
    * @param size desired size;
    */
    void changeDimx(int size);
    //! Public Slot changeDimy
    /*!
    * @brief Stores dimension information in Y;
    * @param size desired size;
    */
    void changeDimy(int size);
    //! Public Slot changeDimz
    /*!
    * @brief Stores dimension information in Z;
    * @param size desired size;
    */
    void changeDimz(int size);
    //! Public Slot changeRad
    /*!
    * @brief modifies the radius of the sphere;
    * @param rd user-chosen sphere radius value;
    */
    void changeRad(int rd);
    //! Public Slot changeRx
    /*!
    * @brief changes the x-radius of the ellipsoid;
    * @param radx x-radius of the ellipsoid chosen by the user;
    */
    void changeRx(int radx);
    //! Public Slot changeRy
    /*!
    * @brief changes the y-radius of the ellipsoid;
    * @param rady y-radius of the ellipsoid chosen by the user;
    */
    void changeRy(int rady);
    //! Public Slot changeRz
    /*!
    * @brief changes the z-radius of the ellipsoid;
    * @param radz z-radius of the ellipsoid chosen by the user;
    */
    void changeRz(int radz);
    //! Public Slot changeRed
    /*!
    * @brief modifies the r(red) channel of the voxel;
    * @param red intensity of the component chosen by the user
    */
    void changeRed(int red);
    //! Public Slot changeGreen
    /*!
    * @brief modifies the g(green) channel of the voxel;
    * @param green intensity of the component chosen by the user
    */
    void changeGreen(int green);
    //! Public Slot changeBlue
    /*!
    * @brief modifies the b(blue) channel of the voxel;
    * @param blue intensity of the component chosen by the user
    */
    void changeBlue(int blue);
    //! Public Slot changeAlpha
    /*!
    * @brief modifies the voxel transparency value;
    * @param alpha intensity of the component chosen by the user
    */
    void changeAlpha(int alpha);
    //! Public Slot changeSlice
    /*!
    * @brief modifies which layer of the plane is being viewed;
    * @param pln value of the plan chosen by the user;
    */
    void changeSlice(int pln);
    //! Public Slot Off
    /*!
    * @brief Off is responsible for calling the write OFF function present in Sculptor and assigning a name to the OFF file;
    */
    void Off();
    //! Public Slot clearAll
    /*!
    * @brief Deletes everything that has already been drawn by calling the clear All function present in the sculptor
    */
    void clearAll();
    //! Public Slot openConseptualizationFile
    /*!
    * @brief Responsible for asking the user for a conceptualization file and sending it to the interpreter to capture the information and modify the sculptor
    */
    void openConseptualizationFile(QString path);
};

#endif // PLOTTER_H
