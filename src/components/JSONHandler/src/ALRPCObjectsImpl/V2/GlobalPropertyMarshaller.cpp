#include <cstring>
#include "../include/JSONHandler/ALRPCObjects/V2/GlobalProperty.h"
#include "GlobalPropertyMarshaller.h"
#include "GlobalPropertyMarshaller.inc"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	robok0der
*/

using namespace NsAppLinkRPCV2;


const GlobalProperty::GlobalPropertyInternal GlobalPropertyMarshaller::getIndex(const char* s)
{
  if(!s)
    return GlobalProperty::INVALID_ENUM;
  const struct PerfectHashTable* p=GlobalProperty_intHash::getPointer(s,strlen(s));
  return p ? static_cast<GlobalProperty::GlobalPropertyInternal>(p->idx) : GlobalProperty::INVALID_ENUM;
}


bool GlobalPropertyMarshaller::fromJSON(const Json::Value& s,GlobalProperty& e)
{
  e.mInternal=GlobalProperty::INVALID_ENUM;
  if(!s.isString())
    return false;

  e.mInternal=getIndex(s.asString().c_str());
  return (e.mInternal!=GlobalProperty::INVALID_ENUM);
}


Json::Value GlobalPropertyMarshaller::toJSON(const GlobalProperty& e)
{
  if(e.mInternal==GlobalProperty::INVALID_ENUM) 
    return Json::Value(Json::nullValue);
  const char* s=getName(e.mInternal);
  return s ? Json::Value(s) : Json::Value(Json::nullValue);
}


bool GlobalPropertyMarshaller::fromString(const std::string& s,GlobalProperty& e)
{
  e.mInternal=GlobalProperty::INVALID_ENUM;
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(fromJSON(json,e))  return true;
  }
  catch(...)
  {
    return false;
  }
  return false;
}

const std::string GlobalPropertyMarshaller::toString(const GlobalProperty& e)
{
  Json::FastWriter writer;
  return e.mInternal==GlobalProperty::INVALID_ENUM ? "" : writer.write(toJSON(e));

}

const PerfectHashTable GlobalPropertyMarshaller::mHashTable[4]=
{
  {"HELPPROMPT",0},
  {"TIMEOUTPROMPT",1},
  {"VRHELPTITLE",2},
  {"VRHELPITEMS",3}
};
