#ifndef __GAPP
#define __GAPP
#include "app.h"
#include "cam.h"

const Uint16 N_VERTS = 8;
const Uint16 V_SIZE = 3;
const Uint16 C_SIZE = 3;
const Uint16 NUM_VERTICES = 36;
const Uint16 FPS = 60;

class Gapp : public App {
	public:
		Gapp (Conf *);
		virtual ~Gapp ();
		int Run();
	private:
		void Draw();
		Cam m_cam;
		Input m_ui;
		float *m_vert;
		unsigned char *m_col;
		unsigned char *m_idx;

};
#endif
