#ifndef __PLANE
#define __PLANE
#include "vector.h"
enum SPACE_POSITION {
	IN_FRONT_OF,
	BELONGS_TO,
	BEHIND_OF
};
class Plane {
	public:
		Plane();
		Plane(Vector4);
		Plane(Vector4,Vector4);
		Plane(Vector4,Vector4,Vector4);
		virtual ~Plane();

		Vector4 GetNormal() const;
		Vector4 GetVector() const;		
		SPACE_POSITION WhereIs(Vector4 p) const;
	private:
		Vector4 m_normal;
		float m_distance;
};
#endif
