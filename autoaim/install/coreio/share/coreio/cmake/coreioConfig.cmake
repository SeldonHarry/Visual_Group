# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_coreio_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED coreio_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(coreio_FOUND FALSE)
  elseif(NOT coreio_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(coreio_FOUND FALSE)
  endif()
  return()
endif()
set(_coreio_CONFIG_INCLUDED TRUE)

# output package information
if(NOT coreio_FIND_QUIETLY)
  message(STATUS "Found coreio: 0.0.0 (${coreio_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'coreio' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${coreio_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(coreio_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${coreio_DIR}/${_extra}")
endforeach()
