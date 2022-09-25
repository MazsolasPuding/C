cmake_minimum_required(VERSION "3.22.0")

project("HomeWorkOne")

add_executable("HomeWorkOne" "Main.c")

install(TARGETS "HomeWorkOne" DESTINATION bin)

install(FILES "main.c" DESTINATION src)