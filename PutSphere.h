#ifndef PUT_SPHERE_H
  #define PUT_SPHERE_H

  #include "GeometricFigure.h"

  //! Concrete class PutSphere - Used to display a set of voxels belonging to a spherical volume
  /*! 
   * \brief It will inform the system that all voxels, present in a certain spherical region
   *         and belonging to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class, it should be **displayed**.
   *
   * @param x_center Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the center of the sphere to be created;
   * @param y_center Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the center of the sphere to be created;
   * @param z_center Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the center of the sphere to be created;
   * @param radius Represents the radius of the sphere to be created, in the three dimensions, **x**, **y** and **z**;
   * 
   * It inherits directly from the GeometricFigure abstract class.
   **/
  class PutSphere:public GeometricFigure{
    int x_center; /**< Central coordinate of the sphere on the **x** axis.*/
    int y_center; /**< Central coordinate of the sphere on the **y** axis.*/
    int z_center; /**< Central coordinate of the sphere on the **z** axis.*/
    int radius; /**< Raio da esfera nas três dimensões.*/
  public:

    //! PutSphere class constructor.
    /*!
     * This constructor will receive as parameters the dimensional coordinates of the voxel sphere to be created, as well as its color and transparency. Therefore,
     * will construct an instance of the PutSphere class.
     *
     *  @param x_center_ Central coordinate of the sphere on the **x** axis;
     *  @param y_center_ Central coordinate of the sphere on the **y** axis;
     *  @param z_center_ Central coordinate of the sphere on the **z** axis;
     *  @param radius_ Raio da esfera nas três dimensões;
     *  @param r_ Represents a red component of the color the sphere will be painted;
     *  @param g_ Represents a green component of the color the sphere will be painted;
     *  @param b_ Represents a blue component of the color the sphere will be painted;
     *  @param a_ Represents the transparency component of the color that the painted sphere;
     **/
    PutSphere(int x_center_, int y_center_, int z_center_, int radius_, float r_, float g_, float b_, float a_);
    
    //! Destructor of the PutBox class.
    /*!
     * Acts as the default destructor;
     **/
    ~PutSphere(){};

    //! Member function draw.
    /*!
     * Method that creates, from an instance of the Sculptor class passed as a parameter, a sphere present in its array of voxels.
     *
     *  @param sculptor instância da classe Escultor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_SPHERE_H