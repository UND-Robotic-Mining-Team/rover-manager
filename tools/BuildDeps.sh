cd ../deps/pistache
mkdir build
cd build
cmake -G "Unix Makefiles" \
      -DCMAKE_BUILD_TYPE=Release \
      -DPISTACHE_BUILD_EXAMPLES=true \
      -DPISTACHE_BUILD_TESTS=true \
      -DPISTACHE_BUILD_DOCS=false \
      -DPISTACHE_USE_SSL=true \
      -DCMAKE_INSTALL_PREFIX=$PWD/../prefix \
      ../
make -j
make install
