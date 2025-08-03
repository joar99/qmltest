# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appQtie_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appQtie_autogen.dir/ParseCache.txt"
  "appQtie_autogen"
  )
endif()
