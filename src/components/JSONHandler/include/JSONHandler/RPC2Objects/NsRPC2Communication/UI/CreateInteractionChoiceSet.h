#ifndef NSRPC2COMMUNICATION_UI_CREATEINTERACTIONCHOICESET_INCLUDE
#define NSRPC2COMMUNICATION_UI_CREATEINTERACTIONCHOICESET_INCLUDE

#include <vector>
#include "JSONHandler/RPC2Request.h"

#include "../include/JSONHandler/ALRPCObjects/V2/Choice.h"

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

    class CreateInteractionChoiceSet : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      CreateInteractionChoiceSet(const CreateInteractionChoiceSet& c);
      CreateInteractionChoiceSet(void);
    
      CreateInteractionChoiceSet& operator =(const CreateInteractionChoiceSet&);
    
      virtual ~CreateInteractionChoiceSet(void);
    
      bool checkIntegrity(void);
    
// getters
      unsigned int get_interactionChoiceSetID(void);

      const std::vector< NsAppLinkRPCV2::Choice>& get_choiceSet(void);

      int get_appId(void);


// setters
/// interactionChoiceSetID <= 2000000000
      bool set_interactionChoiceSetID(unsigned int interactionChoiceSetID);

/// 1 <= size <= 100
      bool set_choiceSet(const std::vector< NsAppLinkRPCV2::Choice>& choiceSet);

      bool set_appId(int appId);


    private:

      friend class CreateInteractionChoiceSetMarshaller;

      unsigned int interactionChoiceSetID;
      std::vector< NsAppLinkRPCV2::Choice> choiceSet;
      int appId;

    };
  }
}

#endif
