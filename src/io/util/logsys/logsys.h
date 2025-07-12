//
// Created by Theo Wimber on 11.07.25.
//

#ifndef LOGSYS_H
#define LOGSYS_H
#include <iostream>
#include <string>
enum class LogLevel
{
    WARNING, // Normal Warning
    ERROR, // Normal Error. Program can operate along.
    DEBUG, // Debug Information. Only use for Debug Build
    INFO, // Normal Information. Can and should be used in
    TRACE, // Very Detailed Debug information
    CRITICAL, // Very Critical Error. Program cannot operate along.
    SEVERE // Worst Error. Needs immediate Attention!
};


class logsys
{
    public:
        // Generic
        static void print(std::string& message); // General Print Function
        static void loginfo(const auto& infcode, const uint16_t infint);

        // Error
        static void logerr(const auto& err, const uint16_t errint); // General Error Log Function
        static void logcritical(const auto& err, const uint16_t errint);
        static void logsevere(const auto& err, const uint16_t errint);

         // Debug

        static void logtrace(const auto& trcmsg, const uint16_t dbgint);
        static void logdebug(const auto& dbgmsg, const uint16_t dbgint);

        // misc
        static void logwarning(const auto& warning, const uint16_t warnint);
};



#endif //LOGSYS_H
