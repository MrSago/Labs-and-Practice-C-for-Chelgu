cmake_minimum_required(VERSION 3.10)
project(Labs-and-Practice-C-Chelgu VERSION 0.1.0)

function(setup_target TARGET)
    file(GLOB_RECURSE SRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}/*.c)

    file(GLOB_RECURSE TXT_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}/*.txt)

    add_executable(${TARGET} ${SRC_FILES} ${TXT_FILES})

    target_compile_options(${TARGET} PRIVATE
        -ansi -lwinmm)
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
setup_target(lab9-1)
setup_target(lab9-2)
setup_target(lab10)
setup_target(pract1-1)
setup_target(pract1-2)
setup_target(pract1-3)
setup_target(pract2-1)
setup_target(pract2-2)
setup_target(pract4)
