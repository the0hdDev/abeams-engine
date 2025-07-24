cmake_minimum_required(VERSION 3.2)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(engine
        src/main.cpp
        src/io/util/parseConfig.cpp
        src/io/util/parseConfig.h
        src/header/config.hpp
        src/datapull/pullDataUsr.cpp
        src/datapull/pullDataUsr.h
        src/datapull/pullDataSpdr.cpp
        src/datapull/pullDataSpdr.h
        src/com/estbComFD.cpp
        src/com/estbComFD.h
        src/com/httpReqResHandler.cpp
        src/com/httpReqResHandler.h
        src/io/util/logsys/logsys.cpp
        src/io/util/logsys/logsys.h
        src/io/util/logsys/logToFile.cpp
        src/io/util/logsys/logToFile.h
        src/io/thread/threadpool/threadpool.cpp
        src/io/thread/threadpool/threadpool.h
)

# Copying config.json and default.log to the build directory
file(COPY config.json DESTINATION ${CMAKE_BINARY_DIR})
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/log")
file(COPY default.log DESTINATION "${CMAKE_BINARY_DIR}/log")
add_custom_command(
     TARGET engine POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_BINARY_DIR}/log/default.log"
)

target_include_directories(engine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/header
        ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/include
)

target_link_libraries(engine
        PRIVATE
        fmt::fmt
        spdlog::spdlog
)

if(WIN32)
    target_link_libraries(engine PRIVATE ws2_32 mswsock)
endif()
