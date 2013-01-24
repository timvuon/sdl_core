#ifndef NSRPC2COMMUNICATION_TTS_GETSUPPORTEDLANGUAGESMARSHALLER_INCLUDE
#define NSRPC2COMMUNICATION_TTS_GETSUPPORTEDLANGUAGESMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/TTS/GetSupportedLanguages.h"

namespace NsRPC2Communication
{
  namespace TTS
  {

    struct GetSupportedLanguagesMarshaller
    {
      static bool checkIntegrity(GetSupportedLanguages& e);
      static bool checkIntegrityConst(const GetSupportedLanguages& e);
    
      static bool fromString(const std::string& s,GetSupportedLanguages& e);
      static const std::string toString(const GetSupportedLanguages& e);
    
      static bool fromJSON(const Json::Value& s,GetSupportedLanguages& e);
      static Json::Value toJSON(const GetSupportedLanguages& e);
    };
  }
}

#endif
