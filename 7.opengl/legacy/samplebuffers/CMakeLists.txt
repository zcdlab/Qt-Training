project(samplebuffers)

qt5_wrap_cpp(moc_srcs
    glwidget.h
)

set(srcs
    ${moc_srcs}
    glwidget.cpp
    main.cpp
)

add_executable(samplebuffers ${srcs})

target_link_libraries(samplebuffers
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
