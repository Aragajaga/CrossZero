//---------------------------------------------------------------------------------------
// Server for CrossZero
// Created by GbaLog
// Link on github.com: https://github.com/GbaLog
//---------------------------------------------------------------------------------------
#ifndef SERVER_HPP
#define SERVER_HPP
//---------------------------------------------------------------------------------------
#include <SFML/Network.hpp>
#include <utility>
#include <string>
#include <memory>
#include <deque>
#include <cstdint>
//---------------------------------------------------------------------------------------
#include "server_protocol.hpp"
//---------------------------------------------------------------------------------------
namespace server
{
namespace detail
{
namespace internal
{
//---------------------------------------------------------------------------------------
using ContainerByte = std::deque<uint8_t>;
//---------------------------------------------------------------------------------------
} //internal
//---------------------------------------------------------------------------------------
struct IServerBase
{
  virtual ~IServerBase() {}

  virtual onMessage(const protocol::Message & msg) = 0;
  virtual onDecodeError(const protocol::Error & code) = 0;
};
//---------------------------------------------------------------------------------------
class DecodeBuffer
{
public:
  DecodeBuffer(IServerBase & server);

  void addDataAndTryToDecode(const internal::ContainerByte & data);

private:
  void tryToDecode();

  bool parseBuffer(protocol::Message & msg, protocol::Error & error);

  bool readFirstByte(protocol::Message & msg);
  bool readDirectionByte(protocol::Message & msg);
  void readUserByte(protocol::Message & msg);

  bool makeError(protocol::ErrorCode code, protocol::Error & err);

  internal::ContainerByte buffer_;
  IServerBase & user_;
};
//---------------------------------------------------------------------------------------
template<typename Socket>
class ServerBase : IServerBase
{
  using SocketPtr = std::unique_ptr<Socket>;

public:
  void pushMessage(const internal::ContainerByte & data);

  void pushClient(SocketPtr newClient);

  template<typename ... Args>
  void emplaceClient(Args && ... args);

private:
  virtual onMessage(const protocol::Message & msg) override;
  virtual onDecodeError(const protocol::Error & code) override;

  std::vector<SocketPtr> sockets_;
};
//---------------------------------------------------------------------------------------
} //detail
//---------------------------------------------------------------------------------------
using TcpServer = detail::ServerBase<sf::TcpSocket>;
using UdpServer = detail::ServerBase<sf::UdpSocket>;
//---------------------------------------------------------------------------------------
} //server
//---------------------------------------------------------------------------------------
#endif //SERVER_HPP
//---------------------------------------------------------------------------------------
