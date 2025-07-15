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
        chapter2/homework/2_60.c)
