cmake_minimum_required(VERSION 3.16)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
message("${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
#SET(CMAKE_CXX_STANDARD 20)

# Hunter
include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
        SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
#        LOCAL
)
SET(HUNTER_STATUS_DEBUG ON)

project(jsonrpc)

#include("gen/buildScript.cmake")
include_directories(${CMAKE_BINARY_DIR})

# JSONRPC/JSONCPP add packg
hunter_add_package(jsoncpp)
find_package(jsoncpp CONFIG REQUIRED)

hunter_add_package(libjson-rpc-cpp)
find_package(libjson-rpc-cpp CONFIG REQUIRED)

# Executables
set(abs gen/jsonrpcclient.h gen/jsonrpcbaseserver.h)
#add_custom_target(common_stubs
#        DEPENDS ${CMAKE_BINARY_DIR}/gen/abstractstubserver.h ${CMAKE_BINARY_DIR}/gen/stubclient.h
#        )
add_executable(jsonrpc_client client.cpp ${abs})
TARGET_LINK_LIBRARIES(jsonrpc_client
        jsoncpp
        jsonrpccpp-common
        jsonrpccpp-client
        )
#set_property(SOURCE unit-tests.cpp APPEND PROPERTY OBJECT_DEPENDS testData.cpp)

add_executable(jsonrpc_server server.cpp ${abs})
TARGET_LINK_LIBRARIES(jsonrpc_server
        jsoncpp
        jsonrpccpp-common
#        jsonrpccpp-client
        jsonrpccpp-server
        )
#add_dependencies(jsonrpc_server common_stubs)