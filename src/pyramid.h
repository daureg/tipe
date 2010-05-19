#ifndef __PYRAMID
#define __PYRAMID

#include "object.h"
#include "vector.h"
#include "matrix.h"
#include "learning_cam.h"

class Pyramid : public Object {
	public:
		Pyramid();
		Pyramid(float, Vector4, LearningCam);
		virtual ~Pyramid();

		void Reset();
		void Move(Vector4);
		void Scale(float);
		void Anim(Uint16, Input*);
		void Draw(SDL_Surface*);	
		void TDraw(LearningCam*);	
	
	private:
		void Transform(Matrix*);
		float m_height;
		Vector4 m_pos;
		Uint8 m_idx[12];
		float m_vert[12];
		LearningCam m_cam;
};
#endif
