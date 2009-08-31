#ifndef __TAPP
#define __TAPP
#include "app.h"
#include "triangle.h"
const Uint16 NBTR=5;
class Tapp : public App {
	public:
		Tapp();
		virtual ~Tapp();
		void Draw();
	private:
		Triangle m_trs[NBTR];
		Uint16 *m_l1;
		Uint16 *m_l2;
		Uint16 *m_l3;
};
#endif
