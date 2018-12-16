cmake_minimum_required(VERSION 3.12)
project(Fourior)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fourior main.cpp common/util.cpp common/util.h common/concurrent.h common/aysnc.cpp common/async.h)