# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_file_io_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED file_io_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(file_io_FOUND FALSE)
  elseif(NOT file_io_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(file_io_FOUND FALSE)
  endif()
  return()
endif()
set(_file_io_CONFIG_INCLUDED TRUE)

# output package information
if(NOT file_io_FIND_QUIETLY)
  message(STATUS "Found file_io: 0.0.0 (${file_io_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'file_io' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${file_io_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(file_io_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${file_io_DIR}/${_extra}")
endforeach()
