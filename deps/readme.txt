The folders here may be managed by Git subtree. If you don't know what that means, see https://github.com/BenMueller/Idiots#dependencies for a foolproof explanation.

basic tutorial to update to the newer upstream:
cd to top folder
run "git remote add -f phoenix-api-github https://github.com/CrossTheRoadElec/Phoenix-api.git"
"git fetch phoenix-api-github master"
"git subtree pull --prefix deps/phoenix-api phoenix-api-github master --squash"


Upstream URLs:
https://github.com/CrossTheRoadElec/Phoenix-api
