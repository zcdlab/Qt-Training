project(hellowindow)

include_directories(${PROJECT_BINARY_DIR})

qt5_wrap_cpp(moc_srcs
    hellowindow.h
)

set(srcs
    ${moc_srcs}
    hellowindow.cpp
    main.cpp
)

add_executable(hellowindow ${srcs})

target_link_libraries(hellowindow
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
