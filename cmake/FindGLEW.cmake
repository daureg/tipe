#
# Taken from http://nvidia-texture-tools.googlecode.com/svn/trunk/cmake/FindGLEW.cmake
#
# Try to find GLEW library and include path.
# Once done this will define
#
# GLEW_FOUND
# GLEW_INCLUDE_PATH
# GLEW_LIBRARY
# 
FIND_PATH( GLEW_INCLUDE_PATH GL/glew.h
	/usr/include
	/usr/local/include
	/sw/include
	/opt/local/include
	${GLEW_ROOT_DIR}/include
	DOC "The directory where GL/glew.h resides")

FIND_LIBRARY( GLEW_LIBRARY
	NAMES GLEW glew
	PATHS
	/usr/lib
	/usr/local/lib
	/sw/lib
	/opt/local/lib
	${GLEW_ROOT_DIR}/lib
	DOC "The GLEW library")

SET(GLEW_FOUND "NO")
IF (GLEW_INCLUDE_PATH AND GLEW_LIBRARY)
	SET(GLEW_LIBRARIES ${GLEW_LIBRARY})
	SET(GLEW_FOUND "YES")
ENDIF (GLEW_INCLUDE_PATH AND GLEW_LIBRARY)

