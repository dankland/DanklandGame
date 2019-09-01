cmake_minimum_required(VERSION 3.12)

# Project
project(dankland-game)

# Find packages
find_package(Catch2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# Base directory relative includes
include_directories(.)

# Flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Tests
enable_testing()
add_test(server_test_build "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target server_test)
add_test(server_test_run game_test)
set_tests_properties(server_test_run PROPERTIES DEPENDS server_test_build)

# Targets
add_executable(
        server
        server/server.cpp
        service/networking.pb.cc
        service/networking.grpc.pb.cc
        service_impl/networking.cpp
)
add_executable(
        server_test
        test/test.cpp
        test/system/movement.cpp
)

# Linked libs
target_link_libraries(server PRIVATE Catch2::Catch2 spdlog::spdlog EnTT gRPC::gpr gRPC::grpc gRPC::grpc++)
target_link_libraries(server_test PRIVATE Catch2::Catch2 spdlog::spdlog EnTT gRPC::gpr gRPC::grpc gRPC::grpc++)
