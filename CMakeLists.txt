cmake_minimum_required(VERSION 3.7)
project(BoolPgiaClient)

set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(SDK_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../P2PGamePlatform)

set(SOURCE_FILES
        main.cpp
        GameProtocol.h
        BPClient.h BPClient.cpp
        GameMessageHandler.h GameMessageHandler.cpp
        ServerMessageHandler.h
        ServerMessageHandler.cpp BPGame.cpp BPGame.h test/RunTest.cpp test/RunTest.h)

include_directories(${SDK_LIB})
add_executable(BoolPgiaClient ${SOURCE_FILES})

target_link_libraries(BoolPgiaClient Threads::Threads)
target_link_libraries(BoolPgiaClient ${SDK_LIB}/cmake-build-debug/libP2PGamePlatform.a)