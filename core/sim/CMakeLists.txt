add_library(abeams_sim SHARED
        sim.cpp
        sim.h
)

target_include_directories(abeams_sim
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)
