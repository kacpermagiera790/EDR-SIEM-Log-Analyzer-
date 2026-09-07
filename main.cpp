// main.cpp
#include "parser.h"
#include "detection.h"
#include <vector>

// deklaracja z report.cpp
void printAlerts(const std::vector<Alert>& alerts);

int main() {
    auto logs = parseLogs("logs/logs.txt");
    auto alerts = detectThreats(logs);
    printAlerts(alerts);
    return 0;
}
