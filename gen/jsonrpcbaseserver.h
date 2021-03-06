/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_JSONRPCBASESERVER_H_
#define JSONRPC_CPP_STUB_JSONRPCBASESERVER_H_

#include <jsonrpccpp/server.h>

class JSONRPCBaseServer : public jsonrpc::AbstractServer<JSONRPCBaseServer>
{
    public:
        JSONRPCBaseServer(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<JSONRPCBaseServer>(conn, type)
        {
            this->bindAndAddMethod(jsonrpc::Procedure("sayHello", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_STRING, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_INTEGER, NULL), &JSONRPCBaseServer::sayHelloI);
        }

        inline virtual void sayHelloI(const Json::Value &request, Json::Value &response)
        {
            response = this->sayHello(request[0u].asString(), request[1u].asInt());
        }
        virtual std::string sayHello(const std::string& param1, int param2) = 0;
};

#endif //JSONRPC_CPP_STUB_JSONRPCBASESERVER_H_
