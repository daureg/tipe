#ifndef __CAPP
#define __CAPP
#include "app.h"
#include "circle.h"
class Capp : public App {
	public:
		Capp (Conf *);
		virtual ~Capp ();
		void Draw();
};
#endif
