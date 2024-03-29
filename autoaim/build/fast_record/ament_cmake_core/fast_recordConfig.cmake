# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_fast_record_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED fast_record_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(fast_record_FOUND FALSE)
  elseif(NOT fast_record_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(fast_record_FOUND FALSE)
  endif()
  return()
endif()
set(_fast_record_CONFIG_INCLUDED TRUE)

# output package information
if(NOT fast_record_FIND_QUIETLY)
  message(STATUS "Found fast_record: 0.0.0 (${fast_record_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'fast_record' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${fast_record_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(fast_record_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${fast_record_DIR}/${_extra}")
endforeach()