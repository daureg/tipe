#ifndef __PNGAPP
#define __PNGAPP
#include "wpng.h"
#include "rpng.h"
class PNGapp {
	public:
		PNGapp();
		virtual ~PNGapp();
		int Run();
	private:
		Rpng m_rpng;
		Wpng m_wpng;
		Uint8 *m_written;
};
#endif
