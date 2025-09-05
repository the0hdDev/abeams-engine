
add_library(a_thread SHARED
        threadpool/threadpool.cpp
        threadpool/threadpool.h
)

target_include_directories(a_thread
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(a_thread
        PUBLIC
        a_util
)