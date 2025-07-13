#include "logsys.h"

template<typename T>
const std::string Log<T>::RED = "\033[31m";
template<typename T>
const std::string Log<T>::GREEN = "\033[32m";
template<typename T>
const std::string Log<T>::YELLOW = "\033[33m";
template<typename T>
const std::string Log<T>::BLUE = "\033[34m";
template<typename T>
const std::string Log<T>::BOLD = "\033[1m";
template<typename T>
const std::string Log<T>::UNDERLINE = "\033[4m";
template<typename T>
const std::string Log<T>::BG_CYAN = "\033[46m";
template<typename T>
const std::string Log<T>::WHITE = "\033[97m";
template<typename T>
const std::string Log<T>::RESET = "\033[0m";

// Explicit instantiation for std::string
template class Log<std::string>;