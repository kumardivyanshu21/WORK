#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    static std::ofstream file;

    static std::string getTime() {
        std::time_t now = std::time(nullptr);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buffer);
    }
    //main logic of the loger
    static void log(const std::string& level, const std::string& message) {
        std::string output = "[" + getTime() + "] [" + level + "] " + message;

        std::cout << output << std::endl;
        if (file.is_open()) {
            file << output << std::endl;
        }
    }
public:
    static void init(const std::string& filename) {
        file.open(filename, std::ios::app);
    }
    static void info(const std::string& message) {
        log("INFO", message);
    }
    static void error(const std::string& message) {
        log("ERROR", message);
    }
    static void warn(const std::string& message) {
        log("WARN", message);
    }

    static void shutdown() {
        if (file.is_open()) {
            file.close();
        }
    }
};

// static member definition
std::ofstream Logger::file;