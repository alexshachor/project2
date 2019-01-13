cmake_minimum_required(VERSION 3.13)
project(project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(project2 main.cpp ClientHandler.h Solver.h Server.h MySerialServer.cpp MySerialServer.h MyClientHandler.cpp MyClientHandler.h CacheManager.h Searchable.h State.cpp State.h ISearcher.h Searcher.h)