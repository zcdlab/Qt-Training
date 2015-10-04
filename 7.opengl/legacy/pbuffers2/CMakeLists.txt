project(pbuffers2)

qt5_add_resources(RCC_GENERATED pbuffers2.qrc)

qt5_wrap_cpp(moc_srcs
    glwidget.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    main.cpp
)

add_executable(pbuffers2 ${srcs} ${RCC_GENERATED})

target_link_libraries(pbuffers2
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Svg_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
