#ifndef NSAPPLINKRPCV2_UNREGISTERAPPINTERFACE_REQUEST_INCLUDE
#define NSAPPLINKRPCV2_UNREGISTERAPPINTERFACE_REQUEST_INCLUDE


#include "JSONHandler/ALRPCMessage.h"


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

/**
     Closes an interface from a mobile application.
     After unregisterAppInterface, no commands other than registerAppInterface will be accepted/executed.
     Will fail, if no registerAppInterface was completed successfully before.
*/

  class UnregisterAppInterface_request : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    UnregisterAppInterface_request(const UnregisterAppInterface_request& c);
    UnregisterAppInterface_request(void);
    
    virtual ~UnregisterAppInterface_request(void);
  
    bool checkIntegrity(void);



  private:
  
    friend class UnregisterAppInterface_requestMarshaller;

  };

}

#endif
