// detection.cpp
#include "detection.h"
#include <map>

std::vector<Alert> detectThreats(const std::vector<LogEntry>& logs) {
    std::vector<Alert> alerts;

    std::map<std::string, int> failedLogins;
    std::map<std::string, int> networkFailsPerIP;
    std::map<std::string, int> portsPerIP;

    for (const auto& log : logs) {
        if (log.type == "PROCESS") {
            if (log.details.find("powershell") != std::string::npos ||
                log.details.find("cmd.exe /c") != std::string::npos) {
                alerts.push_back({"P2", "Suspicious process execution: " + log.details, log.host});
            }
        }

        if (log.type == "AUTH") {
            if (log.details.find("LOGIN FAILED") != std::string::npos) {
                failedLogins[log.host]++;
            }
        }

        if (log.type == "NETWORK") {
            // przykładowy format: "10.0.0.8:22 FAILED"
            if (log.details.find("FAILED") != std::string::npos) {
                networkFailsPerIP[log.details]++;
            }
            // bardzo prosty „port scan”: różne porty w wielu liniach
            auto posColon = log.details.find(':');
            if (posColon != std::string::npos) {
                std::string ip = log.details.substr(0, posColon);
                portsPerIP[ip]++;
            }
        }
    }

    // brute force (AUTH)
    for (const auto& kv : failedLogins) {
        if (kv.second >= 3) {
            alerts.push_back({"P2", "Brute force login attempts detected", kv.first});
        }
    }

    // port scan (NETWORK)
    for (const auto& kv : portsPerIP) {
        if (kv.second >= 3) {
            alerts.push_back({"P2", "Port scanning activity detected from IP: " + kv.first, "N/A"});
        }
    }

    return alerts;
}
