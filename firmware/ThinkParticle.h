#ifndef __THINK_PARTICLE_H_
#define __THINK_PARTICLE_H_

#include "WebServer.h"
#include "spark_wiring_timer.h"

class ThinkDevice: public WebServer
{
public:
  typedef void ThinkCallback(String name, String value);

  ThinkDevice(String deviceName, String deviceTypeUuid, ThinkCallback *thinkCallback);
  void                  report(String name, String value);
  void                  process();
  bool                  connected();

protected:
  TCPClient             m_client;
  bool                  m_started;
  bool                  m_connected;
  static ThinkDevice    *s_thinkDevice;
  ThinkCallback         *m_thinkCallback;
  String                m_deviceId;
  String                m_deviceName;
  String                m_deviceTypeUuid;
  String                m_directUrl;
  String                m_hubIp;
  int                   m_hubPort;
  Timer                 m_timer;

  static String         httpEncode(String s);
  
  void                  handleParams(String name, String value);
  
  static void           sWebCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
  void                  webCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);

  static void           sWebLink(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
  void                  webLink(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
  
  void                  request(String hostName, int port, String path, String method);
  void                  patch(String path, String name, String value);
  String                directUrl();
  String                deviceConf();
};


#endif
