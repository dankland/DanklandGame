#include <grpcpp/grpcpp.h>

#include "networking.h"
#include "service/networking.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;
using service::NetworkingService;
using service::PingRequest;
using service::PingResponse;

namespace networking {

class NetworkingServiceImpl : public NetworkingService::Service {
   public:
    Status Ping(::grpc::ServerContext* context,
                const ::service::PingRequest* request,
                ::service::PingResponse* response) override {
        if (request->message() == "ping") {
            response->set_message("pong");
            return Status::OK;
        } else {
            return Status::CANCELLED;
        }
    }
};

std::unique_ptr<NetworkingService::Service>
NetworkingServiceFactory::get_networking_service() noexcept {
    return std::make_unique<NetworkingServiceImpl>();
}

}  // namespace networking
