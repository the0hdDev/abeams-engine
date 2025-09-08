#pragma once
#include <functional>
#include <unordered_map>

namespace config {
    class cliHandler
    {
        public:
            cliHandler();
            ~cliHandler() = default;
            void startCliHandler();
        private:
            std::unordered_map<std::string, std::function<void()>> configCommandMap;
    };
}