#include "logger.h"
int main() {
    Logger::init("log.txt");
    Logger::info("Program started");
    Logger::warn("This is a warning");
    Logger::error("Something failed");
    Logger::shutdown();
    return 0;
}