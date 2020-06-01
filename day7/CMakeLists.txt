cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Release)

# set the project name
project(Day6)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(
  app
  src/main.cpp
)

TARGET_LINK_LIBRARIES( app LINK_PUBLIC ${Boost_LIBRARIES} )
