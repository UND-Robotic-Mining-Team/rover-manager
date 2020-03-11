#include "RobotMain.h"
#include "rest-server.h"

#include <chrono>
#include <thread>

using und::server::RestServer;

bool isRunning = true;

int main(int argc, char* argv[])
{
  // initialize motors and physical layer
  RobotMain::initMotors();

  // create rest server/api on port 9080
  RestServer myServer(9080);

  // keep running until server shuts down or crashes
  while(isRunning)
    {
      std::this_thread::sleep_for(std::chrono::seconds(5));
      if(myServer.failed())
	isRunning = false;
      else
	myServer.resetPriority();
    }
  return 0;
}
