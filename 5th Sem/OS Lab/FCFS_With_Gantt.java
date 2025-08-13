import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    boolean completed;

    Process(int pid, int arrivalTime, int burstTime) {
        this.pid = pid;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.completed = false;
    }
}

public class FCFS_With_Gantt {
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

        Arrays.sort(processes, (a, b) -> {
            if (a.arrivalTime == b.arrivalTime) {
                return Integer.compare(a.pid, b.pid);
            }
            return Integer.compare(a.arrivalTime, b.arrivalTime);
        });

        int currentTime = 0;
        float totalWT = 0, totalTAT = 0, totalRT = 0;
        StringBuilder ganttChart = new StringBuilder();
        List<Integer> ganttTime = new ArrayList<>();

        ganttTime.add(currentTime);

        for (int i = 0; i < n; i++) {
            Process p = processes[i];

            if (currentTime < p.arrivalTime) {
                ganttChart.append(" | Idle");
                ganttTime.add(p.arrivalTime);
                currentTime = p.arrivalTime;
            }

            p.responseTime = currentTime - p.arrivalTime;

            p.completionTime = currentTime + p.burstTime;
            p.turnaroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnaroundTime - p.burstTime;
            p.completed = true;

            currentTime = p.completionTime;

            totalWT += p.waitingTime;
            totalTAT += p.turnaroundTime;
            totalRT += p.responseTime;

            ganttChart.append(" | P").append(p.pid);
            ganttTime.add(currentTime);
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
        System.out.println(ganttChart.append(" |").toString());

        for (int time : ganttTime) {
            System.out.print(time + "\t");
        }
        System.out.println();
    }
} 
