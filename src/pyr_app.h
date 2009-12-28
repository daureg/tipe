#ifndef __PYR_APP
#define __PYR_APP
#include "app.h"
#include "learning_cam.h"
#include "pyramid.h"

class PyrApp : public App {
	public:
		PyrApp();
		virtual ~PyrApp();
	private:
		void Draw();
		LearningCam m_cam;
		Pyramid m_pyr;
};
#endif
