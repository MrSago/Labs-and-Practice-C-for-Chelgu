
cmake_minimum_required(VERSION 3.22)
project(Labs-and-Practice-C-Chelgu VERSION 2.0)

set(CMAKE_C_STANDARD 90)

function(setup_target TARGET)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET})

    file(GLOB_RECURSE SRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}/*.c)

    add_executable(${TARGET} ${SRC_FILES})
endfunction(setup_target TARGET)

setup_target(ASCII)
setup_target(lab1)
setup_target(lab2)
setup_target(lab3)
setup_target(lab4)
setup_target(lab5)
setup_target(lab6)
setup_target(lab7)
setup_target(lab8)
if (WIN32)
    setup_target(lab9-1)
    setup_target(lab9-2)
    setup_target(lab10)
    target_link_libraries(lab10 winmm)
    setup_target(pract2-1)
    setup_target(pract2-2)
else ()
    message(STATUS "lab9-1, lab9-2, lab10, pract2-1, pract2-2 can be builded only in Windows, because Windows library required")
endif ()
setup_target(pract1-1)
setup_target(pract1-2)
setup_target(pract1-3)
message(STATUS "pract3 already for use in Visual Studio")
setup_target(pract4)

