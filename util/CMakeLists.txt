add_library(abeams_util STATIC
        parseConfig.cpp
        parseConfig.h
        logsys/logsys.cpp
        logsys/logsys.h
        logsys/logToFile.cpp
        logsys/logToFile.h
)

target_include_directories(abeams_util
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(abeams_util
        PUBLIC
        fmt::fmt
        nlohmann_json::nlohmann_json
        PRIVATE
        spdlog::spdlog
)
