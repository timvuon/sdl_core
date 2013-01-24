#include "../include/JSONHandler/ALRPCObjects/V1/SetMediaClockTimer_request.h"
#include "SetMediaClockTimer_requestMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V1/Marshaller.h"
#include "StartTimeMarshaller.h"
#include "UpdateModeMarshaller.h"

#define PROTOCOL_VERSION	1


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	robok0der
*/

using namespace NsAppLinkRPC;
SetMediaClockTimer_request& SetMediaClockTimer_request::operator =(const SetMediaClockTimer_request& c)
{
  startTime= c.startTime ? new StartTime(c.startTime[0]) : 0;
  updateMode= c.updateMode;

  return *this;}


SetMediaClockTimer_request::~SetMediaClockTimer_request(void)
{
  if(startTime)
    delete startTime;
}


SetMediaClockTimer_request::SetMediaClockTimer_request(const SetMediaClockTimer_request& c)
{
  *this=c;
}


bool SetMediaClockTimer_request::checkIntegrity(void)
{
  return SetMediaClockTimer_requestMarshaller::checkIntegrity(*this);
}


SetMediaClockTimer_request::SetMediaClockTimer_request(void) : ALRPCRequest(PROTOCOL_VERSION,Marshaller::METHOD_SETMEDIACLOCKTIMER_REQUEST),
      startTime(0)
{
}



bool SetMediaClockTimer_request::set_startTime(const StartTime& startTime_)
{
  if(!StartTimeMarshaller::checkIntegrityConst(startTime_))   return false;
  delete startTime;
  startTime=0;

  startTime=new StartTime(startTime_);
  return true;
}

void SetMediaClockTimer_request::reset_startTime(void)
{
  if(startTime)
    delete startTime;
  startTime=0;
}

bool SetMediaClockTimer_request::set_updateMode(const UpdateMode& updateMode_)
{
  if(!UpdateModeMarshaller::checkIntegrityConst(updateMode_))   return false;
  updateMode=updateMode_;
  return true;
}




const StartTime* SetMediaClockTimer_request::get_startTime(void) const 
{
  return startTime;
}

const UpdateMode& SetMediaClockTimer_request::get_updateMode(void) const 
{
  return updateMode;
}

