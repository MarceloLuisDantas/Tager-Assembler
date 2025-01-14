cmake_minimum_required(VERSION 3.22.1)
project("TAGER_ASSEMBLER")
add_compile_options(-Wall)
add_executable(
    tager
    src/tager.c
    src/files.c
    src/strings.c
    src/linked_list.c
)