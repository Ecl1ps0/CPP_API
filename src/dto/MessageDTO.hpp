#ifndef MessageDTO_hpp
#define MessageDTO_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class MessageDTO : public oatpp::DTO {

  DTO_INIT(MessageDTO, DTO);

  DTO_FIELD(Int32, statusCode);
  DTO_FIELD(String, message);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* MessageDTO_hpp */
