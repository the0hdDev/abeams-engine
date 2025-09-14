cmake_minimum_required(VERSION 3.16)
project(abeams)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure proper RPATH handling for installed binaries
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
    set(CMAKE_INSTALL_RPATH "@executable_path")
elseif(UNIX)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

# Use vcpkg toolchain if available
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg toolchain file")
endif()

# Output directories
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# Multi-config generator support (MSVC, Xcode, etc.)
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(isMultiConfig)
    foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
        if(WIN32)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
            set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
            set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
        else()
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
            set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
            set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
        endif()
    endforeach()
endif()

# Dependencies
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(ftxui CONFIG REQUIRED)

# Subdirectories
add_subdirectory(util)
add_subdirectory(net)
add_subdirectory(cli)
add_subdirectory(core)
add_subdirectory(unilog)

# Only add sim and thread subdirectories if they exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/core/sim/CMakeLists.txt")
    add_subdirectory(core/sim)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/core/thread/CMakeLists.txt")
    add_subdirectory(core/thread)
endif()

# Function to configure Windows-specific settings for a target
function(configure_windows_target target_name)
    if(NOT TARGET ${target_name})
        return()
    endif()

    if(WIN32)
        target_compile_definitions(${target_name} PRIVATE _WIN32_WINNT=0x0601)
        target_link_libraries(${target_name} PRIVATE ws2_32 mswsock)
    endif()
endfunction()

# Apply Windows configuration to main target if it exists
if(TARGET abeams)
    configure_windows_target(abeams)
endif()

# Print configuration information
message(STATUS "abeams C++ Project Configuration:")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Generator: ${CMAKE_GENERATOR}")
message(STATUS "  Multi-config: ${isMultiConfig}")
if(NOT isMultiConfig)
    message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "  Available Configurations: ${CMAKE_CONFIGURATION_TYPES}")
endif()
message(STATUS "  Runtime Output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "  Archive Output: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")