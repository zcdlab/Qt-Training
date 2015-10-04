project(qopenglwindow)

qt5_add_resources(RCC_GENERATED shaders.qrc)

qt5_wrap_cpp(moc_srcs
    background_renderer.h
    openglwindow.h
)

set(srcs
    ${moc_srcs}
    background_renderer.cpp
    openglwindow.cpp
    main.cpp
)

add_executable(qopenglwindow ${srcs} ${RCC_GENERATED})

target_link_libraries(qopenglwindow
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
