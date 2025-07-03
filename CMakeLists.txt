cmake_minimum_required(VERSION 3.31)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")


project(engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(engine
        src/main.cpp
        src/io/parseConfig.cpp
        src/io/parseConfig.h
        src/header/config.h
        src/datapull/pullDataUsr.cpp
        src/datapull/pullDataUsr.h
        src/datapull/pullDataSpdr.cpp
        src/datapull/pullDataSpdr.h
        src/com/estbComQT.cpp
        src/com/estbComQT.h
)

file(COPY src/mconf.json DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(engine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/header
        Libraries/include
)

if(WIN32)
    target_link_libraries(engine ws2_32)
endif()
