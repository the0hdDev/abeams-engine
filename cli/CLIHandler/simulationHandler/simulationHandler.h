#pragma once
#include <unordered_map>
#include <string>
#include <functional>


namespace simulation
{
    class cliHandler {
        public:
            cliHandler();
            ~cliHandler() = default;
            void startHandler();
        private:
            std::unordered_map<std::string, std::function<void()>> configCommandMap;
    };
}