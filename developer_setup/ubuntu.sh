#!/bin/bash

echo "Installing build-essential, git and cmake..."
sudo apt-get install build-essential git cmake

echo "Initializing and updating submodules..."
git submodule update --init

if [ ! -f ./third_party/vcpkg/vcpkg ]; then
  echo "Bootstrapping vcpkg..."
  ./third_party/vcpkg/bootstrap-vcpkg.sh
else
  echo "Found vcpkg executable!"
fi

echo "Installing catch2, entt, sdlog and grpc..."
./third_party/vcpkg/vcpkg install catch2 entt spdlog grpc

echo "Compiling proto files..."
./third_party/vcpkg/packages/protobuf_x64-linux/tools/protobuf/protoc \
  --proto_path=service/proto/ \
  --plugin=protoc-gen-grpc=./third_party/vcpkg/packages/grpc_x64-linux/tools/grpc/grpc_cpp_plugin \
  --grpc_out=service/ \
  --cpp_out=service/ \
  networking.proto

echo "Done!"
