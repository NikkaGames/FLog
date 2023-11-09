#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <filesystem>

enum class SaveMode { NewLog, AppendLog };
constexpr int MaxLogSize = 524288;

namespace fs = std::filesystem; //C++17

class FLog {
private:
    std::string filePath;
    std::string logCache;
    std::string instanceAddress;
    bool autoSave = false;

public:
    FLog(const std::string& path) : filePath(path) {
        instanceAddress = reinterpret_cast<std::uintptr_t>(this);
        logCache = "/--- New FLog Instance / MemPtr : " + instanceAddress + " ---/\n"
                   "/--- Path : " + path + " ---/\n"
                   "/--- Creation Date : " + getCurrentDateTime() + " ---/\n\n";
    }

    void append(const std::string& log) {
        logCache += "\n" + getCurrentDateTime() + " : " + log + "\n";
        if (autoSave) {
            save(SaveMode::NewLog);
        }
    }

    void append(int value) {
        logCache += "\n" + getCurrentDateTime() + " : " + std::to_string(value) + "\n";
        if (autoSave) {
            save(SaveMode::NewLog);
        }
    }

    template<typename... Args>
    void appendFormatted(const std::string& format, Args... args) {
        char logBuffer[MaxLogSize];
        std::snprintf(logBuffer, MaxLogSize, format.c_str(), args...);
        logCache += "\n" + getCurrentDateTime() + " : " + logBuffer + "\n";
        if (autoSave) {
            save(SaveMode::NewLog);
        }
    }

    std::string getAddressString() const {
        return instanceAddress;
    }

    void setAutoSave(bool state) {
        autoSave = state;
    }

    void clearCache() {
        logCache.clear();
    }

    void eraseLog() {
        if (fs::exists(filePath) && fs::file_size(filePath) > 0) {
            fs::remove(filePath);
        }
    }

    void save(SaveMode mode) {
        std::ofstream outFile(filePath);

        if (mode == SaveMode::NewLog) {
            outFile << logCache;
        } else if (mode == SaveMode::AppendLog) {
            if (fs::exists(filePath) && fs::file_size(filePath) > 0) {
                std::ifstream inFile(filePath);
                std::stringstream data;
                data << inFile.rdbuf();
                data << "\n" + logCache;
                outFile << data.str();
            } else {
                outFile << logCache;
            }
        } else {
            outFile << "Failed to save logs!\nException: Unknown saving mode!";
        }
    }

    std::string getCurrentDateTime() const {
        auto now = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
        char buf[128];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d | %X", std::localtime(&nowTime));
        return buf;
    }
};
