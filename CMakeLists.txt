cmake_minimum_required(VERSION 3.16)
SET(CMAKE_CXX_STANDARD 20)

project(jsonrpc)
#find_package(libjson-rpc-cpp REQUIRED)

set(abs gen/clientabstract.h gen/serverabstract.h)

add_executable(jsonrpc_client client.cpp ${abs})
#target_link_libraries(jsonrpc_client libjson-rpc-cpp)'

add_executable(jsonrpc_server server.cpp ${abs})