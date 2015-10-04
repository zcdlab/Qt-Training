project(overpainting)

include_directories(../shared)

qt5_wrap_cpp(moc_srcs
    ../shared/qtlogo.h
    glwidget.h
    bubble.h
)

set(srcs
    ${moc_srcs}
    ../shared/qtlogo.cpp
    glwidget.cpp
    bubble.cpp
    main.cpp
)

add_executable(overpainting ${srcs})

target_link_libraries(overpainting
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
