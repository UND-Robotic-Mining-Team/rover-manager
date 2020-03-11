#pragma once

#include "pistache/endpoint.h"

namespace und::server
{
  //Pistache stuff
  using namespace Net;

  class RestServer : public Http::Handler
  {
    HTTP_PROTOTYPE(HelloHandler);

    void onRequest(const Http::Request& request, Http::ResponseWriter response)
    {
      response.send(Http::Code::Ok, "Hello, World");
    }

    RestServer(int port)
    {
      //Pistache deals with the evil networking stuff (opts structs) for the most part
      // since we're being simple with just localhost any(), this works decently well
      Net::Address addr(Net::Ipv4::any(), Net::Port(port));
      
      auto opts = Http::Endpoint::options().threads(1);
      Http::Endpoint server(addr);
      server.init(opts);
      server.setHandler(std::make_shared<HelloHandler>());
      server.serve();
    }
    
  }
  
}
