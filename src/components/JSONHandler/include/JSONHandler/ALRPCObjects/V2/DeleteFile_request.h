#ifndef NSAPPLINKRPCV2_DELETEFILE_REQUEST_INCLUDE
#define NSAPPLINKRPCV2_DELETEFILE_REQUEST_INCLUDE

#include <string>

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
     Used to delete a file resident on the SYNC module in the app's local cache.
     Not supported on first generation SYNC vehicles. 
*/

  class DeleteFile_request : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    DeleteFile_request(const DeleteFile_request& c);
    DeleteFile_request(void);
    
    virtual ~DeleteFile_request(void);
  
    bool checkIntegrity(void);

    const std::string& get_syncFileName(void) const;

    bool set_syncFileName(const std::string& syncFileName_);

  private:
  
    friend class DeleteFile_requestMarshaller;


///  File reference name.
      std::string syncFileName;	//!< (500)
  };

}

#endif
