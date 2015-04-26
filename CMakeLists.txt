cmake_minimum_required(VERSION 3.1)
project(poo_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")

configure_file("data/models.dat" "data/models.dat")
configure_file("README.md" "README.md")

file(GLOB MODELS models/*.cpp models/*.h)
file(GLOB CONTROLLERS controllers/*.cpp controllers/*.h)
file(GLOB VIEWS views/*.cpp views/*.h)
file(GLOB TOPLEVEL *.cpp *.h)

add_executable(poo_2 ${TOPLEVEL} ${MODELS} ${VIEWS} ${CONTROLLERS} controllers/ControllerGoale.cpp controllers/ControllerGoale.h)