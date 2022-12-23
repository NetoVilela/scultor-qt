#ifndef CUT_SPHERE_H
  #define CUT_SPHERE_H

  #include "GeometricFigure.h"

  //! Concrete class CutSphere - Used to erase a set of voxels belonging to a spherical volume
  /*! 
   *  \brief It will inform the system that all voxels, present in a certain spherical region
   *         and belonging to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class, must be **deleted**.
   *
   *  @param x_center Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the center of the sphere to be deleted;
   *  @param y_center Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the center of the sphere to be deleted;
   *  @param z_center Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the center of the sphere to be deleted;
   *  @param radius Represents the radius of the sphere to be deleted in three dimensions: **x**, **y** and **z**.
   * 
   *  It inherits directly from the GeometricFigure abstract class.
   **/
  class CutSphere:public GeometricFigure{
    int x_center; /**< Central coordinate of the sphere on the axis**x**.*/
    int y_center; /**< Central coordinate of the sphere on the axis**y**.*/
    int z_center; /**< Central coordinate of the sphere on the axis**z**.*/
    int radius; /**< Sphere radius in three dimensions.*/
  public:

    //! CutSphere class constructor.
    /*!
     *  This constructor will receive as parameters the dimensional coordinates of the voxel sphere to be deleted, thus,
     *  will construct an instance of the CutSphere class.
     *
     *  @param x_center_ Central coordinate of the sphere on the axis**x**;
     *  @param y_center_ Central coordinate of the sphere on the axis**y**;
     *  @param z_center_ Central coordinate of the sphere on the axis**z**;
     *  @param radius_   Sphere radius in three dimensions;
     **/
    CutSphere(int x_center_, int y_center_, int z_center_, int radius_);

    //! Destructor of the CutSphere class.
    /*!
     * Acts as the default destructor;
     **/
    ~CutSphere(){};

    //! Member function draw.
    /*!
     * Method that will delete, from an instance of the Sculptor class passed as a parameter, a sphere present in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_SPHERE_H