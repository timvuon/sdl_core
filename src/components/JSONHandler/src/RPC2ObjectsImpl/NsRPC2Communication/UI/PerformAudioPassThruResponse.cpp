#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/PerformAudioPassThruResponse.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

using namespace NsRPC2Communication::UI;


PerformAudioPassThruResponse& PerformAudioPassThruResponse::operator =(const PerformAudioPassThruResponse& c)
{
  return *this;
}


PerformAudioPassThruResponse::~PerformAudioPassThruResponse(void)
{
}


PerformAudioPassThruResponse::PerformAudioPassThruResponse(void) : 
  RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__PERFORMAUDIOPASSTHRURESPONSE)
{
}


PerformAudioPassThruResponse::PerformAudioPassThruResponse(const PerformAudioPassThruResponse& c) : RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__PERFORMAUDIOPASSTHRURESPONSE,c.getId(),c.getResult())
{
  *this=c;
}


bool PerformAudioPassThruResponse::checkIntegrity(void)
{
  return PerformAudioPassThruResponseMarshaller::checkIntegrity(*this);
}
