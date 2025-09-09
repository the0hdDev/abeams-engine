cmake_minimum_required(VERSION 3.20)
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

# Use vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

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

# Dependencies
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Subdirectories
add_subdirectory(util)
add_subdirectory(net)
add_subdirectory(cli)
add_subdirectory(core)
add_subdirectory(core/sim)
add_subdirectory(core/thread)

# Windows-specific definitions and libraries
if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
    if(TARGET abeams)
        target_link_libraries(abeams PRIVATE ws2_32 mswsock)
    endif()
endif()

# ------------------------------
# Custom Build Types
# ------------------------------
# Add custom build type "Trace"
set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebInfo MinSizeRel Trace CACHE STRING "" FORCE)

if(CMAKE_BUILD_TYPE STREQUAL "Trace")
    message(STATUS "Trace build enabled: Adding extra sanitizer and analysis flags.")

    if(MSVC)
        # MSVC sanitizers are limited (mainly /fsanitize=address in Clang-CL)
        target_compile_options(abeams PRIVATE /fsanitize=address)
        target_link_options(abeams PRIVATE /fsanitize=address)
    else()
        # GCC/Clang sanitizers
        target_compile_options(abeams PRIVATE
                -fsanitize=address
                -fsanitize=undefined
                -fno-omit-frame-pointer
                -fno-optimize-sibling-calls
                -g
        )
        target_link_options(abeams PRIVATE
                -fsanitize=address
                -fsanitize=undefined
        )
    endif()

    # Optional: Valgrind integration (Linux / macOS only)
    if(UNIX AND NOT APPLE) # Linux only, since Valgrind is weak on macOS
        find_program(VALGRIND_EXECUTABLE valgrind)
        if(VALGRIND_EXECUTABLE)
            add_custom_target(valgrind-check
                    COMMAND ${VALGRIND_EXECUTABLE} --leak-check=full --show-leak-kinds=all
                    --track-origins=yes --error-exitcode=1
                    $<TARGET_FILE:abeams>
                    DEPENDS abeams
                    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                    COMMENT "Running Valgrind memory checks..."
            )
        endif()
    endif()
endif()
