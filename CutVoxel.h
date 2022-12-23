#ifndef CUT_VOXEL_H
  #define CUT_VOXEL_H

  #include "GeometricFigure.h"

  //! Concrete class CutVoxel - Used to delete a single voxel
  /*! 
   * \brief It will inform the system that the voxel, present in a certain coordinate and belonging
   *        to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class,
   *        should be **deleted**.
   *
   * @param x Represents the coordinate on the **x** axis of the voxel;
   * @param y Represents the coordinate on the **y** axis of the voxel;
   * @param z Represents the coordinate on the **z** axis of the voxel;
   *
   * It inherits directly from the GeometricFigure abstract class.
   **/
  class CutVoxel:public GeometricFigure{
    int x; /**< Axis voxel coordinate **x**.*/
    int y; /**< Axis voxel coordinate **y**.*/
    int z; /**< Axis voxel coordinate **z**.*/
  public:
    //! CutVoxel class constructor.
    /*!
     *  This constructor will receive as parameters the coordinates of the voxel box to be created and with that,
     *  will construct an instance of the CutVoxel class.
     *
     *  @param x_ Represents the coordinate on the **x** axis of the voxel;
     *  @param y_ Represents the coordinate on the **y** axis of the voxel;
     *  @param z_ Represents the coordinate on the **z** axis of the voxel;   
     **/
    CutVoxel(int x_, int y_, int z_);
    //! Destructor of the CutVoxel class.
    /*!
     * Acts as the default destructor;
     **/
    ~CutVoxel(){};
    //! Member function draw.
    /*!
     *  Method that will delete, from an instance of the Sculptor class passed as a parameter, a voxel in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_VOXEL_H