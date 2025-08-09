#include <bits/stdc++.h>
using namespace std;

// Process structure to hold info about each process
struct P {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
    bool done = 0; // Flag if process completed
};

int main() {
    int n; 
    cin >> n;               // Number of processes
    vector<P> p(n);         // Vector to store processes

    // Input arrival and burst times
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;   // Assign process ID starting from 1
        cin >> p[i].at >> p[i].bt;  // Arrival time and burst time
    }

    int done = 0;           // Count of completed processes
    int time = 0;           // Current time of CPU scheduler
    double totWT = 0, totTAT = 0; // Totals for waiting and turnaround time
    string gantt = "";      // String to record Gantt chart steps
    vector<int> ganttT = {0}; // Time markers for Gantt chart

    // Loop until all processes are done
    while (done < n) {
        int idx = -1;          // Index of next process to execute
        int minBT = INT_MAX;   // Track minimum burst time among eligible processes

        // Find process with shortest burst time that has arrived and not done
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                // Choose process with smaller burst time or earlier arrival if tie
                if (p[i].bt < minBT || (p[i].bt == minBT && p[i].at < p[idx].at)) {
                    minBT = p[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process ready: CPU idle, increment time
            time++;
            gantt += " | Idle";    // Mark idle time in Gantt chart
            ganttT.push_back(time);// Add current time to Gantt timeline
        } else {
            // Execute selected process
            auto &x = p[idx];
            x.ct = time + x.bt;            // Completion time = current time + burst
            x.tat = x.ct - x.at;           // Turnaround = completion - arrival
            x.wt = x.tat - x.bt;           // Waiting = turnaround - burst
            x.done = 1;                    // Mark as completed
            time = x.ct;                   // Advance current time
            done++;                       // Increase completed process count

            totWT += x.wt;                // Accumulate waiting time
            totTAT += x.tat;              // Accumulate turnaround time

            gantt += " | P" + to_string(x.pid); // Append process to Gantt chart
            ganttT.push_back(time);              // Add completion time marker
        }
    }

    // Print process info table
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << x.pid << '\t' << x.at << '\t' << x.bt << '\t'
             << x.ct << '\t' << x.tat << '\t' << x.wt << '\n';
    }

    // Print average waiting and turnaround times with 2 decimal precision
    cout << fixed << setprecision(2)
         << "Avg WT: " << totWT / n << "\nAvg TAT: " << totTAT / n << "\n";

    // Print the Gantt chart timeline
    cout << "\nGantt Chart:" << gantt << " |\n";
    for (int t : ganttT) cout << t << "\t"; // Print time labels below Gantt chart
    cout << '\n';
}
