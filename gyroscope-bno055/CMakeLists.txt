cmake_minimum_required(VERSION 3.0)
project(bno055)

add_executable(bno-prog getbno055.c i2c_bno055.c)
