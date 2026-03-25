# C++ Logger

To use this logger, include `logger.h` in your program and initialize it with a log file using `Logger::init("log.txt")`.

Use `Logger::info()`, `Logger::warn()`, and `Logger::error()` to log messages. These will be printed to the console and saved to the file with a timestamp.

Once logging is complete, call `Logger::shutdown()` to close the file properly.
