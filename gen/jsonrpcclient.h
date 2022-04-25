/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_JSONRPCCLIENT_H_
#define JSONRPC_CPP_STUB_JSONRPCCLIENT_H_

#include <jsonrpccpp/client.h>

class JSONRPCClient : public jsonrpc::Client
{
    public:
        JSONRPCClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

        std::string sayHello(const std::string& param1, int param2) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p.append(param1);
            p.append(param2);
            Json::Value result = this->CallMethod("sayHello",p);
            if (result.isString())
                return result.asString();
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
};

#endif //JSONRPC_CPP_STUB_JSONRPCCLIENT_H_
