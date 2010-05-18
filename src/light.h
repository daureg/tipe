#ifndef __LIGHT
#define __LIGHT

#include "utils.h"
#include "color.h"
#include "vector.h"

enum LTYPE {
	POINT,
	SPOT,
	DIR };

class Light {
	public:
		Light();
		Light(LTYPE, Color, Vector4, Vector4);
		virtual ~Light();

		Color ReceiveFrom(Vector4);
	
	private:
		LTYPE m_type;
		Color m_color;
		Vector4 m_pos;
		Vector4 m_dir;
		float m_concentration;
		float m_att0;
		float m_att1;
		float m_att2;
};
#endif
