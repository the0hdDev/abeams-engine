#pragma once
#include <functional>
#include <unordered_map>

namespace config
{
    class cliHandler
    {
        public:
            cliHandler();
            ~cliHandler() = default;
            void startHandler(int argc, char* argv[]);
        private:
            std::unordered_map<std::string, std::function<void(int argc, char* argv[])>> commandMap;
    };
}