#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

// Class that holds Application components and register components in oatpp::base::Environment
class AppComponent {
public:

  // Connection provider component that provides port listening 
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider) ([] {
      return oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 8000, oatpp::network::Address::IP_4});
  }());

  // Creating Router component
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter) ([] {
      return oatpp::web::server::HttpRouter::createShared();
  }());

  // Creating ConnectionHandler component which uses Router component to route requests
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler) ([] {
      OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
      return oatpp::web::server::HttpConnectionHandler::createShared(router);
  }());

  // Creating ObjectMapper component to serialize/deserialize DTOs in Controller
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper) ([] {
      return oatpp::parser::json::mapping::ObjectMapper::createShared();
  }());

};

#endif /* AppComponent_hpp */

