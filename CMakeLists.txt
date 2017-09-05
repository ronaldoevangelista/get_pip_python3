cmake_minimum_required(VERSION 2.8.3)

project (future)

SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -lpthread  -Wall -mtune=native")

find_package(PythonLibs REQUIRED)

message("Include dirs of Python: " ${PYTHON_INCLUDE_DIRS} )
message("Libs of Python: " ${PYTHON_LIBRARIES} )

find_package (Boost REQUIRED COMPONENTS filesystem system date_time python  )


SET(Boost_USE_MULTITHREADED ON)

include_directories(${PYTHON_INCLUDE_DIRS} )
include_directories(${Boost_INCLUDE_DIRS} )
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}")

#add_executable(app enum.cpp)
#target_link_libraries(app ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

ADD_LIBRARY(yay SHARED enum.cpp)
target_link_libraries(yay ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
