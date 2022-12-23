#ifndef PUT_ELLIPSOID_H
  #define PUT_ELLIPSOID_H

  #include "GeometricFigure.h"

  //! Concrete class PutEllipsoid - Used to display a set of voxels belonging to an elliptical volume
  /*! 
   * \brief It will inform the system that all voxels present in a given elliptical region
   *        and belonging to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class, it should be **displayed**.
   *
   * @param x_center Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the center of the ellipse to be created;
   * @param y_center Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the center of the ellipse to be created;
   * @param z_center Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the center of the ellipse to be created;
   * @param x_radius Represents the radius of the ellipse to be created on the **x** axis;
   * @param y_radius Represents the radius of the ellipse to be created on the **y** axis;
   * @param z_radius Represents the radius of the ellipse to be created on the **z** axis;
   * 
   * It inherits directly from the GeometricFigure abstract class.
   **/
  class PutEllipsoid:public GeometricFigure{
    int x_center; /**< Central coordinate of the ellipse on the **x** axis.*/
    int y_center; /**< Central coordinate of the ellipse on the **y** axis.*/
    int z_center; /**< Central coordinate of the ellipse on the **z** axis.*/
    int x_radius; /**< Radius of the ellipse on the **x** axis.*/
    int y_radius; /**< Radius of the ellipse on the **y** axis.*/
    int z_radius; /**< Radius of the ellipse on the **z** axis.*/
  public:
    //! PutEllipsoid class constructor.
    /*!
     * This constructor will receive as parameters the dimensional coordinates of the voxel ellipse to be created, as well as its color and transparency. Therefore,
     * will construct an instance of the PutEllipsoid class.
     *
     *  @param x_center_ Central coordinate of the ellipse on the **x** axis;
     *  @param y_center_ Central coordinate of the ellipse on the **y** axis;
     *  @param z_center_ Central coordinate of the ellipse on the **z** axis;
     *  @param x_radius_ Radius of the ellipse on the **x** axis;
     *  @param y_radius_ Radius of the ellipse on the **y** axis;
     *  @param z_radius_ Radius of the ellipse on the **z** axis;
     *  @param r_ Represents the red component of the color that the ellipse will be painted on;
     *  @param g_ Represents the green component of the color that the ellipse will be painted on;
     *  @param b_ Represents the blue component of the color that the ellipse will be painted on;
     *  @param a_ Represents the transparency component of the color that the ellipse will be painted on;
     **/
    PutEllipsoid(int x_center_, int y_center_, int z_center_, int x_radius_, int y_radius_, int z_radius_, float r_, float g_, float b_, float a_);
    //! Destructor of the PutEllipsoid class.
    /*!
     * Acts as the default destructor;
     **/
    ~PutEllipsoid(){};
    //! Member function draw.
    /*!
     * Method that will create, from an instance of the Sculptor class passed as a parameter, an ellipse present in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_ELLIPSOID_H