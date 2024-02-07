qt_add_executable(app
        mainwindow.ui
        mainwindow.hpp
        mainwindow.cpp
        main.cpp
        Canvas.hpp
        Canvas.cpp
)

target_link_libraries(app PRIVATE Qt6::Widgets)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(app PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
