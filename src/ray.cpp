#include "ray.h"
Ray::Ray() {}
Ray::Ray(Vector4 o, Vector4 d):m_origin(o),m_direction(d) {}
Ray::~Ray() {}
Vector4 Ray::GetOrigin() const { return m_origin; }
Vector4 Ray::GetDirection() const { return m_direction; }
/*void Ray::SetOrigin(Vector4 o) { m_origin = o; }
void Ray::SetDirection(Vector4 d) {
    if (d!=Vector4::Null())
        m_direction = d;
    else
        printf("Nul direction to a ray !\n");
}*/
bool Ray::Intersect(Plane *p) const { return not cmp(p->GetNormal()/m_direction,0.0f); }
Vector4 Ray::Intersection(Plane *p) const {
	float a=p->GetVector()/m_origin;
	float b=p->GetVector()/m_direction;
	return -(m_origin - m_direction*(a/b));
}
