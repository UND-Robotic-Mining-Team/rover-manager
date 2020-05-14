#pragma once

//TODO: some of this could be moved into a cpp class, leaving the method stubs here. Do that at some point.

#include "pistache/endpoint.h"
#include "RobotMain.h"

#include <atomic>

namespace und::server
{
  //Pistache stuff
  using namespace Net;

  class RestServer : public Http::Handler
  {
    Rest::Router router;
    Rest::Description desc;
    std::shared_ptr<Http::Endpoint> server;

    std::atomic<int> currentPriority = 5;

    RobotMain::instructions()

    // TODO: write this to shutdown the REST server and clean everything up.
    void shutdown()
    {
      
    }

    void resetPriority()
    {
      currentPriority = 5;
    }

    void onRequest(const Http::Request& request, Http::ResponseWriter response)
    {
      response.send(Http::Code::Ok, "Hello, World");
    }

    RestServer(int port)
    {
      //first initialize the description
      desc.info().license("Apache", "http://www.apache.org/licenses/LICENSE-2.0");
      auto backendErrorResponse = desc.response(Http::Code::Internal_Server_Error, "An error occured with the backend");
      desc.schemes(Rest::Scheme::Http).basePath("/v1").produces(MIME(Application, Json)).consumes(MIME(Application, Json));
      desc.route(desc.get("/ready")).bind(&Generic::handleReady).response(Http::Code::Ok, "Response to the /ready call").hide();
      auto versionPath = desc.path("/v1");

      // Ok, here it gets interesting. Controller becomes a callback function, based on the .route parameters.
      // first we define the URL path
      auto controller = versionPath.path("/controller");
      // now the subdomain names. TODO: finish this function
      controller.route(desc.get("/:speed/:direction/:priority"), "Give robot a command").bind(&RestServer::robotCommand, this).produces(MIME(Application, Json)).parameter<Rest::Type::String>("speed", "direction", "priority", "The path on which we want the rover to move")
            .response(Http::Code::Ok, "Rover Command Accepted!")
            .response(backendErrorResponse);

      //replicate the above config for post commands, just in case. TODO.
      /*
        accountsPath
            .route(desc.post("/:speed/:direction/:priority"), "Give robot a command")
            .bind(&BankerService::createAccount, this)
            .produces(MIME(Application, Json))
            .consumes(MIME(Application, Json))
            .parameter<Rest::Type::String>("name", "The name of the account to create")
            .response(Http::Code::Ok, "The initial state of the account")
            .response(backendErrorResponse);
      */
      
      //Pistache deals with the evil networking stuff (opts structs) for the most part
      // since we're being simple with just localhost any(), this works decently well
      Net::Address addr(Net::Ipv4::any(), Net::Port(port));
      
      auto opts = Http::Endpoint::options().threads(1);
      Http::Endpoint server(addr);
      server.init(opts);
      server.serve();
    }

    void robotCommand(const Rest::Request& request, Http::ResponseWriter response)
    {
      auto speed = request.param(":speed").as<std::string>();
      auto direction = request.param(":direction").as<std::string>();
      auto priority = request.param(":priority").as<std::string>();

      if(priority == 0) // system command for shutdown
	{
	  shutdown();
	}
      else if(priority == currentPriority)
	{
	  RobotMain::drive({speed, direction});
	}
      else if(priority < currentPriority)
	{
	  currentPriority = priority;
	  RobotMain::drive({speed, direction});
	}
    }
    
  }
  
}
