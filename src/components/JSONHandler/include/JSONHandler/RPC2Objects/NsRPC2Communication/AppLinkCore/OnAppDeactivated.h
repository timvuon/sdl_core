#ifndef NSRPC2COMMUNICATION_APPLINKCORE_ONAPPDEACTIVATED_INCLUDE
#define NSRPC2COMMUNICATION_APPLINKCORE_ONAPPDEACTIVATED_INCLUDE

#include <string>
#include "JSONHandler/RPC2Request.h"

#include "../include/JSONHandler/ALRPCObjects/V2/DeactivateReason.h"

/*
  interface	NsRPC2Communication::AppLinkCore
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace AppLinkCore
  {

    class OnAppDeactivated : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      OnAppDeactivated(const OnAppDeactivated& c);
      OnAppDeactivated(void);
    
      OnAppDeactivated& operator =(const OnAppDeactivated&);
    
      virtual ~OnAppDeactivated(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::string& get_appName(void);

      const NsAppLinkRPCV2::DeactivateReason& get_reason(void);

      int get_appId(void);


// setters
/// appName <= 100
      bool set_appName(const std::string& appName);

      bool set_reason(const NsAppLinkRPCV2::DeactivateReason& reason);

      bool set_appId(int appId);


    private:

      friend class OnAppDeactivatedMarshaller;

      std::string appName;
      NsAppLinkRPCV2::DeactivateReason reason;
      int appId;

    };
  }
}

#endif
