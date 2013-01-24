#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/AppLinkCore/OnAppDeactivated.h"
#include "../src/../include/JSONHandler/RPC2Objects//Marshaller.h"

/*
  interface	NsRPC2Communication::AppLinkCore
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

using namespace NsRPC2Communication::AppLinkCore;


OnAppDeactivated& OnAppDeactivated::operator =(const OnAppDeactivated& c)
{
  appName=c.appName;
  reason=c.reason;
  appId=c.appId;
  return *this;
}


OnAppDeactivated::~OnAppDeactivated(void)
{
}


OnAppDeactivated::OnAppDeactivated(void) : 
  RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_APPLINKCORE__ONAPPDEACTIVATED)
{
}


OnAppDeactivated::OnAppDeactivated(const OnAppDeactivated& c) : RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_APPLINKCORE__ONAPPDEACTIVATED,c.getId())
{
  *this=c;
}


const std::string& OnAppDeactivated::get_appName(void)
{
  return appName;
}

bool OnAppDeactivated::set_appName(const std::string& appName_)
{
  appName=appName_;
  return true;
}

const NsAppLinkRPCV2::DeactivateReason& OnAppDeactivated::get_reason(void)
{
  return reason;
}

bool OnAppDeactivated::set_reason(const NsAppLinkRPCV2::DeactivateReason& reason_)
{
  reason=reason_;
  return true;
}

int OnAppDeactivated::get_appId(void)
{
  return appId;
}

bool OnAppDeactivated::set_appId(int appId_)
{
  appId=appId_;
  return true;
}

bool OnAppDeactivated::checkIntegrity(void)
{
  return OnAppDeactivatedMarshaller::checkIntegrity(*this);
}
