#ifndef LookAtCameraFactory_H
#define LookAtCameraFactory_H

#include "camera/camera.h"

class LookAtCameraFactory
{
public:
	static Camera createCamera(glm::vec3 camera_postion, glm::vec3 look_at)
	{
        auto camera_front = glm::normalize(look_at - camera_postion);
        auto camera = Camera(camera_postion);
        camera.Front = camera_front;
        camera.updateFromFrontVector();
        return camera;
	}
};
#endif // !LookAtCameraFactory