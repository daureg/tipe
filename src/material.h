#ifndef __MATERIAL
#define __MATERIAL

#include "color.h"

class Material {
	public:
		Material(Color, Color, float);
		Material();
		virtual ~Material();

		Color GetDiffuse() const;
		Color GetSpecular() const;
		float GetSharpness() const;

		void Print();
	
	private:
		Color m_diffuse;
		Color m_specular;
		float m_sharpness;
};
#endif
