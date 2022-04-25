#include <iostream>
#include "gen/jsonrpcbaseserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>

using namespace std;
using namespace jsonrpc;

class Server : public JSONRPCBaseServer
{
public:
	Server(AbstractServerConnector &connector, serverVersion_t type): JSONRPCBaseServer(connector, type) {}

	virtual std::string sayHello(const std::string& param1, int param2) override
	{
		std::cout << "Accepted sayHello method calling" << std::endl;
		std::cout << param1 << " - " << param2 << std::endl;
		string res = param1 + to_string(param2);
		std::cout << res << std::endl;
		return res;
	}
};

int main()
{
	jsonrpc::HttpServer httpServer(8383);
	Server s(httpServer, jsonrpc::JSONRPC_SERVER_V1V2);
	s.StartListening();
	getchar();

	s.StopListening();

	return 0;
}