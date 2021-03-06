#ifndef __LEARNING_CAM
#define __LEARNING_CAM
#include "matrix.h"
#include "input.h"
#include "object.h"
#include <cmath>
class LearningCam : public Object {
	public:
		LearningCam();
		LearningCam(Vector4*);
		LearningCam(Vector4*,Vector4*,Vector4*,Uint8,float,float,float);
		virtual ~LearningCam();

		enum ROTATION_AXIS {
			RIGHT,
			LOOK,
			UP
		};
		Vector4 Proj(Vector4*);
		void Move(Vector4*);
		void Turn(ROTATION_AXIS, float);
		void Print();
		void Anim(Uint16, Input*);
		Vector4 GetPos() const;

		void Draw(SDL_Surface*);
		void MakeAlignMatrix();
	private:
		void RemakeBase();
		void MakeProjectionMatrix();

		Vector4 m_pos;
		Vector4 m_up;
		Vector4 m_look;
		Vector4 m_right;
		float m_fov;
		float m_aspect;
		float m_near;
		float m_far;
		Matrix m_proj;
		Matrix m_align;
		Matrix m_full;
};
#endif
