#include "rpng.h"
Rpng::Rpng() {
	m_img.filename = "";
	m_valid = false;
	m_error = "pas de fichier a lire";
}
Rpng::Rpng(std::string in) {
	m_img.filename = in;
	m_valid = true;
	m_error = "";
	m_img.data = NULL;
}
Rpng::~Rpng() { 
	if (m_img.data != NULL) 
		delete [] m_img.data;
}
void Rpng::SetFile(std::string in) { m_img.filename = in; }
const Uint8* Rpng::Read() {
	/* check signature */
	Uint8 sig[8];
	m_img.file = fopen(m_img.filename.c_str(),"rb");
	if (!m_img.file) {
		m_error += "[can't open image file] ";
		m_valid = false;
		return NULL;
	}

	fread(sig, 1, 8, m_img.file);
	if (!png_check_sig(sig, 8)) {
		m_error += "[bad signature] ";
		m_valid = false;
		return NULL;
	}

	/* could pass pointers to user-defined error handlers instead of NULLs: */
	m_img.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	m_img.info_ptr = png_create_info_struct(m_img.png_ptr);

	/* setjmp() must be called in every function that calls a PNG-reading libpng function */
	if (setjmp(png_jmpbuf(m_img.png_ptr))) {
		png_destroy_read_struct(&m_img.png_ptr, &m_img.info_ptr, NULL);
		m_error += "[setjmp problem] ";
		m_valid = false;
		return NULL;
	}

	png_init_io(m_img.png_ptr, m_img.file);
	png_set_sig_bytes(m_img.png_ptr, 8);  /* we already read the 8 signature bytes */
	png_read_info(m_img.png_ptr, m_img.info_ptr);  /* read all PNG info up to image data */
	png_get_IHDR(m_img.png_ptr, m_img.info_ptr, &(m_img.width), &(m_img.height),
		       	&(m_img.bit_depth), &(m_img.color_type), NULL, NULL, NULL);


	if (m_img.bit_depth != 8 ||m_img.color_type != PNG_COLOR_TYPE_GRAY) {
		m_error += "[not a 8bpp gray image] ";
		m_valid = false;
		return NULL;
	}

	png_uint_32 i;
	png_bytepp row_pointers = NULL;

	m_img.rowbytes = png_get_rowbytes(m_img.png_ptr, m_img.info_ptr);

	if ((m_img.data = new Uint8[m_img.rowbytes*(m_img.height)]) == NULL) {
		png_destroy_read_struct(&m_img.png_ptr, &m_img.info_ptr, NULL);
		return NULL;
	}
	if ((row_pointers = new png_bytep[m_img.height*sizeof(png_bytep)]) == NULL) {
		png_destroy_read_struct(&m_img.png_ptr, &m_img.info_ptr, NULL);
		delete [] m_img.data;
		m_img.data = NULL;
		return NULL;
	}

	/* set the individual row_pointers to point at the correct offsets */
	for (i = 0;  i < m_img.height;  ++i)
		row_pointers[i] = m_img.data + i*m_img.rowbytes;

	/* now we can go ahead and just read the whole image */
	png_read_image(m_img.png_ptr, row_pointers);
	/* Clean up */
	if (m_img.png_ptr && m_img.info_ptr) {
		png_destroy_read_struct(&m_img.png_ptr, &m_img.info_ptr, NULL);
		m_img.png_ptr = NULL;
		m_img.info_ptr = NULL;
	}
	fclose(m_img.file);
	delete [] row_pointers;
	row_pointers = NULL;
	return m_img.data;
}
const std::string Rpng::ErrorMsg() const {return m_error;}
