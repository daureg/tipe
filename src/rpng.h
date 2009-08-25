#include "pngimage.h"
class Rpng {
	public:
		Rpng();
		Rpng(std::string);
		virtual ~Rpng();

		void SetFile(std::string);
		const Uint8* Read();
		const std::string ErrorMsg() const;
	private:
		PngImage m_img;
		bool m_valid;
		std::string m_error;
};
