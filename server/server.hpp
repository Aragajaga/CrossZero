//---------------------------------------------------------------------------------------
// Server for CrossZero
// Created by GbaLog
// Link on github.com: https://github.com/GbaLog
//---------------------------------------------------------------------------------------
// TODO:
// - add listener
// - add messages handler
// - add errors handler
//---------------------------------------------------------------------------------------
#ifndef SERVER_HPP
#define SERVER_HPP
//---------------------------------------------------------------------------------------
#include <SFML/Network.hpp>
#include <memory>
#include <deque>
#include <cstdint>
//---------------------------------------------------------------------------------------
#include "detail/server_protocol.hpp"
#include "detail/server_interfaces.hpp"
#include "detail/message_decoder.hpp"
#include "detail/socket_container.hpp"
#include "common_data.hpp"
//---------------------------------------------------------------------------------------
namespace server
{
//---------------------------------------------------------------------------------------
using TcpSocketContainer = detail::SocketContainer<sf::TcpSocket>;
using UdpSocketContainer = detail::SocketContainer<sf::UdpSocket>;
//---------------------------------------------------------------------------------------
} //server
//---------------------------------------------------------------------------------------
#endif //SERVER_HPP
//---------------------------------------------------------------------------------------
