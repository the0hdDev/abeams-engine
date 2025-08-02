cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Cppcheck ===
find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)
if(CPPCHECK_EXECUTABLE)
    message(STATUS "Cppcheck found: ${CPPCHECK_EXECUTABLE}")
    set(CMAKE_CXX_CPPCHECK
            ${CPPCHECK_EXECUTABLE}
            --enable=warning,performance,portability
            --inconclusive
            --quiet
            --inline-suppr
            --suppress=missingIncludeSystem
    )
else()
    message(WARNING "Cppcheck not found. Skipping static analysis.")
endif()

# === Project Code ===
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(engine
        src/main.cpp
        src/io/util/parseConfig.cpp
        src/io/util/parseConfig.h
        src/header/config.hpp
        src/com/wsServer.cpp
        src/com/wsServer.h
        src/com/wsHandler.cpp
        src/com/wsHandler.h
        src/io/util/logsys/logsys.cpp
        src/io/util/logsys/logsys.h
        src/io/util/logsys/logToFile.cpp
        src/io/util/logsys/logToFile.h
        src/thread/threadpool/threadpool.cpp
        src/thread/threadpool/threadpool.h
        src/initialize.h
        src/cli/cli.cpp
        src/cli/cli.h
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
