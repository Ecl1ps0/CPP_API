#include "controller/MessageController.hpp"
#include "AppComponent.hpp"

#include "oatpp/network/Server.hpp"

void run() {
  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  auto messageController = std::make_shared<MessageController>();
  router -> addController(messageController);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("App", "Server running on port %s", connectionProvider->getProperty("port").getData());

  server.run();
}

int main(int argc, const char *argv[]) {
  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

	return 0;
}
