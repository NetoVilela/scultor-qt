#ifndef CUT_BOX_H
  #define CUT_BOX_H

  #include "GeometricFigure.h"

  //! Concrete class CutBox - Used to delete a block of voxels
  /*! 
   *  \brief It will inform the system that all voxels present in a given cubic region
   *         and belonging to the space of the three-dimensional array of voxels allocated by an instance of the Sculptor class, must be **deleted**.
   *
   *  @param xi Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   *  @param xf Represents a coordinate on the **x** axis belonging to the voxel matrix that denotes the end of the voxel range;
   *  @param yi Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   *  @param yf Represents a coordinate on the **y** axis belonging to the voxel matrix that denotes the end of the voxel range;
   *  @param zi Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the beginning of the voxel range;
   *  @param zf Represents a coordinate on the **z** axis belonging to the voxel matrix that denotes the end of the voxel range;
   * 
   *  It inherits directly from the abstract class GeometricFigure.
   **/
  class CutBox:public GeometricFigure{
    int xi; /**< Initial coordinate of the box on the axis **x**.*/
    int xf; /**< Final coordinate of the box on the axis **x**.*/
    int yi; /**< Initial coordinate of the box on the axis **y**.*/
    int yf; /**< Final coordinate of the box on the axis **y**.*/
    int zi; /**< Initial coordinate of the box on the axis **z**.*/
    int zf; /**< Final coordinate of the box on the axis **z**.*/
  public:
  
    //! CutBox class constructor.
    /*!
     * This constructor will receive as parameters the dimensional coordinates of the voxel box to be deleted and, with that,
     * will construct an instance of the CutBox class.
     *
     *  @param xi_ Represents a coordinate on the **x** axis belonging to the voxel array that denotes the beginning of the voxel range;
     *  @param xf_ Represents a coordinate on the **x** axis belonging to the voxel array that denotes the end of the voxel range
     *  @param yi_ Represents a coordinate on the **y** axis belonging to the voxel array that denotes the beginning of the voxel range;
     *  @param yf_ Represents a coordinate on the **y** axis belonging to the voxel array that denotes the end of the voxel range
     *  @param zi_ Represents a coordinate on the **z** axis belonging to the voxel array that denotes the beginning of the voxel range;
     *  @param zf_ Represents a coordinate on the **z** axis belonging to the voxel array that denotes the end of the voxel range
     **/
    CutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_);

    //! CutBox class destructor.
    /*!
     * Acts as default destructor;
     **/
    ~CutBox(){};

    //! Member function draw.
    /*!
     * Method that will delete, from an instance of the Sculptor class passed as a parameter, a box present in its array of voxels.
     *
     *  @param sculptor instance of the Sculptor class;;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_BOX_H
