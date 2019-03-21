set(RADIX_WINDOW_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/Window")

set(RADIX_WINDOW_EXPORT_CMAKE_PACKAGE_VARS ON)
add_subdirectory("${RADIX_WINDOW_ROOT_DIR}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RadixWindow
  FOUND_VAR RadixWindow_FOUND
  REQUIRED_VARS RADIX_WINDOW_LIBRARIES RADIX_WINDOW_INCLUDE_DIR RADIX_WINDOW_INCLUDE_DIRS)

mark_as_advanced(RADIX_WINDOW_LIBRARY RADIX_WINDOW_LIBRARIES RADIX_WINDOW_INCLUDE_DIR RADIX_WINDOW_INCLUDE_DIRS
  RADIX_WINDOW_DEFINITIONS)
