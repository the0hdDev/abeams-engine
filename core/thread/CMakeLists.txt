
add_library(abeams_thread SHARED
        threadpool/threadpool.cpp
        threadpool/threadpool.h
)

target_include_directories(abeams_thread
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(abeams_thread
        PUBLIC
        abeams_util
)