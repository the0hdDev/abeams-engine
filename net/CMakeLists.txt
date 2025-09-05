
add_library(abeams_net SHARED
        websockets/wsServer.cpp
        websockets/wsServer.h
        websockets/wsHandler.cpp
        websockets/wsHandler.h
)

target_include_directories(abeams_net
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(abeams_net
        PUBLIC
        abeams_util
        fmt::fmt
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(abeams_net
            PRIVATE
            ws2_32
            wsock32
    )
endif()