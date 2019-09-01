rm -rf build &&
  mkdir build &&
  cd build &&
  cmake -DCMAKE_TOOLCHAIN_FILE=third_party/vcpkg/scripts/buildsystems/vcpkg.cmake .. &&
  make
