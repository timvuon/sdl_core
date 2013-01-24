#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/PerformAudioPassThru.h"
#include "../src/ALRPCObjectsImpl/V2/TTSChunkMarshaller.h"
#include "../src/ALRPCObjectsImpl/V2/SamplingRateMarshaller.h"
#include "../src/ALRPCObjectsImpl/V2/AudioCaptureQualityMarshaller.h"
#include "../src/ALRPCObjectsImpl/V2/AudioTypeMarshaller.h"
#include "../src/ALRPCObjectsImpl/V2/ResultMarshaller.h"
#include "../src/../src/RPC2ObjectsImpl//NsRPC2Communication/UI/PerformAudioPassThruMarshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

using namespace NsRPC2Communication::UI;

bool PerformAudioPassThruMarshaller::checkIntegrity(PerformAudioPassThru& s)
{
  return checkIntegrityConst(s);
}


bool PerformAudioPassThruMarshaller::fromString(const std::string& s,PerformAudioPassThru& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string PerformAudioPassThruMarshaller::toString(const PerformAudioPassThru& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool PerformAudioPassThruMarshaller::checkIntegrityConst(const PerformAudioPassThru& s)
{
  {
    unsigned int i=s.initialPrompt.size();
    if(i<1)  return false;
    if(i>100)  return false;
  }

  if(s.audioPassThruDisplayText1 && (s.audioPassThruDisplayText1[0].length()>500))  return false;

  if(s.audioPassThruDisplayText2 && (s.audioPassThruDisplayText2[0].length()>500))  return false;

  if(!NsAppLinkRPCV2::SamplingRateMarshaller::checkIntegrityConst(s.samplingRate))  return false;

  if(s.maxDuration>1000000)  return false;

  if(!NsAppLinkRPCV2::AudioCaptureQualityMarshaller::checkIntegrityConst(s.bitsPerSample))  return false;

  if(!NsAppLinkRPCV2::AudioTypeMarshaller::checkIntegrityConst(s.audioType))  return false;

  return true;
}


Json::Value PerformAudioPassThruMarshaller::toJSON(const PerformAudioPassThru& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["jsonrpc"]=Json::Value("2.0");
  json["method"]=Json::Value("UI.PerformAudioPassThru");

  json["id"]=Json::Value(e.getId());
  json["params"]=Json::Value(Json::objectValue);
  {
    unsigned int i=e.initialPrompt.size();
    Json::Value j=Json::Value(Json::arrayValue);
    j.resize(i);
    while(i--)
      j[i]=NsAppLinkRPCV2::TTSChunkMarshaller::toJSON(e.initialPrompt[i]);

    json["params"]["initialPrompt"]=j;
  }
  if(e.audioPassThruDisplayText1)
    json["params"]["audioPassThruDisplayText1"]=Json::Value(e.audioPassThruDisplayText1[0]);;
  if(e.audioPassThruDisplayText2)
    json["params"]["audioPassThruDisplayText2"]=Json::Value(e.audioPassThruDisplayText2[0]);;
  json["params"]["samplingRate"]=NsAppLinkRPCV2::SamplingRateMarshaller::toJSON(e.samplingRate);;
  json["params"]["maxDuration"]=Json::Value(e.maxDuration);;
  json["params"]["bitsPerSample"]=NsAppLinkRPCV2::AudioCaptureQualityMarshaller::toJSON(e.bitsPerSample);;
  json["params"]["audioType"]=NsAppLinkRPCV2::AudioTypeMarshaller::toJSON(e.audioType);;
  json["params"]["appId"]=Json::Value(e.appId);;
  return json;
}


bool PerformAudioPassThruMarshaller::fromJSON(const Json::Value& json,PerformAudioPassThru& c)
{
  try
  {
    if(!json.isObject())  return false;
    if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return false;
    if(!json.isMember("method") || !json["method"].isString() || json["method"].asString().compare("UI.PerformAudioPassThru"))  return false;
    if(!json.isMember("id") || !json["id"].isInt()) return false;
    c.setId(json["id"].asInt());

    if(!json.isMember("params")) return false;

    Json::Value js=json["params"];
    if(!js.isObject())  return false;
    if(!js.isMember("initialPrompt") || !js["initialPrompt"].isArray())  return false;
    {
      unsigned int i=js["initialPrompt"].size();
      if(i<1)  return false;
      if(i>100)  return false;
      c.initialPrompt.resize(i);
      while(i--)
      {
        NsAppLinkRPCV2::TTSChunk t;
        if(!NsAppLinkRPCV2::TTSChunkMarshaller::fromJSON(js["initialPrompt"][i],t))
          return false;
         c.initialPrompt[i]=t;
      }
    }

    if(c.audioPassThruDisplayText1)  delete c.audioPassThruDisplayText1;
    c.audioPassThruDisplayText1=0;
    if(js.isMember("audioPassThruDisplayText1"))
    {
      if(!js["audioPassThruDisplayText1"].isString())  return false;
      c.audioPassThruDisplayText1=new std::string();
      c.audioPassThruDisplayText1[0]=js["audioPassThruDisplayText1"].asString();
      if(c.audioPassThruDisplayText1[0].length()>500)  return false;

    }

    if(c.audioPassThruDisplayText2)  delete c.audioPassThruDisplayText2;
    c.audioPassThruDisplayText2=0;
    if(js.isMember("audioPassThruDisplayText2"))
    {
      if(!js["audioPassThruDisplayText2"].isString())  return false;
      c.audioPassThruDisplayText2=new std::string();
      c.audioPassThruDisplayText2[0]=js["audioPassThruDisplayText2"].asString();
      if(c.audioPassThruDisplayText2[0].length()>500)  return false;

    }

    if(!js.isMember("samplingRate") || !NsAppLinkRPCV2::SamplingRateMarshaller::fromJSON(js["samplingRate"],c.samplingRate))  return false;

    if(!js.isMember("maxDuration") || !js["maxDuration"].isInt())  return false;
    c.maxDuration=js["maxDuration"].asInt();
    if(c.maxDuration>1000000)  return false;

    if(!js.isMember("bitsPerSample") || !NsAppLinkRPCV2::AudioCaptureQualityMarshaller::fromJSON(js["bitsPerSample"],c.bitsPerSample))  return false;

    if(!js.isMember("audioType") || !NsAppLinkRPCV2::AudioTypeMarshaller::fromJSON(js["audioType"],c.audioType))  return false;

    if(!js.isMember("appId") || !js["appId"].isInt())  return false;
    c.appId=js["appId"].asInt();
    
  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}
