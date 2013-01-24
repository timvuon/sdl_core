#ifndef NSRPC2COMMUNICATION_UI_SHOW_INCLUDE
#define NSRPC2COMMUNICATION_UI_SHOW_INCLUDE

#include <string>
#include <vector>
#include "JSONHandler/RPC2Request.h"

#include "../include/JSONHandler/ALRPCObjects/V2/TextAlignment.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Image.h"
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

    class Show : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      Show(const Show& c);
      Show(void);
    
      Show& operator =(const Show&);
    
      virtual ~Show(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::string* get_mainField1(void);
      const std::string* get_mainField2(void);
      const std::string* get_mainField3(void);
      const std::string* get_mainField4(void);
      const NsAppLinkRPCV2::TextAlignment* get_alignment(void);
      const std::string* get_statusBar(void);
      const std::string* get_mediaClock(void);
      const std::string* get_mediaTrack(void);
      const NsAppLinkRPCV2::Image* get_graphic(void);
      const std::vector< NsAppLinkRPCV2::SoftButton>* get_softButtons(void);
      const std::vector< std::string>* get_customPresets(void);
      int get_appId(void);


// setters
/// mainField1 <= 500
      bool set_mainField1(const std::string& mainField1);

      void reset_mainField1(void);

/// mainField2 <= 500
      bool set_mainField2(const std::string& mainField2);

      void reset_mainField2(void);

/// mainField3 <= 500
      bool set_mainField3(const std::string& mainField3);

      void reset_mainField3(void);

/// mainField4 <= 500
      bool set_mainField4(const std::string& mainField4);

      void reset_mainField4(void);

      bool set_alignment(const NsAppLinkRPCV2::TextAlignment& alignment);

      void reset_alignment(void);

/// statusBar <= 500
      bool set_statusBar(const std::string& statusBar);

      void reset_statusBar(void);

/// mediaClock <= 500
      bool set_mediaClock(const std::string& mediaClock);

      void reset_mediaClock(void);

/// mediaTrack <= 500
      bool set_mediaTrack(const std::string& mediaTrack);

      void reset_mediaTrack(void);

      bool set_graphic(const NsAppLinkRPCV2::Image& graphic);

      void reset_graphic(void);

/// 0 <= size <= 8
      bool set_softButtons(const std::vector< NsAppLinkRPCV2::SoftButton>& softButtons);

      void reset_softButtons(void);

/// customPresets[] <= 500 ; 0 <= size <= 6
      bool set_customPresets(const std::vector< std::string>& customPresets);

      void reset_customPresets(void);

      bool set_appId(int appId);


    private:

      friend class ShowMarshaller;

      std::string* mainField1;
      std::string* mainField2;
      std::string* mainField3;
      std::string* mainField4;
      NsAppLinkRPCV2::TextAlignment* alignment;
      std::string* statusBar;
      std::string* mediaClock;
      std::string* mediaTrack;
      NsAppLinkRPCV2::Image* graphic;
      std::vector< NsAppLinkRPCV2::SoftButton>* softButtons;
      std::vector< std::string>* customPresets;
      int appId;

    };
  }
}

#endif
