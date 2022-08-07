#/bin/bash

cmake -S . -B . -DCMAKE_BUILD_TYPE=$CORE_MODE
cmake --install . --strip
cmake --build . --config $CORE_MODE
