cmake_minimum_required(VERSION 3.0)
project(ocrad)
project(libocrad)
project(ocradcheck)
project(ocrad-java)

# Java
include_directories($ENV{JAVA_HOME}/include)
if(WIN32)
  include_directories($ENV{JAVA_HOME}/include/win32)
elseif(APPLE)
  include_directories($ENV{JAVA_HOME}/include/darwin)
else()
  include_directories($ENV{JAVA_HOME}/include/linux)
endif()

set(CMAKE_CXX_STANDARD 11)

add_library(SRC_ALL
  ./arg_parser.cc
  ./bitmap.cc
  ./blob.cc
  ./character.cc
  ./character_r11.cc
  ./character_r12.cc
  ./character_r13.cc
  ./common.cc
  ./feats.cc
  ./feats_test0.cc
  ./feats_test1.cc
  ./iso_8859.cc
  ./mask.cc
  ./page_image.cc
  ./page_image_io.cc
  ./profile.cc
  ./rational.cc
  ./rectangle.cc
  ./segment.cc
  ./textblock.cc
  ./textline.cc
  ./textline_r2.cc
  ./textpage.cc
  ./track.cc
  ./ucs.cc
  ./user_filter.cc
)
set_property(TARGET SRC_ALL PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(libocrad SHARED ./ocradlib.cc)
set_target_properties(libocrad PROPERTIES OUTPUT_NAME "ocrad")
target_link_libraries(libocrad SRC_ALL)

add_executable(ocrad ./main.cc)
target_link_libraries(ocrad SRC_ALL)

add_executable(ocradcheck ./ocradcheck.cc ./ocradlib.cc)
target_link_libraries(ocradcheck SRC_ALL)

add_library(ocrad-java SHARED ./java/com_ian678_ocrad_Ocrad.cc ./ocradlib.cc)
target_link_libraries(ocrad-java SRC_ALL)

if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()
