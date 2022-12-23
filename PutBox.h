#ifndef PUT_BOX_H
  #define PUT_BOX_H

  #include "GeometricFigure.h"
  
  //! Concrete class PutBox - Used to display a block of voxels
  /*! 
   * \brief It will inform the system that all voxels present in a given cubic region
   *        and belonging to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class, it should be **displayed**.
   *
   * @param xi Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   * @param xf Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the end of the voxel range;
   * @param yi Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   * @param yf Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the end of the voxel range;
   * @param zi Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   * @param zf Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the end of the voxel range;
   *
   * It inherits directly from the abstract class GeometricFigure.
   **/
  class PutBox:public GeometricFigure{
    int xi; /**< Initial coordinate of the box on the **x** axis.*/
    int xf; /**< Final box coordinate on the **x** axis.*/
    int yi; /**< Initial coordinate of the box on the **y** axis.*/
    int yf; /**< Final box coordinate on the **y** axis.*/
    int zi; /**< Initial coordinate of the box on the **z** axis.*/
    int zf; /**< Final box coordinate on the **z** axis.*/
  public:

    //! PutBox class constructor.
    /*!
     * This constructor will receive as parameters the dimensional coordinates of the voxel box to be created, as well as its color and transparency. Therefore,
     * will construct an instance of the PutBox class.
     *
     *  @param xi_ Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
     *  @param xf_ Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the end of the voxel range;
     *  @param yi_ Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
     *  @param yf_ Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the end of the voxel range;
     *  @param zi_ Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
     *  @param zf_ Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the end of the voxel range;
     *  @param r_ Represents the red component of the color that the box will be painted;
     *  @param g_ Represents the green component of the color that the box will be painted
     *  @param b_ Represents the blue component of the color that the box will be painted
     *  @param a_ Represents the transparency component of the color that the box will be painted;
     **/
    PutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_, float r_, float g_, float b_, float a_);

    //! Destructor of the PutBox class.
    /*!
     * Acts as the default destructor;
     **/
    ~PutBox(){};

    //! Member function draw.
    /*!
     *  Method that will create, from an instance of the Sculptor class passed as a parameter, a box present in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_BOX_H