qt_add_executable(app
        mainwindow.ui
        mainwindow.hpp
        mainwindow.cpp
        main.cpp
)

target_link_libraries(app PRIVATE Qt6::Widgets)

set_target_properties(app PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
