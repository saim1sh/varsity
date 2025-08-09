#include <bits/stdc++.h>
using namespace std;

// Structure to represent each process and its attributes
struct P {
    int pid;        // Process ID
    int at;         // Arrival Time
    int bt;         // Burst Time
    int ct;         // Completion Time
    int tat;        // Turnaround Time = CT - AT
    int wt;         // Waiting Time = TAT - BT
    int resp;       // Response Time = time from arrival to first execution
    bool started = false;  // Flag to check if process has started executing
    bool done = false;     // Flag to check if process has completed

    // Constructor to initialize process with id, arrival time, burst time
    P(int id=0, int a=0, int b=0) : pid(id), at(a), bt(b), resp(-1) {}
};

int main() {
    int n; 
    cin >> n;              // Read number of processes
    vector<P> p;           // Vector to store all processes

    // Read arrival and burst times for each process
    for (int i = 1; i <= n; i++) {
        int at, bt;
        cin >> at >> bt;   // Input arrival time and burst time
        p.emplace_back(i, at, bt);  // Add process to vector
    }

    int done = 0;          // Count of completed processes
    int time = 0;          // Current time in the scheduler
    double totalWT = 0;    // Total waiting time for all processes
    double totalTAT = 0;   // Total turnaround time for all processes
    double totalRT = 0;    // Total response time for all processes

    vector<int> ganttT;       // Time markers for the Gantt chart
    vector<string> ganttP;    // Process labels or "Idle" for the Gantt chart

    // Loop until all processes have completed
    while (done < n) {
        int idx = -1;           // Index of the next process to run
        int earliestAT = INT_MAX; // Store earliest arrival time among ready processes

        // Find the process with the earliest arrival time that is not done and has arrived
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                // Update if this process arrived earlier or has a smaller pid on tie
                if (p[i].at < earliestAT || (p[i].at == earliestAT && p[i].pid < p[idx].pid)) {
                    earliestAT = p[i].at;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process is ready to run at this time; CPU is idle
            // Add "Idle" to Gantt chart if the previous state wasn't idle
            if (ganttP.empty() || ganttP.back() != "Idle") {
                ganttP.push_back("Idle");
                ganttT.push_back(time);  // Mark idle start time
            }
            time++;  // Increase current time during idle
        } else {
            auto &x = p[idx];     // Reference to the selected process
            ganttT.push_back(time); // Mark process start time in Gantt chart
            ganttP.push_back("P" + to_string(x.pid)); // Add process label to Gantt chart

            // If this is the first time the process runs, calculate response time
            if (!x.started) {
                x.resp = time - x.at;  // Response time = time first scheduled - arrival time
                x.started = true;      // Mark process as started
            }

            time += x.bt;       // Increase current time by burst time (non-preemptive)
            x.ct = time;        // Completion time = current time after process finishes
            x.tat = x.ct - x.at; // Turnaround time = completion time - arrival time
            x.wt = x.tat - x.bt; // Waiting time = turnaround time - burst time
            x.done = true;      // Mark process as completed

            // Accumulate totals for averages
            totalWT += x.wt;
            totalTAT += x.tat;
            totalRT += x.resp;

            done++;             // Increment count of completed processes
        }
    }

    ganttT.push_back(time); // Mark the end time of the last process in Gantt chart

    // Print the process table with all timing information
    cout << "P\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.pid << '\t' << x.at << '\t' << x.bt << '\t' << x.ct << '\t'
             << x.tat << '\t' << x.wt << '\t' << x.resp << '\n';
    }

    // Print average waiting, turnaround, and response times with 2 decimals
    cout << fixed << setprecision(2);
    cout << "Avg WT: " << totalWT / n << "\n";
    cout << "Avg TAT: " << totalTAT / n << "\n";
    cout << "Avg RT: " << totalRT / n << "\n";

    // Print the Gantt chart
    cout << "\nGantt Chart:\n";
    for (auto &label : ganttP) cout << "| " << label << ' ';
    cout << "|\n";

    // Print the timeline underneath the Gantt chart
    for (int t : ganttT) cout << t << "\t";
    cout << "\n";
}
