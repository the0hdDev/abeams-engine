
add_library(abeams_thread STATIC
        threadpool/threadpool.cpp
        threadpool/threadpool.h
)

target_include_directories(abeams_thread
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

