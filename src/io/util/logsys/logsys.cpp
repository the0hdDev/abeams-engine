#include "logsys.h"


template<>
const std::string Log<std::string>::RED = "\033[31m";
template<>
const std::string Log<std::string>::GREEN = "\033[32m";
template<>
const std::string Log<std::string>::YELLOW = "\033[33m";
template<>
const std::string Log<std::string>::BLUE = "\033[34m";
template<>
const std::string Log<std::string>::BOLD = "\033[1m";
template<>
const std::string Log<std::string>::UNDERLINE = "\033[4m";
template<>
const std::string Log<std::string>::BG_CYAN = "\033[46m";
template<>
const std::string Log<std::string>::WHITE = "\033[97m";
template<>
const std::string Log<std::string>::RESET = "\033[0m";

// Explicit instantiation for std::string
template class Log<std::string>;
Log<std::string> logSys;
