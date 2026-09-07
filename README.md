# EDR-SIEM-Log-Analyzer-
Mini EDR + SIEM log analyzer written in C++.   Reads endpoint logs (PROCESS, NETWORK, AUTH), detects threats (port scanning, brute force, suspicious processes) and generates SIEM‑style alerts. Project created as part of SOC L1 learning path.
Load_logs  
Loads logs from the logs.txt file in the format:
TIMESTAMP;HOST;TYPE;DETAILS

Parse_telemetry  
Parses EDR events:

PROCESS

NETWORK

AUTH

Analyze_processes  
Detects suspicious processes, e.g.:

powershell.exe -nop -w hidden

cmd.exe /c

others typical of L1 attacks

Detect_brute_force  
Counts failed login attempts and generates an alert when the threshold is exceeded.

Detect_port_scan  
Analyzes activity across various ports from a single IP → detects port scanning.

Analyze_network  
Detects recurring network errors and unusual connection attempts.

Generate_alerts  
Creates SIEM-style alerts:
[P2] Suspicious process execution: powershell.exe -nop -w hidden | Host: HOST01
[P2] Brute force login attempts detected | Host: HOST01
[P2] Port scanning activity detected from IP: 10.0.0.8 | Host: N/A

Code organized into modules:

parser

detection

report

main

Symuluje_EDR  
Simulates endpoint telemetry (processes, network, logins).

Symuluje_SIEM  
Correlates events and generates alerts like a real SIEM.

Project created as a practical SOC L1 exercise:

log analysis

threat detection

event correlation

alert creation

understanding endpoint telemetry
