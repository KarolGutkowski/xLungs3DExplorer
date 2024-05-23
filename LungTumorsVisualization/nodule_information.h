#ifndef NODULE_INFORMATION_H
#define NODULE_INFORMATION_H

#include <stdint.h>

struct nodule_information {
  uint8_t cluster_id;
  float params[14];
};

#endif // !NODULE_INFORMATION_H

// float shape_elongation;				// 0
// float shape_flatness;				// 1
// float shape_LeastAxisLength;			// 2
// float shape_MajorAxisLength;			// 3
// float shape_Maximum2DDiameterColumn;	// 4
// float shape_Maximum2DDiameterRow;	// 5
// float shape_Maximum2DDiameterSlice;	// 6
// float shape_Maximum3DDiameter;		// 7
// float shape_MeshVolume;				// 8
// float shape_MinorAxisLength;			// 9
// float shape_sphericity;				// 10
// float shape_SurfaceArea;				// 11
// float shape_SurfaceVolumeRatio;		// 12
// float shape_VoxelVolume;				// 13