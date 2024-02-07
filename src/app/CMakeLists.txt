qt_add_executable(app
        mainwindow.ui
        mainwindow.hpp
        mainwindow.cpp
        main.cpp
        Canvas.hpp
        Canvas.cpp
        models/PointModel.hpp
        models/PointModel.cpp
        views/PointListView.hpp
        views/PointListView.cpp
)

target_link_libraries(
        app
        PRIVATE
        Qt6::Widgets
        curve_lib
)

target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(app PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
