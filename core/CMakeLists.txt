add_executable(engine
    main.cpp
    initialize.h
)

target_link_libraries(engine
    PRIVATE
        abeams_thread
        abeams_util
        abeams_sim
        abeams_net
        abeams_cli
        spdlog::spdlog
)

if(WIN32)
    target_link_libraries(engine PRIVATE ws2_32 mswsock)
endif()
