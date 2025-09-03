
add_library(abeams_cli STATIC
        cli.cpp
        cli.h
)

target_include_directories(abeams_cli
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(abeams_cli
        PUBLIC
        abeams_util
        fmt::fmt
        nlohmann_json::nlohmann_json
)

