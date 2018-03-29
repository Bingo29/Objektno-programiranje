cmake_minimum_required(VERSION 3.1)

project(predavanje3 CXX)

add_executable(main Vjezba1.cpp)
target_compile_features(main PRIVATE cxx_decltype)
target_compile_features(main PRIVATE cxx_generic_lambdas)

