
message("BUILD SCRIPT: ${CMAKE_CURRENT_SOURCE_DIR}/gen/serverabstract.h")
add_custom_command(
        OUTPUT gen/serverabstract.h
        COMMAND jsonrpcstub ARGS ${CMAKE_CURRENT_SOURCE_DIR}/spec.json --cpp-server=ServerAbstract --cpp-server-file=gen/serverabstract.h
        MAIN_DEPENDENCY spec.json
        DEPENDS jsonrpcstub
        COMMENT "Generating Server Stubfiles"
        VERBATIM
)

#add_library(common_stubs ${CMAKE_BINARY_DIR}/gen/serverabstract3.h)

add_custom_target(common_stubs
        DEPENDS ${CMAKE_BINARY_DIR}/gen/serverabstract.h
        )