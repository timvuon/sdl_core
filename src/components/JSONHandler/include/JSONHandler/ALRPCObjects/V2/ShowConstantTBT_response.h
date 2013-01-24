#ifndef NSAPPLINKRPCV2_SHOWCONSTANTTBT_RESPONSE_INCLUDE
#define NSAPPLINKRPCV2_SHOWCONSTANTTBT_RESPONSE_INCLUDE

#include <string>

#include "Result.h"
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

  class ShowConstantTBT_response : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    ShowConstantTBT_response(const ShowConstantTBT_response& c);
    ShowConstantTBT_response(void);
    
    virtual ~ShowConstantTBT_response(void);
  
    ShowConstantTBT_response& operator =(const ShowConstantTBT_response&);
  
    bool checkIntegrity(void);

    bool get_success(void) const;
    const Result& get_resultCode(void) const;
    const std::string* get_info(void) const;

    bool set_success(bool success_);
    bool set_resultCode(const Result& resultCode_);
    void reset_info(void);
    bool set_info(const std::string& info_);

  private:
  
    friend class ShowConstantTBT_responseMarshaller;


/**
     true, if successful
     false, if failed
*/
      bool success;

///  See Result
      Result resultCode;

///  Provides additional human readable info regarding the result.
      std::string* info;	//!< (1000)
  };

}

#endif
