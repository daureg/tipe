#include "material.h"
Material::Material() :m_diffuse(White), m_specular(White),
	m_sharpness(1.0f) {}
Material::Material(Color diff, Color spec=White, float sharp=1.0f) :
	m_diffuse(diff), m_specular(spec), m_sharpness(sharp) {}
Material::~Material() {}

Color Material::GetDiffuse() const { return m_diffuse; }
Color Material::GetSpecular() const { return m_specular; }
float Material::GetSharpness() const { return m_sharpness; }

void Material::Print() {
	printf("Diffuse : ");
	m_diffuse.Print();
	printf("Specular : ");
	m_specular.Print();
	printf("Sharpness : %.2f\n",m_sharpness);
}
