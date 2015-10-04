project(opengl)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_subdirectory(1_Example)
add_subdirectory(2dpainting)

add_subdirectory(contextinfo)
add_subdirectory(cube)

add_subdirectory(hellogl2)

add_subdirectory(hellowindow)
add_subdirectory(legacy)
add_subdirectory(paintedwindow)

add_subdirectory(qopenglwidget)
add_subdirectory(qopenglwindow)

add_subdirectory(textures)
add_subdirectory(threadedqopenglwidget)
