#ifndef __COLOR_APP
#define __COLOR_APP
#include "app.h"
#include "color.h"
class ColorApp : public App {
	public:
		ColorApp();
		virtual ~ColorApp();
		void Draw();
	private:
		Color m_rouge;
		Color m_jaune;
		Color m_test;
};
#endif
