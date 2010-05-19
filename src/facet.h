#ifndef __FACET
#define __FACET

#include "material.h"
#include "triangle.h"
#include "camera.h"
#include "light.h"

class Facet: public Object {
	public:
		Facet();
		Facet(Vector4, Vector4, Vector4, Vector4, Material, Material, 
				Material, Triangle, Camera*, std::vector<Light*>);
		virtual ~Facet();

		void Draw(SDL_Surface*);
		void Anim(Uint16, Input*);

		void SetCam(Camera*);
		void SetLights(std::vector<Light*>);
	
	private:

		void MakeNormal();

		Vector4 m_p1;
		Vector4 m_p1;
		Vector4 m_p1;
		Vector4 m_normal;
		Material m_c1;
		Material m_c1;
		Material m_c1;
		Triangle m_triangle;
		Camera *m_cam;
		std::vector<Light*> m_lights_list;
};
#endif
