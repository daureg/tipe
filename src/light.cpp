#include "light.h"
Light::Light() : m_type(DIR), m_color(White), m_dir(1.0f), m_concentration(1.0f),
	m_att0(1.0f), m_att1(1.0f), m_att2(1.0f) {}
Light::Light(LTYPE type, Color col, Vector4 pos, Vector4 dir) : m_type(type),
	m_color(col), m_pos(pos), m_dir(dir), m_concentration(1.0f), m_att0(1.0f),
	m_att1(1.0f), m_att2(1.0f) {}
Light::~Light() {}

Vector4 Light::GetDir() const { return m_dir; }
Vector4 Light::GetPos() const { return m_pos; }
LTYPE Light::GetType() const { return m_type; }
Color Light::ReceiveFrom(Vector4 pos) {
	if (m_type==DIR or m_type==AMBIENT)
		return m_color;
	float d2=(m_pos-pos).Norm2();
	float d = m_att0 + std::sqrt(d2)*m_att1 +d2*m_att2;
	switch (m_type) {
		case POINT:
			return m_color*(1/d);
		case SPOT:
			Vector4 l=(m_pos-pos).Normalize();
			return m_color*(1/d)*std::pow(Max(-m_dir/l, 0.0f), m_concentration);
	}
}
