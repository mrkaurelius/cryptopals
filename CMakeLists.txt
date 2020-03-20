cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set ( CMAKE_CXX_FLAGS "-Wall -g")

project(cryptopalls)
# include_directories($ENV{OPENNI_INCLUDE}) # for angled brackets
find_library(libb64-dev REQUIRED)

add_library(cpals_util SHARED
  src/cpalsutil/cpals_util.hpp  
  src/cpalsutil/cpals_util.cpp  
)

add_executable(hex2base64 
  src/hex2base64.cpp
)

add_executable(breakrepeatingxor
  src/breakrepeatingxor.cpp
)

add_executable(fixedxor 
  src/fixedxor.cpp
)

add_executable(detectsinglecharxor
  src/detectsinglecharxor.cpp
)

add_executable(repeatkeyxor
  src/repeatkeyxor.cpp
)

add_executable(singlebytexor
  src/singlebytexor.cpp
)

target_link_libraries(hex2base64 PRIVATE cpals_util)
target_link_libraries(detectsinglecharxor PRIVATE cpals_util)
target_link_libraries(fixedxor PRIVATE cpals_util)
target_link_libraries(repeatkeyxor PRIVATE cpals_util)
target_link_libraries(singlebytexor PRIVATE cpals_util)
target_link_libraries(breakrepeatingxor PRIVATE cpals_util)
