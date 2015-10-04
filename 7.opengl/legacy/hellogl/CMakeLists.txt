project(hellogl)

include_directories(../shared)

qt5_wrap_cpp(moc_srcs
    ../shared/qtlogo.h
    glwidget.h
    window.h
)

set(srcs
    ${moc_srcs}
    ../shared/qtlogo.cpp
    glwidget.cpp
    window.cpp
    main.cpp
)

add_executable(hellogl ${srcs})

target_link_libraries(hellogl
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
