project(pbuffers)

qt5_add_resources(RCC_GENERATED pbuffers.qrc)

qt5_wrap_cpp(moc_srcs
    glwidget.h
    cube.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    cube.cpp
    main.cpp
)

add_executable(pbuffers ${srcs} ${RCC_GENERATED})

target_link_libraries(pbuffers
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Svg_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
