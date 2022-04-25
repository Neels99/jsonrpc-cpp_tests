
message("${CMAKE_CURRENT_SOURCE_DIR}/gen/serverabstract.h")
add_custom_command(
        OUTPUT gen/serverabstract3.h
        COMMAND jsonrpcstub ARGS ${CMAKE_CURRENT_SOURCE_DIR}/spec.json --cpp-server=ServerAbstract --cpp-server-file=gen/serverabstract2.h
        MAIN_DEPENDENCY spec.json
        DEPENDS jsonrpcstub
        COMMENT "Generating Server Stubfiles"
        VERBATIM
)

add_custom_target(common_stubs2
        DEPENDS ${CMAKE_BINARY_DIR}/gen/serverabstract3.h
        )