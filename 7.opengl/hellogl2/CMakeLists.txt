project(hellogl2)

include_directories(${PROJECT_BINARY_DIR})

qt5_wrap_cpp(moc_srcs
    glwidget.h
    logo.h
    mainwindow.h
    window.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    logo.cpp
    mainwindow.h
    window.cpp
    main.cpp
)

add_executable(hellogl2 ${srcs})

target_link_libraries(hellogl2
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
