cmake_minimum_required(VERSION 3.13)
project(project2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(project2 main.cpp ClientHandler.h Solver.h Server.h
        MySerialServer.cpp MySerialServer.h MyClientHandler.cpp
        MyClientHandler.h CacheManager.h Searchable.h State.h
        ISearcher.h Searcher.h BestFirstSearch.h BestFirstSearch.cpp MyExceptions.h Sockets.cpp Sockets.h FileCacheManager.cpp FileCacheManager.h StringHelper.cpp StringHelper.h MatrixSearchable.cpp MatrixSearchable.h SearchSolver.cpp SearchSolver.h)