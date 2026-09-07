// detection.h
#pragma once
#include "parser.h"
#include <vector>
#include <string>

struct Alert {
    std::string severity;
    std::string description;
    std::string host;
};

std::vector<Alert> detectThreats(const std::vector<LogEntry>& logs);
