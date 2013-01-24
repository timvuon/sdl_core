#ifndef NSRPC2COMMUNICATION_APPLINKCORE_ONDEVICELISTUPDATED_INCLUDE
#define NSRPC2COMMUNICATION_APPLINKCORE_ONDEVICELISTUPDATED_INCLUDE

#include <string>
#include <vector>
#include "JSONHandler/RPC2Notification.h"


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

    class OnDeviceListUpdated : public ::NsRPC2Communication::RPC2Notification
    {
    public:
    
      OnDeviceListUpdated(const OnDeviceListUpdated& c);
      OnDeviceListUpdated(void);
    
      OnDeviceListUpdated& operator =(const OnDeviceListUpdated&);
    
      virtual ~OnDeviceListUpdated(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::vector< std::string>* get_deviceList(void);

// setters
/// 1 <= size <= 100
      bool set_deviceList(const std::vector< std::string>& deviceList);

      void reset_deviceList(void);


    private:

      friend class OnDeviceListUpdatedMarshaller;

      std::vector< std::string>* deviceList;

    };
  }
}

#endif
