#/bin/bash

cmake -S . -B . -DCMAKE_BUILD_TYPE=$APP_ENV
cmake --install . --strip
cmake --build . --config $APP_ENV
