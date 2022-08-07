#/bin/bash

if [ "$CORE_MODE" = "release" ]; then

  cmake -S . -B . -DCMAKE_BUILD_TYPE=Release
  cmake --install . --strip
  cmake --build . --config Release

elif [ "$CORE_MODE" = "debug" ]; then

  cmake -S . -B . -DCMAKE_BUILD_TYPE=Debug
  cmake --install . --strip
  cmake --build . --config Debug

fi
