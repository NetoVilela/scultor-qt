#ifndef PUT_VOXEL_H
  #define PUT_VOXEL_H

  #include "GeometricFigure.h"

  //! Concrete class PutVoxel - Used to display a single voxel
  /*! 
   * \brief It will inform the system that the voxel, present in a certain coordinate and belonging
   *        to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class,
   *        should be **displayed**.
   *
   * @param x Represents the coordinate on the **x** axis of the voxel;
   * @param y Represents the coordinate on the **y** axis of the voxel;
   * @param z Represents the coordinate on the **z** axis of the voxel;
   *
   * It inherits directly from the GeometricFigure abstract class.
   **/
  class PutVoxel:public GeometricFigure{
    int x; /**< **x** axis voxel coordinate.*/
    int y; /**< **y** axis voxel coordinate.*/
    int z; /**< **z** axis voxel coordinate.*/
  public:
    //! PutVoxel class constructor.
    /*!
     * This constructor will receive as parameters the coordinates of the voxel box to be created, as well as its color and transparency. Therefore,
     * will construct an instance of the PutVoxel class.
     *
     *  @param x_ Represents the coordinate on the **x** axis of the voxel;
     *  @param y_ Represents the coordinate on the **y** axis of the voxel;
     *  @param z_ Represents the coordinate on the **z** axis of the voxel;   
     *  @param r_ Represents the red component of the color that the voxel will be painted;
     *  @param g_ Represents the green component of the color that the voxel will be painted;
     *  @param b_ Represents the blue component of the color that the voxel will be painted;
     *  @param a_ Represents the transparency component of the color that the voxel will be painted on;
     **/
    PutVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_);
    //! Destructor of the PutVoxel class.
    /*!
     * Acts as the default destructor;
     **/
    ~PutVoxel(){};
    //! Member function draw.
    /*!
     * Method that will create, from an instance of the Sculptor class passed as a parameter, a voxel in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_VOXEL_H