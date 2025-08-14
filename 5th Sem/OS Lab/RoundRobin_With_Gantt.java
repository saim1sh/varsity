import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

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
        this.responseTime = -1;
    }
}

public class RoundRobin_With_Gantt {
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

        System.out.print("Enter time quantum: ");
        int timeQuantum = sc.nextInt();

        sc.close();

        int completed = 0, currentTime = 0;
        float totalWT = 0, totalTAT = 0, totalRT = 0;
        List<Integer> ganttTime = new ArrayList<>();
        List<String> ganttProcess = new ArrayList<>();
        Queue<Process> readyQueue = new LinkedList<>();
        boolean[] inQueue = new boolean[n];

        ganttTime.add(currentTime);

        while (completed < n) {
            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && !inQueue[i] && processes[i].arrivalTime <= currentTime) {
                    readyQueue.offer(processes[i]);
                    inQueue[i] = true;
                }
            }

            if (readyQueue.isEmpty()) {
                int nextArrival = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    if (!processes[i].completed && processes[i].arrivalTime > currentTime) {
                        nextArrival = Math.min(nextArrival, processes[i].arrivalTime);
                    }
                }
                if (nextArrival != Integer.MAX_VALUE) {
                    ganttProcess.add("Idle");
                    ganttTime.add(nextArrival);
                    currentTime = nextArrival;
                }
            } else {
                Process currentProcess = readyQueue.poll();

                if (!currentProcess.isStarted) {
                    currentProcess.responseTime = currentTime - currentProcess.arrivalTime;
                    currentProcess.isStarted = true;
                }

                int executeTime = Math.min(timeQuantum, currentProcess.remainingTime);

                ganttProcess.add("P" + currentProcess.pid);
                currentProcess.remainingTime -= executeTime;
                currentTime += executeTime;
                ganttTime.add(currentTime);

                for (int i = 0; i < n; i++) {
                    if (!processes[i].completed && !inQueue[i] &&
                        processes[i].arrivalTime <= currentTime && processes[i] != currentProcess) {
                        readyQueue.offer(processes[i]);
                        inQueue[i] = true;
                    }
                }

                if (currentProcess.remainingTime == 0) {
                    currentProcess.completionTime = currentTime;
                    currentProcess.turnaroundTime = currentProcess.completionTime - currentProcess.arrivalTime;
                    currentProcess.waitingTime = currentProcess.turnaroundTime - currentProcess.burstTime;
                    totalWT += currentProcess.waitingTime;
                    totalTAT += currentProcess.turnaroundTime;
                    totalRT += currentProcess.responseTime;
                    currentProcess.completed = true;
                    completed++;
                    for (int i = 0; i < n; i++) {
                        if (processes[i] == currentProcess) {
                            inQueue[i] = false;
                            break;
                        }
                    }
                } else {
                    readyQueue.offer(currentProcess);
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