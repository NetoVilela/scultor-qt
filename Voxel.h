#ifndef VOXEL
#define VOXEL

/*! \brief Struct Voxel (volume element) used to store properties of the elements that will constitute the created sculpture
 *         by the sculptor class. It is defined as a ***struct*** and contains the necessary properties and information for
 *         construction and use of voxels: their color and transparency and whether or not they should be included in the digital model
 *         which represents the sculpture generated in the Sculptor class.
 */
struct Voxel {
  float r; /**< R (Red) color component in RGBA format in a floating point range from 0.0 to 1.0;*/
  float g; /**< Color component G (Green) in RGBA format in a floating point range from 0.0 to 1.0;*/
  float b; /**< Color component B (Blue) in RGBA format in a floating point range from 0.0 to 1.0;*/
  float a; /**< Color component A (Alpha - Transparency) in RGBA format in a floating point range from 0.0 to 1.0;*/
  bool isOn = false; /**< Boolean information that will inform whoever accesses the element whether or not it should be included in the digital model of the sculpture. Default: False.*/
};

#endif // VOXEL
