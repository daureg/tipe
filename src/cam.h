#ifndef __CAM
#define __CAM
#include "matrix.h"
#include <GL/glu.h>
#include "object.h"
class Cam : public Object {
	public:
		Cam();
		Cam(Vector4*);
		virtual ~Cam();

		void Move(Vector4*);
		void Anim(Uint16, Input*);
		void Look();
		void Print() const;
		void Draw(SDL_Surface*);
		enum ROTATION_AXIS {
			RIGHT,
			LOOK,
			UP };
		void Turn(ROTATION_AXIS, float);
	private:
		void RemakeBase();
			
		Vector4 m_pos;
		Vector4 m_up;
		Vector4 m_look;
		Vector4 m_right;
};
#endif
