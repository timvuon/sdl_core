/*
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_APPLICATION_MANAGER_INCLUDE_APPLICATION_MANAGER_COMMANDS_HMI_GET_SYSTEM_INFO_RESPONSE_H_
#define SRC_COMPONENTS_APPLICATION_MANAGER_INCLUDE_APPLICATION_MANAGER_COMMANDS_HMI_GET_SYSTEM_INFO_RESPONSE_H_

#include "application_manager/commands/hmi/response_from_hmi.h"
#include "application_manager/application_manager.h"

namespace application_manager {

namespace commands {

struct SystemInfo {
  std::string ccpu_version;
  std::string wers_country_code;
  std::string language;
};

/**
 * @brief GetSystemInfoResponse command class
 **/
class GetSystemInfoResponse : public ResponseFromHMI {
 public:
  /**
   * @brief GetSystemInfoResponse class constructor
   *
   * @param message Incoming SmartObject message
   **/
  GetSystemInfoResponse(const MessageSharedPtr& message,
                        ApplicationManager& application_manager);

  /**
   * @brief GetSystemInfoResponse class destructor
   **/
  virtual ~GetSystemInfoResponse();

  /**
   * @brief Execute command
   **/
  virtual void Run();

 private:
  const SystemInfo GetSystemInfo(
      const hmi_apis::Common_Result::eType code) const;

  DISALLOW_COPY_AND_ASSIGN(GetSystemInfoResponse);
};

}  // namespace commands

}  // namespace application_manager

#endif  // SRC_COMPONENTS_APPLICATION_MANAGER_INCLUDE_APPLICATION_MANAGER_COMMANDS_HMI_GET_SYSTEM_INFO_RESPONSE_H_
