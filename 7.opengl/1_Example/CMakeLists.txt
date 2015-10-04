project(1_Example)

include_directories(${PROJECT_BINARY_DIR})

qt5_wrap_ui(uis
    mainwindow.ui
)

qt5_wrap_cpp(moc_srcs
    mainwindow.h
)

set(srcs
    ${moc_srcs}
    ${uis}
    mainwindow.cpp
    main.cpp
)

add_executable(1_Example ${srcs})

target_link_libraries(1_Example
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_glut_LIBRARY}
)
