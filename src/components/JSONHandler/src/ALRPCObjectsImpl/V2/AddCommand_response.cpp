#include "../include/JSONHandler/ALRPCObjects/V2/AddCommand_response.h"
#include "AddCommand_responseMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Marshaller.h"
#include "ResultMarshaller.h"

#define PROTOCOL_VERSION	2


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	robok0der
*/

using namespace NsAppLinkRPCV2;
AddCommand_response& AddCommand_response::operator =(const AddCommand_response& c)
{
  success= c.success;
  resultCode= c.resultCode;
  info= c.info ? new std::string(c.info[0]) : 0;

  return *this;
}


AddCommand_response::~AddCommand_response(void)
{
  if(info)
    delete info;
}


AddCommand_response::AddCommand_response(const AddCommand_response& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool AddCommand_response::checkIntegrity(void)
{
  return AddCommand_responseMarshaller::checkIntegrity(*this);
}


AddCommand_response::AddCommand_response(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION),
      info(0)
{
}



bool AddCommand_response::set_success(bool success_)
{
  success=success_;
  return true;
}

bool AddCommand_response::set_resultCode(const Result& resultCode_)
{
  if(!ResultMarshaller::checkIntegrityConst(resultCode_))   return false;
  resultCode=resultCode_;
  return true;
}

bool AddCommand_response::set_info(const std::string& info_)
{
  if(info_.length()>1000)  return false;
  delete info;
  info=0;

  info=new std::string(info_);
  return true;
}

void AddCommand_response::reset_info(void)
{
  if(info)
    delete info;
  info=0;
}




bool AddCommand_response::get_success(void) const
{
  return success;
}

const Result& AddCommand_response::get_resultCode(void) const 
{
  return resultCode;
}

const std::string* AddCommand_response::get_info(void) const 
{
  return info;
}

