#ifndef __TRIANGLE_APP
#define __TRIANGLE_APP
#include "app.h"
#include "triangle.h"
const Uint16 NBTR=2;
class TriangleApp : public App {
	public:
		TriangleApp();
		virtual ~TriangleApp();
		void Draw();
	private:
		Triangle m_trs[NBTR];
		Uint16 *m_l1;
		Uint16 *m_l2;
		Uint16 *m_l3;
};
#endif
