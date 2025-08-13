 import java.util.*;

class Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    boolean isStarted;
    boolean completed;

    Process(int pid, int arrivalTime, int burstTime) {
        this.pid = pid;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
        this.completed = false;
        this.isStarted = false;
    }
}

public class SRTN_With_ResponseTime {
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
        float totalWT = 0, totalTAT = 0, totalRT = 0;
        List<Integer> ganttTime = new ArrayList<>();
        List<String> ganttProcess = new ArrayList<>();

        ganttTime.add(currentTime);

        while (completed < n) {
            int idx = -1;
            int minRT = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                    if (processes[i].remainingTime < minRT) {
                        minRT = processes[i].remainingTime;
                        idx = i;
                    } else if (processes[i].remainingTime == minRT) {
                        if (processes[i].arrivalTime < processes[idx].arrivalTime) {
                            idx = i;
                        }
                    }
                }
            }

            if (idx == -1) {
                ganttProcess.add("Idle");
                currentTime++;
                ganttTime.add(currentTime);
            } else {
                Process p = processes[idx];

                if (!p.isStarted) {
                    p.responseTime = currentTime - p.arrivalTime;
                    p.isStarted = true;
                }

                ganttProcess.add("P" + p.pid);
                p.remainingTime--;
                currentTime++;
                ganttTime.add(currentTime);

                if (p.remainingTime == 0) {
                    p.completionTime = currentTime;
                    p.turnaroundTime = p.completionTime - p.arrivalTime;
                    p.waitingTime = p.turnaroundTime - p.burstTime;
                    totalWT += p.waitingTime;
                    totalTAT += p.turnaroundTime;
                    totalRT += p.responseTime;
                    p.completed = true;
                    completed++;
                }
            }
        }

        // Output Table
        System.out.println("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT");
        for (Process p : processes) {
            System.out.println("P" + p.pid + "\t" + p.arrivalTime + "\t" + p.burstTime + "\t" +
                    p.completionTime + "\t" + p.turnaroundTime + "\t" + p.waitingTime + "\t" + p.responseTime);
        }

        System.out.printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
        System.out.printf("Average Turnaround Time: %.2f\n", totalTAT / n);
        System.out.printf("Average Response Time: %.2f\n", totalRT / n);

        // Gantt Chart
        System.out.println("\nGantt Chart:");
        for (String label : ganttProcess) {
            System.out.print("| " + label + " ");
        }
        System.out.println("|");

        for (int time : ganttTime) {
            System.out.print(time + "    ");
        }
        System.out.println();
    }
}
 