project(2dpainting)

include_directories(${PROJECT_BINARY_DIR})

qt5_wrap_cpp(moc_srcs
    glwidget.h
    helper.h
    widget.h
    window.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    helper.cpp
    widget.cpp
    window.cpp
    main.cpp
)

add_executable(2dpainting ${srcs})

target_link_libraries(2dpainting
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
