#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2_ttf::SDL2_ttf" for configuration ""
set_property(TARGET SDL2_ttf::SDL2_ttf APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SDL2_ttf::SDL2_ttf PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "SDL2::SDL2"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSDL2_ttf-2.0.so.0.2500.0"
  IMPORTED_SONAME_NOCONFIG "libSDL2_ttf-2.0.so.0"
  )

list(APPEND _cmake_import_check_targets SDL2_ttf::SDL2_ttf )
list(APPEND _cmake_import_check_files_for_SDL2_ttf::SDL2_ttf "${_IMPORT_PREFIX}/lib/libSDL2_ttf-2.0.so.0.2500.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
