#include "wpng.h"
Wpng::Wpng() {
	m_img.filename = "";
	m_error = "pas de fichier a ecrire";
}
Wpng::Wpng(std::string in, Uint16 size) {
	m_img.filename = in;
	m_img.width = size;
	m_img.height = size;
	m_img.bit_depth	= 8;
	m_img.color_type = PNG_COLOR_TYPE_GRAY;
	m_error = "";
}
Wpng::~Wpng() { if (!m_img.data) delete [] m_img.data; }

const std::string Wpng::ErrorMsg() const {return m_error;}
bool Wpng::Write(Uint8 *t) {
	m_img.data = t;
	m_img.png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	m_img.info_ptr = png_create_info_struct(m_img.png_ptr);

	// setjmp() must be called in every function that calls a PNG-writing libpng function
	if (setjmp(png_jmpbuf(m_img.png_ptr))) {
		png_destroy_write_struct(&m_img.png_ptr, &m_img.info_ptr);
		m_error += "[setjmp problem] ";
		return false;
	}

	m_img.file = fopen(m_img.filename.c_str(),"wb");
	if (!m_img.file) {
		m_error += "[can't open image file] ";
		return false;
	}

	/* make sure outfile is (re)opened in BINARY mode */
	png_init_io(m_img.png_ptr, m_img.file);
	png_set_compression_level(m_img.png_ptr, 6);
	png_set_IHDR(m_img.png_ptr, m_img.info_ptr, m_img.width, m_img.height,
			m_img.bit_depth, m_img.color_type, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	/* write all chunks up to (but not including) first IDAT */
	png_write_info(m_img.png_ptr, m_img.info_ptr);
	/* set up the transformations:  for now, just pack low-bit-depth pixels
	 * into bytes (one, two or four pixels per byte) */
	png_set_packing(m_img.png_ptr);

	/* TODO essayer de mettre new ici */
	png_byte *row_pointers[PICTURE_SIZE];
	for (int i=0; i<PICTURE_SIZE; i++)
		row_pointers[i]=m_img.data + i*m_img.width;
	png_write_image(m_img.png_ptr, row_pointers);
	png_write_end(m_img.png_ptr, NULL);
	png_destroy_write_struct(&m_img.png_ptr, &m_img.info_ptr);
	fclose(m_img.file);
	return true;
}

