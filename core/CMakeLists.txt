
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
        abeams_thread
        abeams_util
        abeams_sim
        abeams_net
        abeams_cli
        spdlog::spdlog
)



