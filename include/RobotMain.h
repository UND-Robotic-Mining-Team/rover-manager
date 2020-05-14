#pragma once;

#define Phoenix_No_WPI // remove WPI dependencies
#include <ctre/Phoenix.h>
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include "pistache/endpoint.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>

namespace RobotMain
{
  struct status
  {
    int lfSpeed; // Left front
    int rfSpeed; // right front
    int lbSpeed;
    int rbSpeed;
  };

  struct instructions
  {
    int targetSpeed; // units to be decided
    int targetDir; // degrees
  };
  
  status drive(instructions);
  void sleepApp(int ms);
  void initMotors();
  
}
