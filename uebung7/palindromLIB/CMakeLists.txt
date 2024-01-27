add_library(Palindrom palindrom.c)
cmake_minimum_required(VERSION 3.26)
project(uebung7 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(palindromLIB) # Baut die Library (definiert im Unterordner) bevor die Applikation gebaut wird.
add_executable(PALINDROM palindrom.c)
target_link_libraries(PALINDROM PUBLIC Palindrom) # Fügt die Library zur Applikation hinzu.
target_include_directories(PALINDROM PUBLIC Palindrom) # Inkludiert die Headerdateien.