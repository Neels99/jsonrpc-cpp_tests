cmake_minimum_required(VERSION 3.16)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
message("${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
SET(CMAKE_CXX_STANDARD 20)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
        SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
#        LOCAL
)
SET(HUNTER_STATUS_DEBUG ON)
project(jsonrpc)

include("gen/buildScript.cmake")
#macro(jsonrpcstub_create EXECUTABLE SPEC SERVERNAME SERVERDIR SERVERFILENAME CLIENTNAME CLIENTDIR CLIENTFILENAME)
#    if (ETH_JSON_RPC_STUB)
#        add_custom_target(${SPEC}stub)
#        add_custom_command(
#                TARGET ${SPEC}stub
#                POST_BUILD
#                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${SPEC}"
#                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                COMMAND ${CMAKE_COMMAND} -DETH_SPEC_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SPEC}" -DETH_SOURCE_DIR="${CMAKE_SOURCE_DIR}" -DETH_CMAKE_DIR="${ETH_CMAKE_DIR}"
#                -DETH_CLIENT_DIR="${CLIENTDIR}"
#                -DETH_CLIENT_NAME=${CLIENTNAME}
#                -DETH_CLIENT_FILENAME=${CLIENTFILENAME}
#                -DETH_SERVER_DIR="${SERVERDIR}"
#                -DETH_SERVER_NAME=${SERVERNAME}
#                -DETH_SERVER_FILENAME=${SERVERFILENAME}
#                -DETH_JSON_RPC_STUB="${ETH_JSON_RPC_STUB}"
#                -P "${ETH_SCRIPTS_DIR}/jsonrpcstub.cmake"
#        )
#        add_dependencies(${EXECUTABLE} ${SPEC}stub)
#    endif ()
#endmacro()

#jsonrpcstub_create(
#        EthClient spec.json EthClient
#)

# Generate spec
#file(MAKE_DIRECTORY gen)
#
#message("${CMAKE_CURRENT_SOURCE_DIR}/gen/serverabstract.h")
#add_custom_command(
#        OUTPUT gen/serverabstract.h
#        COMMAND jsonrpcstub ARGS ${CMAKE_CURRENT_SOURCE_DIR}/spec.json --cpp-server=ServerAbstract --cpp-server-file=gen/serverabstract.h
#        MAIN_DEPENDENCY spec.json
#        DEPENDS jsonrpcstub
#        COMMENT "Generating Server Stubfiles"
#        VERBATIM
#)

#add_custom_command(
#        OUTPUT gen/clientabstract.h
#        COMMAND jsonrpcstub ARGS ${CMAKE_CURRENT_SOURCE_DIR}/spec.json --cpp-client=ClientAbstract --cpp-client-file=gen/clientabstract.h
#        MAIN_DEPENDENCY spec.json
#        DEPENDS jsonrpcstub
#        COMMENT "Generating Server Stubfiles"
#        VERBATIM
#)
include_directories(${CMAKE_BINARY_DIR})

#############
#
#add_library(jsoncpp INTERFACE)
#target_link_libraries(jsoncpp INTERFACE ${JSONCPP_LIBRARIES})
#target_include_directories(jsoncpp INTERFACE ${JSONCPP_INCLUDE_DIRS})
#
#add_library(jsonrpccpp INTERFACE)
#target_link_libraries(jsonrpccpp INTERFACE ${JSONRPCCPP_LIBRARIES})
#target_include_directories(jsonrpccpp INTERFACE ${JSONRPCCPP_INCLUDE_DIRS})
#

#find_package(JSONCPP REQUIRED)
#find_package(JSONRPCCPP REQUIRED)
#INCLUDE_DIRECTORIES(
#        jsoncpp
#        jsonrpccpp
#)

add_custom_target(common_stubs
        DEPENDS gen/abstractstubserver.h gen/stubclient.h
        )

hunter_add_package(jsoncpp)
find_package(jsoncpp CONFIG REQUIRED)

#hunter_add_package(jsonrpccpp)
#find_package(jsonrpccpp CONFIG REQUIRED)

hunter_add_package(libjson-rpc-cpp)
find_package(libjson-rpc-cpp CONFIG REQUIRED)

# Executables
set(abs gen/clientabstract.h gen/serverabstract.h)
#add_custom_target(common_stubs
#        DEPENDS ${CMAKE_BINARY_DIR}/gen/abstractstubserver.h ${CMAKE_BINARY_DIR}/gen/stubclient.h
#        )
add_executable(jsonrpc_client client.cpp ${abs})

add_executable(jsonrpc_server server.cpp ${abs})
TARGET_LINK_LIBRARIES(jsonrpc_server
        jsoncpp
        jsonrpccpp-common
#        jsonrpccpp-client
        jsonrpccpp-server
        )