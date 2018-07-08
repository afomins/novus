


#include	"main\main.h"
#include	"camera\camera.h"

#include	<math.h>

void	camera_process()
{
	if(camera.camera_mode	==	CAMERA_MODE_FREELOOK)
	{
		camera_freelook_process();
	}
	else
	if(camera.camera_mode	==	CAMERA_MODE_ROTATE)
	{
		camera_rotate_process();
	}
	else
	if(camera.camera_mode	==	CAMERA_MODE_SCRIPT_ROTATE)
	{
		camera_script_rotate_process();
	}
	else
	if(camera.camera_mode == CAMERA_MODE_SCRIPT)
	{
		camera_script_process();
	}
}