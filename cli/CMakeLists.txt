
add_library(a_cli SHARED
        cli.cpp
        cli.h
)

target_include_directories(a_cli
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(a_cli
        PUBLIC
        a_util
        fmt::fmt
        nlohmann_json::nlohmann_json
)

