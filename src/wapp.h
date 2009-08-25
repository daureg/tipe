#ifndef __WAPP
#define __WAPP
#include "wpng.h"
class Wapp {
	public:
		Wapp();
		virtual ~Wapp();
		bool Run();
	private:
		Wpng m_png;
		Uint8 *m_t;
};
#endif
