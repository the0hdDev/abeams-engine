# Production Readiness Checklist

This document outlines areas for improvement to make the codebase production-ready.

## 1. Error Handling

- **Incomplete Error Handling:** The `estbComFD::run` method has a general `catch (const std::exception& e)` block that prints to `std::cout`. This is not sufficient for a production environment. Errors should be logged with more details, and the application should have a strategy for graceful recovery or shutdown. (src/com/estbComFD.cpp:33)
- **File I/O:** The `ParseConfig` function in `src/io/util/parseConfig.cpp` checks if the file is open but doesn't handle the case where the file is empty or malformed. This could lead to crashes. (src/io/util/parseConfig.cpp:8)
- **Websocket Communication:** The websocket communication in `estbComFD.cpp` lacks proper error handling for read/write operations. Network operations can fail for various reasons, and these failures should be handled gracefully. (src/com/estbComFD.cpp:28)

## 2. Logging

- **Inconsistent Logging:** The logging is inconsistent. Some parts of the code use the `logSys` object, while others print directly to `std::cout` or `std::cerr`. All logging should be standardized through the `logSys` object. (src/com/estbComFD.cpp:33, src/io/util/logsys/logToFile.cpp:16)
- **Insufficient Logging:** There are several places where logging is missing. For example, in `main.cpp`, there's no logging in the main loop. In `estbComFD.cpp`, there's no logging for the websocket messages being sent and received. (src/main.cpp:28, src/com/httpReqResHandler.cpp:20)
- **Log Levels:** The log levels are not used consistently. The `setLogLevel` function is called in `main.cpp`, but the log levels are not checked in all logging statements. (src/main.cpp:15, src/io/util/logsys/logsys.h:35)

## 3. Configuration

- **Hardcoded Values:** There are several hardcoded values in the code, such as the port number in `main.cpp` and the config file path. These should be moved to a configuration file. (src/main.cpp:12)
- **Configuration Management:** The `ReadConfig` class in `src/io/util/parseConfig.h` is a good start, but it could be improved. For example, it could validate the configuration file against a schema to ensure that all required values are present and have the correct type. (src/io/util/parseConfig.h:7)

## 4. Concurrency

- **Thread Management:** In `main.cpp`, a new thread is created for the `estbComFD` server and then detached. Detaching threads is generally not recommended as it can lead to resource leaks and make it difficult to reason about the application's lifecycle. A better approach would be to join the thread or use a thread pool. (src/main.cpp:18)
- **Race Conditions:** The `taskQueue` class in `src/io/thread/task/taskHandler.h` has a `tasks` queue, a `queueMutex`, and a `condition` variable. However, it's not clear how these are used to prevent race conditions. The code needs to be carefully reviewed to ensure that all shared data is properly protected. (src/io/thread/task/taskHandler.h:31)

## 5. Code Structure and Design

- **Unused Code:** The `pullDataSpdr` and `pullDataUsr` classes are empty and appear to be unused. They should be removed if they are not needed. (src/datapull/pullDataSpdr.h, src/datapull/pullDataUsr.h)
- **Header Guards:** The header guards in `pullDataSpdr.h` and `pullDataUsr.h` are not standard. They should be changed to `#pragma once` or use the standard `#ifndef`/`#define`/`#endif` idiom. (src/datapull/pullDataSpdr.h:6, src/datapull/pullDataUsr.h:6)
- **Class Design:** The `taskHandler` and `taskQueue` classes in `src/io/thread/task/taskHandler.h` are not well-defined. The `taskHandler` class has methods for adding and removing tasks from the queue, but it's not clear how it interacts with the `taskQueue` class. The `task` class has a `taskMutex`, but it's not clear what it's protecting. (src/io/thread/task/taskHandler.h:12)

## 6. Testing

- **No Tests:** There are no tests in the codebase. This makes it difficult to refactor the code or add new features without introducing regressions. Unit tests should be added for all classes and methods. Integration tests should be added to test the application as a whole.

## 7. Dependencies

- **Boost:** The code uses the Boost library, but it's not clear which version is required. The `CMakeLists.txt` file should be updated to specify the required version of Boost.
- **nlohmann/json:** The code uses the nlohmann/json library, but it's not clear which version is required. The `CMakeLists.txt` file should be updated to specify the required version of nlohmann/json.

## 8. Naming and Formatting

- **Inconsistent Naming:** The naming convention is inconsistent. Some classes use PascalCase (e.g., `ReadConfig`), while others use a mix of lowercase and underscores (e.g., `logToFile_c`). Functions also have inconsistent naming (e.g., `ParseConfig` vs. `getPort`). A consistent naming convention should be adopted and applied throughout the codebase.
- **Inconsistent Formatting:** The formatting is inconsistent. Some files use tabs, while others use spaces. The indentation is also inconsistent. A code formatter such as ClangFormat should be used to automatically format the code.