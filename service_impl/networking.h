#ifndef DANKLAND_SERVICE_IMPL_NETWORKING_H
#define DANKLAND_SERVICE_IMPL_NETWORKING_H

#include "service/networking.grpc.pb.h"

namespace networking {

class NetworkingServiceFactory {
   public:
    [[nodiscard]] static std::unique_ptr<service::NetworkingService::Service>
    get_networking_service() noexcept;
};

}  // namespace networking

#endif  // DANKLAND_SERVICE_IMPL_NETWORKING_H
