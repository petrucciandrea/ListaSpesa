cmake_minimum_required(VERSION 3.24)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListaSpesa main.cpp Articolo.cpp Articolo.h Observer.h Subject.h Lista.cpp Lista.h)
