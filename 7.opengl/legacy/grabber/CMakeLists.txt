project(grabber)

qt5_wrap_cpp(moc_srcs
    glwidget.h
    mainwindow.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    mainwindow.cpp
    main.cpp
)

add_executable(grabber ${srcs} ${RCC_GENERATED})

target_link_libraries(grabber
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
