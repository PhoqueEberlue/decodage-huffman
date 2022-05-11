cmake_minimum_required(VERSION 3.23)
project(decodage_huffman)

set(CMAKE_CXX_STANDARD 20)

add_executable(decodage_huffman src/main.cpp src/alphabet.cpp src/alphabet.h src/character.cpp src/character.h src/huffman_decoding.cpp src/huffman_decoding.h)
