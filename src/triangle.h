#ifndef __TRIANGLE
#define __TRIANGLE
#include "const.h"
#include "color.h"
class Triangle {
	public:
		Triangle();
		Triangle(Uint16*,Uint16*,Uint16*,Uint16*);
		virtual ~Triangle();

		void SetPoint(Uint16*,Uint16*,Uint16*,Uint16*);
		void SetColors(Color*,Color*,Color*);
		void Draw() const;
		void DrawGL() const;
		void Print() const;

	private:
		float Distance(Sint16,Sint16,Sint16,Sint16) const;
		void DrawSegment(Uint16,Uint16,Uint16) const;
		void Swap(Uint8,Uint8);
		void Sort();
		void Line(Uint16,Uint16,Uint16,Uint16,Uint16*) const;

		Uint16 m_vertex[6];
		Uint16 *m_l1;
		Uint16 *m_l2;
		Uint16 *m_l3;
		Color m_colors[3];
		bool m_default;
		float m_d1;
};
#endif
