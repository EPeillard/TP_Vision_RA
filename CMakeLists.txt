cmake_minimum_required(VERSION 2.8)

project(arucoMinimal)

SET(CMAKE_MODULE_PATH /usr/local/lib/cmake)

find_package(aruco REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

macro( config_project PROJNAME LIBNAME )
       include_directories( ${${LIBNAME}_INCLUDE_DIR} )
       target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

file(
        GLOB_RECURSE
        source_files
        src/*
)

SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(arucoMinimal ${source_files})

target_link_libraries(arucoMinimal 
  jpeg
  ${aruco_LIBS}
  ${OpenCV_LIBS}
  ${OPENGL_LIBRARIES}
  ${GLUT_LIBRARIES}
)


