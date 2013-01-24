#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/AddSubMenu.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

using namespace NsRPC2Communication::UI;


AddSubMenu& AddSubMenu::operator =(const AddSubMenu& c)
{
  menuId=c.menuId;
  if(position)  delete position;
  position= c.position ? new unsigned int(c.position[0]) : 0;
  menuName=c.menuName;
  appId=c.appId;
  return *this;
}


AddSubMenu::~AddSubMenu(void)
{
  if(position)  delete position;
}


AddSubMenu::AddSubMenu(void) : 
  RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__ADDSUBMENU),
  position(0)
{
}


AddSubMenu::AddSubMenu(const AddSubMenu& c) : RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__ADDSUBMENU,c.getId())
{
  *this=c;
}


unsigned int AddSubMenu::get_menuId(void)
{
  return menuId;
}

bool AddSubMenu::set_menuId(unsigned int menuId_)
{
  menuId=menuId_;
  return true;
}

const unsigned int* AddSubMenu::get_position(void)
{
  return position;
}

bool AddSubMenu::set_position(const unsigned int& position_)
{
  if(position)  delete position;
  position=new unsigned int(position_);
  return true;
}

void AddSubMenu::reset_position(void)
{
  if(position)  delete position;
  position=0;
}

const std::string& AddSubMenu::get_menuName(void)
{
  return menuName;
}

bool AddSubMenu::set_menuName(const std::string& menuName_)
{
  menuName=menuName_;
  return true;
}

int AddSubMenu::get_appId(void)
{
  return appId;
}

bool AddSubMenu::set_appId(int appId_)
{
  appId=appId_;
  return true;
}

bool AddSubMenu::checkIntegrity(void)
{
  return AddSubMenuMarshaller::checkIntegrity(*this);
}
