add_library(abeams_sim STATIC
        sim.cpp
        sim.h
)

target_include_directories(abeams_sim
        PUBLIC
        ${CMAKE_SOURCE_DIR}
)
