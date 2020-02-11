cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set ( CMAKE_CXX_FLAGS "-Wall -g")

project(cryptopalls)

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
