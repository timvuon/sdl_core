#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/SetAppIcon.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

using namespace NsRPC2Communication::UI;


SetAppIcon& SetAppIcon::operator =(const SetAppIcon& c)
{
  syncFileName=c.syncFileName;
  appId=c.appId;
  return *this;
}


SetAppIcon::~SetAppIcon(void)
{
}


SetAppIcon::SetAppIcon(void) : 
  RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__SETAPPICON)
{
}


SetAppIcon::SetAppIcon(const SetAppIcon& c) : RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__SETAPPICON,c.getId())
{
  *this=c;
}


const std::string& SetAppIcon::get_syncFileName(void)
{
  return syncFileName;
}

bool SetAppIcon::set_syncFileName(const std::string& syncFileName_)
{
  syncFileName=syncFileName_;
  return true;
}

int SetAppIcon::get_appId(void)
{
  return appId;
}

bool SetAppIcon::set_appId(int appId_)
{
  appId=appId_;
  return true;
}

bool SetAppIcon::checkIntegrity(void)
{
  return SetAppIconMarshaller::checkIntegrity(*this);
}
