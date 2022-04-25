#include <iostream>
#include "gen/serverabstract.h"
#include <jsonrpccpp/server/connectors/httpserver.h>

using namespace std;
using namespace jsonrpc;

class Server : public ServerAbstract
{
public:
	Server(AbstractServerConnector &connector, serverVersion_t type): ServerAbstract(connector, type) {}

	virtual std::string sayHello() override
	{
		std::cout << "Accepted sayHello method calling" << std::endl;
		return "Polychaetsy -- Hello.";
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