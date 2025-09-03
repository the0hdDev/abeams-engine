#include "logsys.h"



const std::string Log::RED = "\033[31m";
const std::string Log::GREEN = "\033[32m";
const std::string  Log::YELLOW = "\033[33m";
const std::string Log::BLUE = "\033[34m";
const std::string Log::BOLD = "\033[1m";
const std::string Log::UNDERLINE = "\033[4m";
const std::string Log::BG_CYAN = "\033[46m";
const std::string Log::WHITE = "\033[97m";
const std::string Log::RESET = "\033[0m";

std::string Log::currentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Explicit instantiation for std::string

Log logSys;

