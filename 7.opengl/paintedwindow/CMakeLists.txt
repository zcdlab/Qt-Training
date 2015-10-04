project(paintedwindow)

include_directories(${PROJECT_BINARY_DIR})

qt5_wrap_cpp(moc_srcs
    paintedwindow.h
)

set(srcs
    ${moc_srcs}
    paintedwindow.cpp
    main.cpp
)

add_executable(paintedwindow ${srcs})

target_link_libraries(paintedwindow
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
