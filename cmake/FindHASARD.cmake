# - Try to find the HASARD libraries
# Once done this will define
#
#  HASARD_FOUND - system has hasard
#  HASARD_INCLUDE_DIR - the hasard include directory
#  HASARD_LIBRARY - hasard library

if(HASARD_INCLUDE_DIR AND HASARD_LIBRARY)
    set(HASARD_FIND_QUIETLY TRUE)
endif(HASARD_INCLUDE_DIR AND HASARD_LIBRARY)

find_path(HASARD_MAIN_INCLUDE_DIR hasard.h
          PATHS ${_LibHASARDIncDir} )

# search the glibconfig.h include dir under the same root where the library is found
find_library(HASARD_LIBRARY 
             NAMES hasard 
             PATHS ${_LibHASARDLinkDir} )

get_filename_component(hasardLibDir "${HASARD_LIBRARY}" PATH)

#find_path(HASARD_INTERNAL_INCLUDE_DIR glibconfig.h
#          PATH_SUFFIXES glib-2.0/include
#          PATHS ${_LibHASARDIncDir} "${hasardLibDir}" ${CMAKE_SYSTEM_LIBRARY_PATH})

set(HASARD_INCLUDE_DIR "${HASARD_MAIN_INCLUDE_DIR}")

