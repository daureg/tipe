#ifndef __FACET
#define __FACET

#include "material.h"
#include "triangle.h"
#include "cam.h"
#include "light.h"
#include <vector>

class Facet: public Object {
	public:
		Facet();
		Facet(Vector4, Vector4, Vector4, Vector4, Material, Material, 
				Material, Cam*, std::vector<Light*>);
		virtual ~Facet();

		void Draw(SDL_Surface*);
		void Anim(Uint16, Input*);

		void SetCam(Cam*);
		void SetLights(std::vector<Light*>);
	
	private:

		void MakeNormal();

		Vector4 m_p1;
		Vector4 m_p2;
		Vector4 m_p3;
		Vector4 m_normal;
		Material m_c1;
		Material m_c2;
		Material m_c3;
		Triangle m_triangle;
		Cam *m_cam;
		std::vector<Light*> m_lights_list;
};
#endif
