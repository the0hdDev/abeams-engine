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

# ------------------------------
# Custom Build Type Configuration
# ------------------------------
# Define the Trace build type with proper CMake variables
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(isMultiConfig)
    # Multi-config generators (Visual Studio, Xcode)
    if(NOT "Trace" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Trace)
        set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "" FORCE)
    endif()
else()
    # Single-config generators (Make, Ninja)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "RelWithDebInfo" "MinSizeRel" "Trace")
endif()

# Define compiler and linker flags for Trace build type
set(CMAKE_CXX_FLAGS_TRACE "-O1 -g" CACHE STRING "C++ flags for Trace build type" FORCE)
set(CMAKE_C_FLAGS_TRACE "-O1 -g" CACHE STRING "C flags for Trace build type" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_TRACE "" CACHE STRING "Executable linker flags for Trace build type" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_TRACE "" CACHE STRING "Shared library linker flags for Trace build type" FORCE)
set(CMAKE_STATIC_LINKER_FLAGS_TRACE "" CACHE STRING "Static library linker flags for Trace build type" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_TRACE "" CACHE STRING "Module linker flags for Trace build type" FORCE)

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
find_package(ftxui CONFIG REQUIRED)

# Subdirectories
add_subdirectory(util)
add_subdirectory(net)
add_subdirectory(cli)
add_subdirectory(core)

# Only add sim and thread subdirectories if they exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/core/sim/CMakeLists.txt")
    add_subdirectory(core/sim)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/core/thread/CMakeLists.txt")
    add_subdirectory(core/thread)
endif()

# Function to apply trace build configuration to a target
function(configure_trace_build target_name)
    if(NOT TARGET ${target_name})
        return()
    endif()

    # Get current build type (for single-config generators)
    if(NOT isMultiConfig)
        set(current_config ${CMAKE_BUILD_TYPE})
    else()
        # For multi-config, we'll use generator expressions
        set(current_config $<CONFIG>)
    endif()

    if(NOT isMultiConfig AND CMAKE_BUILD_TYPE STREQUAL "Trace")
        message(STATUS "Configuring ${target_name} for Trace build with sanitizers")

        if(MSVC)
            # MSVC/Clang-CL sanitizers
            target_compile_options(${target_name} PRIVATE
                    /fsanitize=address
                    /Zi
            )
            target_link_options(${target_name} PRIVATE
                    /fsanitize=address
            )
        else()
            # GCC/Clang sanitizers
            target_compile_options(${target_name} PRIVATE
                    -fsanitize=address
                    -fsanitize=undefined
                    -fno-omit-frame-pointer
                    -fno-optimize-sibling-calls
                    -g
            )
            target_link_options(${target_name} PRIVATE
                    -fsanitize=address
                    -fsanitize=undefined
            )
        endif()
    elseif(isMultiConfig)
        # For multi-config generators, use generator expressions
        if(MSVC)
            target_compile_options(${target_name} PRIVATE
                    $<$<CONFIG:Trace>:/fsanitize=address>
                    $<$<CONFIG:Trace>:/Zi>
            )
            target_link_options(${target_name} PRIVATE
                    $<$<CONFIG:Trace>:/fsanitize=address>
            )
        else()
            target_compile_options(${target_name} PRIVATE
                    $<$<CONFIG:Trace>:-fsanitize=address>
                    $<$<CONFIG:Trace>:-fsanitize=undefined>
                    $<$<CONFIG:Trace>:-fno-omit-frame-pointer>
                    $<$<CONFIG:Trace>:-fno-optimize-sibling-calls>
                    $<$<CONFIG:Trace>:-g>
            )
            target_link_options(${target_name} PRIVATE
                    $<$<CONFIG:Trace>:-fsanitize=address>
                    $<$<CONFIG:Trace>:-fsanitize=undefined>
            )
        endif()
    endif()
endfunction()

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

# Apply configurations to main target if it exists
# Note: This assumes your main executable target is named 'abeams'
# You may need to adjust this based on your actual target names
if(TARGET abeams)
    configure_trace_build(abeams)
    configure_windows_target(abeams)
endif()

# Optional: Valgrind integration for Linux Trace builds
if(UNIX AND NOT APPLE AND NOT isMultiConfig AND CMAKE_BUILD_TYPE STREQUAL "Trace")
    find_program(VALGRIND_EXECUTABLE valgrind)
    if(VALGRIND_EXECUTABLE AND TARGET abeams)
        add_custom_target(valgrind-check
                COMMAND ${VALGRIND_EXECUTABLE} --leak-check=full --show-leak-kinds=all
                --track-origins=yes --error-exitcode=1
                $<TARGET_FILE:abeams>
                DEPENDS abeams
                WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                COMMENT "Running Valgrind memory checks on abeams..."
        )
        message(STATUS "Valgrind target 'valgrind-check' available")
    endif()
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