#ifndef __PROJ_APP
#define __PROJ_APP
#include "app.h"
#include "learning_cam.h"
class ProjApp : public App {
	public:
		ProjApp();
		virtual ~ProjApp();
		void Draw();

	private:
		LearningCam m_cam;
		Vector4 m_pos;
};
#endif
