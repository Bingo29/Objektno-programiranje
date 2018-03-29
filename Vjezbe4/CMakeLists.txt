cmake_minimum_required(VERSION 3.1)

project(predavanje4 CXX)

add_executable(main Vjezba4.cpp)
target_compile_features(main PRIVATE cxx_decltype)
target_compile_features(main PRIVATE cxx_generic_lambdas)

