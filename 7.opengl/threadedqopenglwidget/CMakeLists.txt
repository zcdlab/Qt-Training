project(threadedqopenglwidget)

qt5_wrap_cpp(moc_srcs
    mainwindow.h
    glwidget.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    mainwindow.cpp
    main.cpp
)

add_executable(threadedqopenglwidget ${srcs})

target_link_libraries(threadedqopenglwidget
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
