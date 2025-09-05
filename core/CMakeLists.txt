
add_executable(abeams
        main.cpp
        initialize.h
)

target_include_directories(abeams
        PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(abeams
        PRIVATE
        a_thread
        a_util
        a_sim
        a_net
        a_cli
        spdlog::spdlog
)



