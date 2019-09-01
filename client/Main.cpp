#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>
#include <exception>
#include <iostream>
#include "application.hpp"

int main() {
    auto my_logger = spdlog::basic_logger_mt("file_logger", "logs/log.txt");
    spdlog::set_default_logger(my_logger);
    spdlog::set_pattern("%+", spdlog::pattern_time_type::utc);
#ifdef NDEBUG
    spdlog::set_level(spdlog::level::err);
#else
    spdlog::set_level(spdlog::level::debug);
#endif
    spdlog::info("Spdlog version {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);

    try {
        Application app;
        app.run();
    } catch (const char* e) {
        std::cerr << e << std::endl;
        return 1;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }

    return 0;
}
