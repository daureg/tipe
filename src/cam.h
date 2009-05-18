#ifndef __CAM
#define __CAM
#include "vector.h"
#include "matrix.h"
#include "input.h"
#include "conf.h"
#include <cmath>
class Cam {
	public:
		Cam();
		Cam(Vector4, float, float, float, float);
//		Cam(Vector4, Vector4, Vector4, Vector4, float);
		~Cam();

		Vector4 GetPos() const;
		float GetRotX() const;
		float GetRotY() const;
		float GetRotZ() const;
		float GetFov() const;

		void SetPos(Vector4);
		void SetRotX(float);
		void SetRotY(float);
		void SetRotZ(float);

		void Anim(Uint16, user_input*);
		void Projection(Vector4, Uint16 &, Uint16 &);
	private:
		Vector4 m_pos;
		float m_rotx;
		float m_roty;
		float m_rotz;
		float m_fov;/*
		Vector4 m_up;
		Vector4 m_right;
		Vector4 m_look;*/

};
#endif
