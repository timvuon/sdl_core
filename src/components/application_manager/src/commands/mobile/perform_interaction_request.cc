/*

 Copyright (c) 2013, Ford Motor Company
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the
 distribution.

 Neither the name of the Ford Motor Company nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#include <string>
#include "application_manager/commands/mobile/perform_interaction_request.h"
#include "application_manager/application_manager_impl.h"
#include "application_manager/application_impl.h"
#include "application_manager/message_helper.h"
#include "interfaces/MOBILE_API.h"
#include "interfaces/HMI_API.h"

namespace application_manager {

namespace commands {

PerformInteractionRequest::PerformInteractionRequest(
    const MessageSharedPtr& message): CommandRequestImpl(message) {
}

PerformInteractionRequest::~PerformInteractionRequest() {
}

void PerformInteractionRequest::Run() {
  LOG4CXX_INFO(logger_, "PerformInteractionRequest::Run");

  ApplicationImpl* app = static_cast<ApplicationImpl*>(
      ApplicationManagerImpl::instance()->
      application((*message_)[strings::params][strings::connection_key]));

  if (NULL == app) {
    SendResponse(false, mobile_apis::Result::APPLICATION_NOT_REGISTERED);
    LOG4CXX_ERROR(logger_, "Application is not registered");
    return;
  }

  smart_objects::CSmartObject& choice_list =
      (*message_)[strings::msg_params][strings::interaction_choice_set_id_list];

  for (size_t i = 0; i < choice_list.length(); ++i) {
    if (!app->FindChoiceSet(choice_list[i].asInt())) {
      SendResponse(false, mobile_apis::Result::INVALID_ID);
      LOG4CXX_ERROR(logger_, "Invalid ID");
      return;
    }
  }

  if ((true == SendVRAddCommandRequest(app)) &&
      (true == SendUIPerforminterActionRequest(app))) {
    app->set_perform_interaction_active(true);
  }
}

bool PerformInteractionRequest::SendVRAddCommandRequest(
    const ApplicationImpl* app) {

  smart_objects::CSmartObject& choice_list =
  (*message_)[strings::msg_params][strings::interaction_choice_set_id_list];

  for (size_t i = 0; i < choice_list.length(); ++i) {
    // choice_set contains SmartObject msg_params
    smart_objects::CSmartObject* i_choice_set =
        app->FindChoiceSetVRCommands(choice_list[i].asInt());

    for (size_t j = 0; j < choice_list.length(); ++j) {
      smart_objects::CSmartObject* j_choice_set =
          app->FindChoiceSetVRCommands(choice_list[j].asInt());

      if ((!i_choice_set) || (!j_choice_set)) {
        SendResponse(false, mobile_apis::Result::INVALID_ID);
        LOG4CXX_ERROR(logger_, "Invalid ID");
        return false;
      }

      // choice_set pointer contains SmartObject msg_params
      smart_objects::CSmartObject& i_vr_commands =
          (*i_choice_set)[strings::choice_set][strings::vr_commands];

      smart_objects::CSmartObject& j_vr_commands =
          (*j_choice_set)[strings::choice_set][strings::vr_commands];

      for (size_t ii = 0; ii < i_vr_commands.length(); ++ii) {
        for (size_t jj = 0; jj < j_vr_commands.length(); ++jj) {
          if (i_vr_commands[ii].asString() == j_vr_commands[jj].asString()) {
            SendResponse(false, mobile_apis::Result::DUPLICATE_NAME);
            return false;
          }
        }
      }
    }
  }

  for (size_t i = 0; i < choice_list.length(); ++i) {

    smart_objects::CSmartObject* choice_set =
        app->FindChoiceSetVRCommands(choice_list[i].asInt());

    if (!choice_set) {
      SendResponse(false, mobile_apis::Result::INVALID_ID);
      LOG4CXX_ERROR(logger_, "Invalid ID");
      return false;
    }

    smart_objects::CSmartObject msg_params =
        smart_objects::CSmartObject(smart_objects::SmartType_Map);
    msg_params[strings::app_id] = app->app_id();
    msg_params[strings::cmd_id] =
        (*choice_set)[strings::choice_set][strings::choice_id];
    msg_params[strings::vr_commands] =
        smart_objects::CSmartObject(smart_objects::SmartType_Array);
    msg_params[strings::vr_commands] =
        (*choice_set)[strings::choice_set][strings::vr_commands];

    CreateHMIRequest(hmi_apis::FunctionID::VR_AddCommand, msg_params, false);
  }

  return true;
}

bool PerformInteractionRequest::SendUIPerforminterActionRequest(
    const ApplicationImpl* app) {

  smart_objects::CSmartObject& choice_list =
    (*message_)[strings::msg_params][strings::interaction_choice_set_id_list];

    for (size_t i = 0; i < choice_list.length(); ++i) {
      // choice_set contains SmartObject msg_params
      smart_objects::CSmartObject* i_choice_set =
          app->FindChoiceSetVRCommands(choice_list[i].asInt());

      for (size_t j = 0; j < choice_list.length(); ++j) {
        smart_objects::CSmartObject* j_choice_set =
            app->FindChoiceSetVRCommands(choice_list[j].asInt());

        if ((!i_choice_set) || (!j_choice_set)) {
          SendResponse(false, mobile_apis::Result::INVALID_ID);
          LOG4CXX_ERROR(logger_, "Invalid ID");
          return false;
        }

        std::string i_menu_name=
            (*i_choice_set)[strings::choice_set][strings::menu_name].asString();
        std::string j_menu_name=
            (*j_choice_set)[strings::choice_set][strings::menu_name].asString();

        if (i_menu_name == j_menu_name) {
          SendResponse(false, mobile_apis::Result::DUPLICATE_NAME);
          return false;
        }
      }
    }

  smart_objects::CSmartObject msg_params =
      smart_objects::CSmartObject(smart_objects::SmartType_Map);

  msg_params[hmi_request::initial_text][hmi_request::field_name] =
      TextFieldName::INITIAL_INTERACTION_TEXT;
  msg_params[hmi_request::initial_text][hmi_request::field_text] =
      (*message_)[strings::msg_params][hmi_request::initial_text];
    msg_params[strings::interaction_choice_set_id_list] = choice_list;
  msg_params[strings::timeout] =
      (*message_)[strings::msg_params][strings::timeout];
  msg_params[strings::app_id] = app->app_id();

  CreateHMIRequest(hmi_apis::FunctionID::UI_PerformInteraction,
                   msg_params, true);
  return true;
}

}  // namespace commands

}  // namespace application_manager
