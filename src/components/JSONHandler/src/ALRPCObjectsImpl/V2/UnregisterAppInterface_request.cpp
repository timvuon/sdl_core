#include "../include/JSONHandler/ALRPCObjects/V2/UnregisterAppInterface_request.h"
#include "UnregisterAppInterface_requestMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Marshaller.h"

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

UnregisterAppInterface_request::~UnregisterAppInterface_request(void)
{
}


UnregisterAppInterface_request::UnregisterAppInterface_request(const UnregisterAppInterface_request& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool UnregisterAppInterface_request::checkIntegrity(void)
{
  return UnregisterAppInterface_requestMarshaller::checkIntegrity(*this);
}


UnregisterAppInterface_request::UnregisterAppInterface_request(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION)
{
}






