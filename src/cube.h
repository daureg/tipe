#ifndef __CUBE
#define __CUBE
#include "circle.h"
#include <vector>
#include "cam.h"
class Cube : public Object {
	public:
		Cube();
		Cube(Vector4, Uint16, Cam*);
		~Cube();
		void Draw(SDL_Surface*);
		void Anim(Uint16,user_input*);
		void Input(user_input*);

		Vector4 GetCenter() const;
		Uint16 GetSize() const;
		void SetCenter(Vector4);
		void SetSize(Uint16);
		void SetCam(Cam*);
	private:
		void Build();
		Vector4 m_center;
		Uint16 m_size;
		std::vector<Vector4> m_coord;
		Circle m_points[8];
		Cam* m_cam;
};
#endif
