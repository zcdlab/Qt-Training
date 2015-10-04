project(cube)

include_directories(${PROJECT_BINARY_DIR})

qt5_add_resources(RCC_GENERATED shaders.qrc textures.qrc)

qt5_wrap_cpp(moc_srcs
    mainwidget.h
    geometryengine.h
)

set(srcs
    ${moc_srcs}
    mainwidget.cpp
    geometryengine.cpp
    main.cpp
)

add_executable(cube ${srcs} ${RCC_GENERATED})

target_link_libraries(cube
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
