#ifndef NSAPPLINKRPC_ONHMISTATUSMARSHALLER_INCLUDE
#define NSAPPLINKRPC_ONHMISTATUSMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V1/OnHMIStatus.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	robok0der
*/

namespace NsAppLinkRPC
{

  struct OnHMIStatusMarshaller
  {
    static bool checkIntegrity(OnHMIStatus& e);
    static bool checkIntegrityConst(const OnHMIStatus& e);
  
    static bool fromString(const std::string& s,OnHMIStatus& e);
    static const std::string toString(const OnHMIStatus& e);
  
    static bool fromJSON(const Json::Value& s,OnHMIStatus& e);
    static Json::Value toJSON(const OnHMIStatus& e);
  };
}

#endif
