cmake_minimum_required(VERSION 3.1)
project(poo_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")

set(SOURCE_FILES main.cpp)
configure_file("data/models.dat" "data/models.dat")
add_executable(poo_2 ${SOURCE_FILES} views/Console.cpp views/Console.h Engine.cpp Engine.h models/Stoc.cpp models/Stoc.h models/Bun.cpp models/Bun.h controllers/Controller.cpp controllers/Controller.h log.cpp log.h models/Model.cpp models/Model.h controllers/Viewer.cpp controllers/Viewer.h)