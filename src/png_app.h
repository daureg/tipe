#ifndef __PNG_APP
#define __PNG_APP
#include "wpng.h"
#include "rpng.h"
class PngApp {
	public:
		PngApp();
		virtual ~PngApp();
		int Run();
	private:
		Rpng m_rpng;
		Wpng m_wpng;
		Uint8 *m_written;
};
#endif
