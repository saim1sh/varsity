import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    boolean completed;

    Process(int pid, int arrivalTime, int burstTime) {
        this.pid = pid;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.completed = false;
    }
}

public class SJF_With_Gantt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter arrival time for Process " + (i + 1) + ": ");
            int at = sc.nextInt();
            System.out.print("Enter burst time for Process " + (i + 1) + ": ");
            int bt = sc.nextInt();
            processes[i] = new Process(i + 1, at, bt);
        }

        sc.close();

        int completed = 0, currentTime = 0;
        float totalWT = 0, totalTAT = 0;
        StringBuilder ganttChart = new StringBuilder();
        List<Integer> ganttTime = new ArrayList<>();

        ganttTime.add(currentTime);

        while (completed < n) {
            int idx = -1;
            int minBT = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                    if (processes[i].burstTime < minBT) {
                        minBT = processes[i].burstTime;
                        idx = i;
                    } else if (processes[i].burstTime == minBT) {
                        if (processes[i].arrivalTime < processes[idx].arrivalTime) {
                            idx = i;
                        }
                        else if (processes[i].arrivalTime == processes[idx].arrivalTime) {
                            if (processes[i].pid < processes[idx].pid) {
                                idx = i;
                            }
                    }
                }
            }

            if (idx == -1) {
                currentTime++;
                ganttChart.append(" | Idle");
                ganttTime.add(currentTime);
            } else {
                Process p = processes[idx];
                p.completionTime = currentTime + p.burstTime;
                p.turnaroundTime = p.completionTime - p.arrivalTime;
                p.waitingTime = p.turnaroundTime - p.burstTime;
                p.completed = true;
                currentTime = p.completionTime;
                completed++;

                totalWT += p.waitingTime;
                totalTAT += p.turnaroundTime;

                ganttChart.append(" | P").append(p.pid);
                ganttTime.add(currentTime);
            }
        }

        System.out.println("\nProcess\tAT\tBT\tCT\tTAT\tWT");
        for (Process p : processes) {
            System.out.println("P" + p.pid + "\t" + p.arrivalTime + "\t" + p.burstTime + "\t" +
                    p.completionTime + "\t" + p.turnaroundTime + "\t" + p.waitingTime);
        }

        System.out.printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
        System.out.printf("Average Turnaround Time: %.2f\n", totalTAT / n);

        System.out.println("\nGantt Chart:");
        System.out.println(ganttChart.append(" |").toString());

        for (int time : ganttTime) {
            System.out.print(time + "\t");
        }
        System.out.println();
    }
}
