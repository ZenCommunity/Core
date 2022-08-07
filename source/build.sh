#/bin/bash

cmake -S . -B . -DCMAKE_BUILD_TYPE=$APP_MODE
cmake --install . --strip
cmake --build . --config $APP_MODE
