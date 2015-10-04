project(qopenglwidget)

qt5_add_resources(RCC_GENERATED texture.qrc)

qt5_wrap_cpp(moc_srcs
    mainwindow.h
    glwidget.h
    bubble.h
)

set(srcs
    ${moc_srcs}
    bubble.cpp
    glwidget.cpp
    mainwindow.cpp
    main.cpp
)

add_executable(qopenglwidget ${srcs} ${RCC_GENERATED})

target_link_libraries(qopenglwidget
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
