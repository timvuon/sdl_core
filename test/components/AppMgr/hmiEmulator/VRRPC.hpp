/**
 * \file VRRPC.hpp
 * \brief MessageBroker Controller VRRPC.
 * \author AKara
 */
#pragma once

#include <iostream>

#include "RPC.h"

/**
 * \namespace NsHMIEmulator
 * \brief HMIEmulator related functions.
 */ 
namespace NsHMIEmulator
{
  /**
  * \class VRRPC
  * \brief MessageBroker Controller.
  */

  class VRRPC : public RPC
  {
  public:
    /**
    * \brief Constructor.
    * \param address remote network address or FQDN
    * \param port remote local port
    */
    VRRPC(const std::string& address, unsigned short port);

    /**
    * \brief Destructor.
    */
    virtual ~VRRPC();

    /**
    * \brief process request.
    * \param root JSON message.
    */
    virtual void processRequest(Json::Value& root);

    /**
    * \brief process notification.
    * \param root JSON message.
    */
    virtual void processNotification(Json::Value& root);

    /**
    * \brief process response.
    * \param method method name which has been called.
    * \param root JSON message.
    */
    virtual void processResponse(std::string method, Json::Value& root);

    /**
     * \brief Callback function which is called upon a new message from mobile side arrival
     * \param command RPC2Bus Json message
     */
    virtual void messageReceivedFromDeviceCallback(NsRPC2Communication::RPC2Command * msg );
  };
}/* namespace NsHMIEmulator */
