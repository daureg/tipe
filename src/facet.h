#ifndef __FACET
#define __FACET

#include "material.h"
#include "triangle.h"
#include "learning_cam.h"
#include "light.h"
#include <vector>

class Facet: public Object {
	public:
		Facet();
		Facet(Vector4, Vector4, Vector4, Vector4, Material, Material, 
				Material, LearningCam*, std::vector<Light*>,
				Uint16*, Uint16*, Uint16*);
		virtual ~Facet();

		void Draw(SDL_Surface*);
		void Anim(Uint16, Input*);

		void SetCam(LearningCam*);
		void SetLights(std::vector<Light*>);
	
	private:

		void MakeNormal();

		Vector4 m_points[3];
		Vector4 m_normal;
		Material m_colors[3];
		Triangle m_triangle;
		LearningCam *m_cam;
		std::vector<Light*> m_lights_list;
		Uint16 *m_lines[3];
};
#endif
