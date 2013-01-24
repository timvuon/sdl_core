#ifndef NSAPPLINKRPC_ONAPPINTERFACEUNREGISTEREDMARSHALLER_INCLUDE
#define NSAPPLINKRPC_ONAPPINTERFACEUNREGISTEREDMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V1/OnAppInterfaceUnregistered.h"


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

  struct OnAppInterfaceUnregisteredMarshaller
  {
    static bool checkIntegrity(OnAppInterfaceUnregistered& e);
    static bool checkIntegrityConst(const OnAppInterfaceUnregistered& e);
  
    static bool fromString(const std::string& s,OnAppInterfaceUnregistered& e);
    static const std::string toString(const OnAppInterfaceUnregistered& e);
  
    static bool fromJSON(const Json::Value& s,OnAppInterfaceUnregistered& e);
    static Json::Value toJSON(const OnAppInterfaceUnregistered& e);
  };
}

#endif
