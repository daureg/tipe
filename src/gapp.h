#ifndef __GAPP
#define __GAPP
#include "app.h"
#include "cam.h"
#include "glcam.h"
class Gapp : public App {
	public:
		Gapp (Conf *);
		virtual ~Gapp ();
		int Run();
		bool GetInput(SDL_Event*);
	private:
		void Draw();
		GLCam m_cam;
		Vector4 _r;
		Vector4 _p;
		Vector4 _l;
};
const Uint16 FPS = 60;

#endif
