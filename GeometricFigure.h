#ifndef GEOMETRIC_FIGURE_H
  #define GEOMETRIC_FIGURE_H

  #include "Sculptor.h"
  
  //! Abstract class GeometricFigure - Base for generating geometries
  /*! 
   * \brief Base class for the geometric application of all elements that can be built or deleted
    * from the voxel array of an instance of the Sculptor class.
   *
   *  @param r Represents the red component of the color that the voxel(s) will be painted;
   *  @param g Represents the green component of the color that the voxel(s) will be painted;
   *  @param b Represents the blue component of the color that the voxel(s) will be painted;
   *  @param a Represents the transparency component of the color that the voxel(s) will be painted;
   **/
  class GeometricFigure{
    protected:
      float r; /**< Red component RGBA color format in a floating point range from 0 to 1.*/
      float g; /**< Green component RGBA color format in a floating point range from 0 to 1.*/
      float b; /**< Blue component RGBA color format in a floating point range from 0 to 1.*/
      float a; /**< Transparency component in RGBA color format in a floating point range from 0 to 1.*/
    public:
      //! GeometricFigure class constructor.
      virtual ~GeometricFigure(){};

    //! Pure virtual Draw function.
    /*!
     * Base method for implementing the application logic of each geometry that inherits from this class
     * on top of a digital sculptor instance of the Sculptor class.
     * 
     * @param sculptor instance of the Sculptor class;
     **/
      virtual void draw(Sculptor &sculptor)=0; // NOOP
  };

#endif // GEOMETRIC_FIGURE_H
