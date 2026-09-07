// parser.h
#pragma once
#include <string>

struct LogEntry {
    std::string timestamp;
    std::string host;
    std::string type;    // PROCESS / NETWORK / AUTH
    std::string details; // reszta linii
};
