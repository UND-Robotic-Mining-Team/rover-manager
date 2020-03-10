#!lua

solution "rover-manager"
   configurations { "Debug", "Release" }

   files {
      "../src/*.cpp",
      "../include/*.h"
   }

   includedirs {
      "../include",
      "../deps/phoenix-example/include",
      "../deps/pistache/include"
   }

   project "rover-manager"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "**.cpp" }
--      prebuildcommands { "./BuildDeps.sh" }

      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
	 libdirs{ "../deps/phoenix-example/lib/x86-64", "../deps/pistache/prefix/lib" }
	 links { "CTRE_Phoenix", "CTRE_PhoenixCCI", "CTRE_PhoenixCanutils", "CTRE_PhoenixPlatformLinuxSocketCan", "pistache", "SDL2", "pthread" }
         targetdir "../build/x86"

      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }
	 linkoptions { "-Bstatic" }
	 libdirs{ "../deps/phoenix-example/lib/jetsontx", "../deps/pistache/prefix/lib" }
	 links { "CTRE_Phoenix", "CTRE_PhoenixCCI", "CTRE_PhoenixCanutils", "CTRE_PhoenixPlatformLinuxSocketCan", "pistache", "SDL2", "pthread" }
         targetdir "../build/jetson"

