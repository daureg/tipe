#ifndef __GRID_APP
#define __GRID_APP
#include "app.h"
#include "cam.h"
#include "grid.h"

class GridApp : public App {
	public:
		GridApp();
		virtual ~GridApp();
	private:
		void Draw();
		Cam m_cam;
		Grid m_grid;
};
#endif
