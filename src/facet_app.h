#ifndef __FACET_APP
#define __FACET_APP
#include "app.h"
#include "facet.h"

class FacetApp : public App {
	public:
		FacetApp();
		virtual ~FacetApp();
	private:
		void Draw();
		Cam m_cam;
		Light m_ambient;
		std::vector<Light*> m_lights;
		Facet m_facet;
};
#endif

