project(QtTraining)

cmake_minimum_required(VERSION 2.8.11)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Gui_DEFINITIONS})
add_definitions(${Qt5Network_DEFINITIONS})
add_definitions(${Qt5OpenGL_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x ${Qt5Core_EXECUTABLE_COMPILE_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS} ${Qt5Network_EXECUTABLE_COMPILE_FLAGS} ${Qt5OpenGL_EXECUTABLE_COMPILE_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}" CACHE STRING "Flags used by the compiler during all build types.")


include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5GUI_INCLUDE_DIRS}
    ${Qt5Network_INCLUDE_DIRS}
    ${Qt5OpenGL_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

#add_subdirectory("1.Some Example")
#add_subdirectory("1.String")
#add_subdirectory("2.Lottery")
#add_subdirectory("3.CLassEvent")
#add_subdirectory("4.STL")
#add_subdirectory("5.USBCamera")
#add_subdirectory("6.camera")
add_subdirectory("7.opengl")
#add_subdirectory("8.CoolYing")
#add_subdirectory("9.QMyLearn")
