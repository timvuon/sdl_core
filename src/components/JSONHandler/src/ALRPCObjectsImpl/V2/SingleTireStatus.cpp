#include "../include/JSONHandler/ALRPCObjects/V2/SingleTireStatus.h"
#include "SingleTireStatusMarshaller.h"
#include "SingleTirePressureStatusMarshaller.h"
/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	robok0der
*/



using namespace NsAppLinkRPCV2;

SingleTireStatus::SingleTireStatus(const SingleTireStatus& c)
{
  *this=c;
}


bool SingleTireStatus::checkIntegrity(void)
{
  return SingleTireStatusMarshaller::checkIntegrity(*this);
}


SingleTireStatus::SingleTireStatus(void)
{
}



bool SingleTireStatus::set_pressure(unsigned int pressure_)
{
  if(pressure_>255)  return false;
  pressure=pressure_;
  return true;
}

bool SingleTireStatus::set_status(const SingleTirePressureStatus& status_)
{
  if(!SingleTirePressureStatusMarshaller::checkIntegrityConst(status_))   return false;
  status=status_;
  return true;
}




unsigned int SingleTireStatus::get_pressure(void) const
{
  return pressure;
}


const SingleTirePressureStatus& SingleTireStatus::get_status(void) const 
{
  return status;
}


