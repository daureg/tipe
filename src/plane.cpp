#include "plane.h"
Plane::Plane():m_normal(Vector4(0.0f,0.0f,1.0f,0.0f)),m_distance(0.0f) {}
Plane::Plane(Vector4 l):m_normal(Vector4(l(1),l(2),l(3),0.0f)),m_distance(l(4)) {}
Plane::Plane(Vector4 n, Vector4 p):m_normal(Vector4(n(1),n(2),n(3),0.0f)),m_distance(-(n/p)) {}
Plane::Plane(Vector4 p1,Vector4 p2,Vector4 p3):m_normal((p2-p1)*(p3-p1)) {
	m_distance = -(m_normal/p1);
}
Plane::~Plane() {}
Vector4 Plane::GetVector() const {
	return Vector4(m_normal(1),m_normal(2),m_normal(3),m_distance);
}
Vector4 Plane::GetNormal() const {
	return Vector4(m_normal(1),m_normal(2),m_normal(3),0.0f);
}
SPACE_POSITION Plane::WhereIs(Vector4 p) const {
	float d = m_normal/p + m_distance;
	if (d > EPSILON)
		return IN_FRONT_OF;
	if (d < EPSILON)
		return BEHIND_OF;
	else
		return BELONGS_TO;
}	
