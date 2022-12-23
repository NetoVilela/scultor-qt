#ifndef INTERPRETER_H
  #define INTERPRETER_H

  #include <vector>
  #include <string>

  #include "GeometricFigure.h"

  //! Class Interpreter - Interpreter of plain text files with description for generating sculptures
  /*! 
   * \brief Helper class for reading and interpreting files that describe a sculpture
   * in a certain expected model. It captures the contents of a plain text file
   * and generates a sequence of geometric shapes, children of the GeometricFigure class. This sequence that
   * can be used to build a three-dimensional digital model instantiated by
   * Sculptor class.
   *
   * @param dimX Maximum dimension of the sculpture in the direction of the **x** axis;
   * @param dimY Maximum dimension of the sculpture in the direction of the **y** axis;
   * @param dimZ Maximum dimension of the sculpture in the direction of the **z** axis;
   * @param r Red component RGBA color format in a floating point range from 0 to 1;
   * @param g Green component RGBA color format in a floating point range from 0 to 1;
   * @param b Blue component RGBA color format in a floating point range from 0 to 1;
   * @param a Transparency component in RGBA color format in a floating point range from 0 to 1;
   *
   **/
  class Interpreter{
    private:
      int dimX; /**< Maximum dimension of the sculpture in the direction of the **x** axis.*/
      int dimY; /**< Maximum dimension of the sculpture in the direction of the **y** axis.*/
      int dimZ; /**< Maximum dimension of the sculpture in the direction of the **z** axis.*/
      float r; /**< Red component RGBA color format in a floating point range from 0 to 1.*/
      float g; /**< Green component RGBA color format in a floating point range from 0 to 1.*/
      float b; /**< Blue component RGBA color format in a floating point range from 0 to 1.*/
      float a; /**< Transparency component in RGBA color format in a floating point range from 0 to 1.*/
    public:
      //! Interpreter class constructor.
      /*!
      * Acts as default constructor;
      **/
      Interpreter();
      //! getDimX member function.
      /*!
      * Captures and returns the information present in the private dimX variable.
      * 
      * @return Integer present in the dimX variable.
      **/
      int getDimX();
      //! Member function getDimY.
      /*!
      * Captures and returns the information present in the private dimY variable.
      * 
      * @return Integer present in variable dimY.
      **/
      int getDimY();
      //! Member function getDimZ.
      /*!
      * Captures and returns the information present in the private dimZ variable.
      * 
      * @return Integer present in variable dimZ.
      **/
      int getDimZ();

      //! Parse member function.
      /*!
      * Receives the path of a plain text file, then captures its information and interprets it
      * generating a vector of Geometrica Figure that will be returned.
      * 
      * @param file_path Informational string of the path of the file to be parsed.
      * 
      * @return Pointer to a sequence of child class instances of Geometric Figure - std::vector<Geometric Figure *>.
      **/
      std::vector<GeometricFigure *> parse(std::string file_path);
  };

#endif // INTERPRETER_H
