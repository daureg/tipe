#ifndef __RAY
#define __RAY
#include "plane.h"
class Ray {
	public:
		Ray();
		Ray(Vector4, Vector4);
		~Ray();

		Vector4 GetOrigin() const;
		Vector4 GetDirection() const;
		/*void SetOrigin(Vector4);
		void SetDirection(Vector4);*/

		bool Intersect(Plane*) const;
		Vector4 Intersection(Plane*) const;
	private:
		Vector4 m_origin;
		Vector4 m_direction;
};
#endif 
