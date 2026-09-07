// report.cpp
#include "detection.h"
#include <iostream>

void printAlerts(const std::vector<Alert>& alerts) {
    if (alerts.empty()) {
        std::cout << "No alerts detected.\n";
        return;
    }

    std::cout << "=== ALERTS ===\n";
    for (const auto& a : alerts) {
        std::cout << "[" << a.severity << "] "
                  << a.description
                  << " | Host: " << a.host << "\n";
    }
}
