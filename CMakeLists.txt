cmake_minimum_required(VERSION 3.16)
project(abeams LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(boost CONFIG REQUIRED COMPONENTS asio beast)


add_subdirectory(core)
add_subdirectory(net)
add_subdirectory(util)
add_subdirectory(cli)