#ifndef NSRPC2COMMUNICATION_UI_ALERT_INCLUDE
#define NSRPC2COMMUNICATION_UI_ALERT_INCLUDE

#include <string>
#include <vector>
#include "JSONHandler/RPC2Request.h"

#include "../include/JSONHandler/ALRPCObjects/V2/TTSChunk.h"
#include "../include/JSONHandler/ALRPCObjects/V2/SoftButton.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace UI
  {

    class Alert : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      Alert(const Alert& c);
      Alert(void);
    
      Alert& operator =(const Alert&);
    
      virtual ~Alert(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::string* get_AlertText1(void);
      const std::string* get_AlertText2(void);
      const std::string* get_AlertText3(void);
      const std::vector< NsAppLinkRPCV2::TTSChunk>* get_ttsChunks(void);
      const unsigned int* get_duration(void);
      const bool* get_playTone(void);
      const std::vector< NsAppLinkRPCV2::SoftButton>* get_softButtons(void);
      int get_appId(void);


// setters
/// AlertText1 <= 500
      bool set_AlertText1(const std::string& AlertText1);

      void reset_AlertText1(void);

/// AlertText2 <= 500
      bool set_AlertText2(const std::string& AlertText2);

      void reset_AlertText2(void);

/// AlertText3 <= 500
      bool set_AlertText3(const std::string& AlertText3);

      void reset_AlertText3(void);

/// 1 <= size <= 100
      bool set_ttsChunks(const std::vector< NsAppLinkRPCV2::TTSChunk>& ttsChunks);

      void reset_ttsChunks(void);

/// 3000 <= duration <= 10000
      bool set_duration(const unsigned int& duration);

      void reset_duration(void);

      bool set_playTone(const bool& playTone);

      void reset_playTone(void);

/// 0 <= size <= 4
      bool set_softButtons(const std::vector< NsAppLinkRPCV2::SoftButton>& softButtons);

      void reset_softButtons(void);

      bool set_appId(int appId);


    private:

      friend class AlertMarshaller;

      std::string* AlertText1;
      std::string* AlertText2;
      std::string* AlertText3;
      std::vector< NsAppLinkRPCV2::TTSChunk>* ttsChunks;
      unsigned int* duration;
      bool* playTone;
      std::vector< NsAppLinkRPCV2::SoftButton>* softButtons;
      int appId;

    };
  }
}

#endif
