cmake_minimum_required(VERSION 4.0)
project(csapp C)

set(CMAKE_C_STANDARD 11)

add_executable(csapp
        chapter2/c2_inplace_swap.c
        chapter2/c2_show_bytes.c
        chapter2/c2_strlonger.c
        datalab-handout/btest.c
        datalab-handout/bits.c
        datalab-handout/decl.c
        datalab-handout/fshow.c
        datalab-handout/tests.c
        my_test.c
        chapter2/homework/2_58.c
        chapter2/homework/2_59.c
        chapter2/homework/2_60.c
        chapter2/homework/2_61.c
        chapter2/homework/2_62.c
        chapter2/homework/2_63.c
        chapter2/homework/2_64.c
        chapter2/homework/65.c
        chapter2/homework/67.c
        chapter2/homework/66.c
        chapter2/homework/68.c
        chapter2/homework/69.c
        chapter2/homework/70.c
        chapter2/homework/72.c
        chapter2/homework/73.c
        chapter2/homework/74.c
        chapter2/homework/75.c)
