#ifndef NSAPPLINKRPCV2_DELETESUBMENU_RESPONSEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_DELETESUBMENU_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/DeleteSubMenu_response.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	robok0der
*/

namespace NsAppLinkRPCV2
{

  struct DeleteSubMenu_responseMarshaller
  {
    static bool checkIntegrity(DeleteSubMenu_response& e);
    static bool checkIntegrityConst(const DeleteSubMenu_response& e);
  
    static bool fromString(const std::string& s,DeleteSubMenu_response& e);
    static const std::string toString(const DeleteSubMenu_response& e);
  
    static bool fromJSON(const Json::Value& s,DeleteSubMenu_response& e);
    static Json::Value toJSON(const DeleteSubMenu_response& e);
  };
}

#endif
