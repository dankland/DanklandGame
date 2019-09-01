#include <grpcpp/grpcpp.h>
#include <spdlog/spdlog.h>

#include "service_impl/networking.h"

using grpc::Server;
using grpc::ServerBuilder;
using networking::NetworkingServiceFactory;
using service::NetworkingService;

int main() {
    std::string listen_address("0.0.0.0:54321");
    auto service = NetworkingServiceFactory::get_networking_service();

    ServerBuilder builder{};
    std::unique_ptr<Server> server =
        builder.AddListeningPort(listen_address, grpc::InsecureServerCredentials())
            .RegisterService(service.get())
            .BuildAndStart();

    spdlog::info("Server started! Listening on {}", listen_address);
    server->Wait();
    return 0;
}
