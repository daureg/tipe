#ifndef __WPNG
#define __WPNG
#include "pngimage.h"
class Wpng {
	public:
		Wpng();
		Wpng(std::string, Uint16 size=PICTURE_SIZE);
		virtual ~Wpng();

		bool Write(Uint8*);
		const std::string ErrorMsg() const;
	private:
		PngImage m_img;
		std::string m_error;
};
#endif
