project(textures)

qt5_add_resources(RCC_GENERATED textures.qrc)

qt5_wrap_cpp(moc_srcs
    window.h
    glwidget.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    window.cpp
    main.cpp
)

add_executable(textures ${srcs} ${RCC_GENERATED})

target_link_libraries(textures
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
