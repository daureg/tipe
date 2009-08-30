#ifndef __TRIANGLE
#define __TRIANGLE
#include <GL/gl.h>
#include "conf.h"
class Triangle {
	public:
		Triangle();
		Triangle(Uint16*,Uint16*,Uint16*,Uint16*);
		virtual ~Triangle();
		void SetPoint(Uint16*,Uint16*,Uint16*,Uint16*);
		void Draw() const;
		void DrawGL(Uint8) const;

	private:
		void Swap(Uint8,Uint8);
		void Sort();
		void Line(Uint16,Uint16,Uint16,Uint16,Uint16*) const;

		Uint16 m_vertex[6];
		Uint16 *m_l1;
		Uint16 *m_l2;
		Uint16 *m_l3;
		bool m_default;
};
#endif
