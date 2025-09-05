

add_library(a_net SHARED
        websockets/wsServer.cpp
        websockets/wsServer.h
        websockets/wsHandler.cpp
        websockets/wsHandler.h
)

target_include_directories(a_net
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(a_net
        PUBLIC
        a_util
        fmt::fmt
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(a_net
            PRIVATE
            ws2_32
            wsock32
    )
endif()