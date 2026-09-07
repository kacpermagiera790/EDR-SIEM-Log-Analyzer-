// parser.cpp
#include "parser.h"
#include <vector>
#include <fstream>
#include <sstream>

std::vector<LogEntry> parseLogs(const std::string& path) {
    std::vector<LogEntry> logs;
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string ts, host, type, details;

        std::getline(ss, ts, ';');
        std::getline(ss, host, ';');
        std::getline(ss, type, ';');
        std::getline(ss, details); // reszta

        LogEntry entry{ts, host, type, details};
        logs.push_back(entry);
    }

    return logs;
}
