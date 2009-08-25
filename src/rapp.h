#ifndef __RAPP
#define __RAPP
#include "rpng.h"
class Rapp {
	public:
		Rapp();
		virtual ~Rapp();
		int Run();
	private:
		Rpng m_png;
};
#endif
