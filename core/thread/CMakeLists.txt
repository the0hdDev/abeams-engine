add_library(abeams_thread SHARED
    threadpool/threadpool.cpp
    threadpool/threadpool.h
)

target_include_directories(abeams_thread
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(abeams_thread
    PUBLIC fmt::fmt
)
