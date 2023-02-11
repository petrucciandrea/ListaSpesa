cmake_minimum_required(VERSION 3.24)
project(ListaSpesa)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Articolo.cpp Articolo.h Observer.h Subject.h Lista.cpp Lista.h Utente.cpp Utente.h ListaNotifier.h)
add_executable(ListaSpesa main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ListaSpesa core)