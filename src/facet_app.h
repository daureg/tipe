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
		LearningCam m_cam;
		Light m_ambient;
		Light m_dir;
		std::vector<Light*> m_lights;
		Facet m_facet;
		Uint16 *m_l1;
		Uint16 *m_l2;
		Uint16 *m_l3;
};
#endif

