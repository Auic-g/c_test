cmake_minimum_required(VERSION 3.10)
project(DataStructTest)

add_compile_options(-fexec-charset=GBK)

# 告诉编译器：去 includes 文件夹里找头文件
include_directories(includes)

# 告诉编译器：把 main.c 和 src 里面的 sqlist.c 一起编译成一个叫 main_app 的程序
add_executable(main_app main.c src/sqlist.c src/linklist.c/ src/stack.c)
