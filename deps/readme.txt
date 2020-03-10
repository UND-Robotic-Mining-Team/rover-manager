The folders here may be managed by Git subtree. If you don't know what that means, see https://github.com/BenMueller/Idiots#dependencies for an explanation.

basic tutorial to update to the newer upstream:
cd to top folder
run "git remote add -f phoenix-api-github https://github.com/CrossTheRoadElec/Phoenix-api.git"
"git fetch phoenix-api-github master"
"git subtree pull --prefix deps/phoenix-api phoenix-api-github master --squash"


Upstream URLs:
The important ones:
https://github.com/CrossTheRoadElec/Phoenix-Linux-SocketCAN-Example
https://github.com/oktal/pistache

Ones which may be useful in understanding/future (i.e. upstream) use:
https://github.com/CrossTheRoadElec/Phoenix-api
https://github.com/wpilibsuite/allwpilib
Phoenix-api-release: https://github.com/CrossTheRoadElec/Phoenix-Releases/releases/tag/v5.17.6


Phoenix-headers had to be manually copied from the phoenix-api build artefacts. It seems it's included in a "core-<version>-headers.zip" file and unpacked at build time. Mainly, things like ErrorCode.h are included in this. Remember to update these files from updated phonenix-api releases from time to time (you can find them by searching for ErrorCode.h)

If you get build errors about SDL2, make sure libsdl2-dev is installed.

*** IMPORTANT ***
Currently, building Phoenix-api doesn't work from upstream git repo. As such, phoenix-api-release is thus the best place to get build artefacts/objects, under the following folder:

phoenix-api-release/maven/com/ctre/phoenix/api-cpp/<version>

In that folder, you can find libCTRE build objects inside ZIP files. From this, copy the debug and ordinary build file into deps/phoenix-api-release/libs/x86 (or armhf if on jetson)/<debug or release>
