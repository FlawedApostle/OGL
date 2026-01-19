#include <chrono>
#include <format>
#include <string>
#include "Timer.h"

/// because im in x86 build this wont work
//std::string Timer::GetDateTime() {
//    using namespace std::chrono;
//
//    auto now = zoned_time
//    { 
//        current_zone(), system_clock::now() 
//    };
//    return std::format("{:%Y-%m-%d %H:%M:%S}", now);
//}

#include <chrono>
#include <iomanip>
#include <sstream>

std::string Timer::GetDateTime() {
    using namespace std::chrono;

    auto now = system_clock::now();
    std::time_t now_c = system_clock::to_time_t(now);

    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &now_c);
#else
    localtime_r(&now_c, &localTime);
#endif

    std::ostringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

