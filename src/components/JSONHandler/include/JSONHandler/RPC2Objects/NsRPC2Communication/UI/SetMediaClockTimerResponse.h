#ifndef NSRPC2COMMUNICATION_UI_SETMEDIACLOCKTIMERRESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_UI_SETMEDIACLOCKTIMERRESPONSE_INCLUDE

#include "JSONHandler/RPC2Response.h"


/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace UI
  {

    class SetMediaClockTimerResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      SetMediaClockTimerResponse(const SetMediaClockTimerResponse& c);
      SetMediaClockTimerResponse(void);
    
      SetMediaClockTimerResponse& operator =(const SetMediaClockTimerResponse&);
    
      virtual ~SetMediaClockTimerResponse(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class SetMediaClockTimerResponseMarshaller;


    };
  }
}

#endif
