
add_library(a_cli SHARED
        cli.cpp
        cli.h
        cli_Implementations.h
        simulationCLIHander/simulationCLIHandler.h
)

target_include_directories(a_cli
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(a_cli
        PUBLIC
        a_util
        fmt::fmt
        ftxui::dom
        ftxui::component
        ftxui::screen
        nlohmann_json::nlohmann_json
)

