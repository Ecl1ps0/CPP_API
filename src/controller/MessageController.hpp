#ifndef MessageController_hpp
#define MessageController_hpp

#include "dto/MessageDTO.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MessageController : public oatpp::web::server::api::ApiController {
public:
  MessageController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : 
    oatpp::web::server::api::ApiController(objectMapper) {}

  ENDPOINT("GET", "/hello", root) {
    auto dto = MessageDTO::createShared();
    dto -> statusCode = 200;
    dto -> message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
  }
};

#include OATPP_CODEGEN_END(ApiController)

#endif /* MessageController_hpp */
