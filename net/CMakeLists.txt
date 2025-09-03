add_library(abeams_net SHARED
        websockets/wsServer.cpp
        websockets/wsServer.h
        websockets/wsHandler.cpp
        websockets/wsHandler.h
)

target_include_directories(abeams_net
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../header
)

target_link_libraries(abeams_net
        PRIVATE
        fmt::fmt
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(abeams_net PRIVATE ws2_32 mswsock)
endif()

target_include_directories(abeams_net
        PUBLIC
        ${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/include
)
