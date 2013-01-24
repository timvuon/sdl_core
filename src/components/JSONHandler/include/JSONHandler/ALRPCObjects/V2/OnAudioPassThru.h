#ifndef NSAPPLINKRPCV2_ONAUDIOPASSTHRU_INCLUDE
#define NSAPPLINKRPCV2_ONAUDIOPASSTHRU_INCLUDE


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

  class OnAudioPassThru : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    OnAudioPassThru(const OnAudioPassThru& c);
    OnAudioPassThru(void);
    
    virtual ~OnAudioPassThru(void);
  
    bool checkIntegrity(void);



  private:
  
    friend class OnAudioPassThruMarshaller;

  };

}

#endif
