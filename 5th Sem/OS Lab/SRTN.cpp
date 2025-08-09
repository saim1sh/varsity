#include <bits/stdc++.h>
using namespace std;

// Structure to represent each process
struct P {
    int pid;         // Process ID
    int at;          // Arrival Time
    int bt;          // Burst Time (total CPU time required)
    int rt;          // Remaining Time (updated as process executes)
    int ct;          // Completion Time
    int tat;         // Turnaround Time = CT - AT
    int wt;          // Waiting Time = TAT - BT
    int resp;        // Response Time = time from arrival to first execution
    bool started = false;  // Flag: process started execution or not
    bool done = false;     // Flag: process completed or not

    // Constructor to initialize process with pid, arrival time, burst time
    P(int id=0, int a=0, int b=0) : pid(id), at(a), bt(b), rt(b), resp(-1) {}
};

int main() {
    int n; 
    cin >> n;                 // Number of processes
    vector<P> p;              // Vector to store all processes
    for (int i = 1; i <= n; i++) {
        int at, bt;
        cin >> at >> bt;      // Input arrival time and burst time
        p.emplace_back(i, at, bt);
    }

    int done = 0;             // Count of completed processes
    int time = 0;             // Current time of the CPU scheduler
    double totalWT = 0;       // Sum of all waiting times
    double totalTAT = 0;      // Sum of all turnaround times
    double totalRT = 0;       // Sum of all response times

    vector<int> ganttT = {0}; // Timeline points for Gantt chart, starts at 0
    vector<string> ganttP;    // Process execution sequence for Gantt chart

    // Continue until all processes complete
    while (done < n) {
        int idx = -1;         // Index of next process to execute
        int minRT = INT_MAX;  // Minimum remaining time found so far

        // Find process with shortest remaining time among arrived and not done
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                // Choose process with lower remaining time, break ties by earlier arrival
                if (p[i].rt < minRT || (p[i].rt == minRT && p[i].at < p[idx].at)) {
                    minRT = p[i].rt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process is ready to run at this time (CPU Idle)
            ganttP.push_back("Idle"); // Mark idle in Gantt chart
            time++;                   // Advance time by 1 unit
            ganttT.push_back(time);   // Add current time to Gantt timeline
        } else {
            auto &x = p[idx];          // Reference to the selected process

            // If process starts for the first time, calculate response time
            if (!x.started) {
                x.resp = time - x.at;  // Response time = first run time - arrival time
                x.started = true;      // Mark process as started
            }

            ganttP.push_back("P" + to_string(x.pid)); // Log process in Gantt chart
            x.rt--;              // Execute process for 1 time unit (reduce remaining time)
            time++;              // Increment current time by 1
            ganttT.push_back(time); // Mark timeline for Gantt chart

            // If process has finished execution
            if (x.rt == 0) {
                x.ct = time;              // Completion time = current time
                x.tat = x.ct - x.at;     // Turnaround time = completion - arrival
                x.wt = x.tat - x.bt;     // Waiting time = turnaround - burst
                x.done = true;           // Mark process as completed
                done++;                  // Increase completed count

                // Accumulate totals for average calculations later
                totalWT += x.wt;
                totalTAT += x.tat;
                totalRT += x.resp;
            }
        }
    }

    // Print the detailed process table with all calculated times
    cout << "P\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.pid << '\t' << x.at << '\t' << x.bt << '\t' << x.ct << '\t'
             << x.tat << '\t' << x.wt << '\t' << x.resp << '\n';
    }

    // Print average waiting, turnaround, and response times with 2 decimal places
    cout << fixed << setprecision(2)
         << "Avg WT: " << totalWT / n << "\n"
         << "Avg TAT: " << totalTAT / n << "\n"
         << "Avg RT: " << totalRT / n << "\n";

    // Print the Gantt chart visually showing process execution over time
    cout << "\nGantt Chart:\n";
    for (auto &label : ganttP) cout << "| " << label << ' ';
    cout << "|\n";

    // Print the timeline corresponding to Gantt chart events
    for (int t : ganttT) cout << t << "    ";
    cout << '\n';
}
