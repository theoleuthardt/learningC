cmake_minimum_required(VERSION 3.27)
project(learningC C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(exam/exam_modules)
add_subdirectory(examTemplate/examTemp_modules)
add_subdirectory(examTemplate/examTemp_modules)
add_subdirectory(uebung7/uebung7_modules)
add_subdirectory(uebung7/palindromLIB)

add_executable(E1E2 uebung1und2/main.c)
add_executable(E3 uebung3/main.c)

add_executable(E5T1 uebung5/aufgabe1.c)
add_executable(E5T2 uebung5/aufgabe2.c)
add_executable(E5T3 uebung5/aufgabe3.c)
add_executable(E5T4 uebung5/aufgabe4.c)
add_executable(E5T5 uebung5/aufgabe5.c)

add_executable(E6T1 uebung6/aufgabe1.c)
add_executable(E6T2 uebung6/aufgabe2.c)
add_executable(E6T3 uebung6/aufgabe3.c)
add_executable(E6T4 uebung6/aufgabe4.c)
add_executable(E6T5 uebung6/aufgabe5.c)

add_executable(E7T1 uebung7/aufgabe1.c palindromLIB/palindrom.c)
target_link_libraries(E7T1 m)
add_executable(E7T2 uebung7/aufgabe2.c uebung7_modules/list.c)
target_link_libraries(E7T2 m)
add_executable(E7T3 uebung7/aufgabe3.c uebung7_modules/geometrics.c)
target_link_libraries(E7T3 m)

add_executable(E8T1 uebung8/aufgabe1.c)
add_executable(E8T2 uebung8/aufgabe2.c)
add_executable(E8T3 uebung8/aufgabe3.c)
add_executable(E8T4 uebung8/aufgabe4.c)
add_executable(E8T5 uebung8/aufgabe5.c)
add_executable(E8T6 uebung8/aufgabe6.c)
add_executable(E8T7 uebung8/aufgabe7.c)
add_executable(E8T8 uebung8/aufgabe8.c)

find_package(PkgConfig REQUIRED) # ermöglicht das einfache Einbinden von Libraries
pkg_check_modules(GTK4 REQUIRED gtk4) # sucht das Paket gtk4 und erstellt die benötigten Variablen mit dem Prefix GTK4_ in den folgende Zeilen
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})
add_executable(E9 main.c)
target_link_libraries(E9 ${GTK4_LIBRARIES})

add_executable(MOCK_EXAM probePruefung/main.c)
add_executable(EXAM_TEMPLATE examTemplate/main.c examTemp_modules/list.c)
target_link_libraries(EXAM_TEMPLATE m)

add_executable(EXAM exam/main.c exam_modules/list.c)
target_link_libraries(EXAM m)