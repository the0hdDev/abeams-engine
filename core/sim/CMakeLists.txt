

add_library(a_sim SHARED
        sim.cpp
        sim.h
)

target_include_directories(a_sim
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)
