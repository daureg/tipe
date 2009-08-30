#ifndef __CAM
#define __CAM
#include "input.h"
#include "matrix.h"
#include <GL/glu.h>
class Cam {
	public:
		Cam();
		Cam(Vector4*);
		virtual ~Cam();

		void Move(Vector4*);
		void Anim(Uint16, Input*);
		void Look();
	private:
		enum ROTATION_AXIS {
			RIGHT,
			LOOK,
			UP };
		void Turn(ROTATION_AXIS, float);
		void RemakeBase();
			
		Vector4 m_pos;
		Vector4 m_up;
		Vector4 m_look;
		Vector4 m_right;
};
#endif
