package os;

import java.util.Scanner;

public class DeadlockSimulator {

    static int n; // number of processes
    static int m; // number of resources

    static int[][] allocation;
    static int[][] max;
    static int[][] need;
    static int[] available;

    // Calculate Need matrix
    static void calculateNeed() {
        need = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
            }
        }
    }

    // Banker's Algorithm
    static boolean isSafeState() {
        boolean[] finished = new boolean[n];
        int[] work = new int[m];

        // Initialize work = available
        for (int i = 0; i < m; i++) {
            work[i] = available[i];
        }

        int count = 0;
        int[] safeSequence = new int[n];

        while (count < n) {
            boolean found = false;

            for (int i = 0; i < n; i++) {
                if (!finished[i]) {
                    boolean canExecute = true;

                    for (int j = 0; j < m; j++) {
                        if (need[i][j] > work[j]) {
                            canExecute = false;
                            break;
                        }
                    }

                    if (canExecute) {
                        // Process executes
                        for (int j = 0; j < m; j++) {
                            work[j] += allocation[i][j];
                        }

                        safeSequence[count++] = i;
                        finished[i] = true;
                        found = true;

                        System.out.println("Process P" + i + " executed. Resources released.");
                    }
                }
            }

            if (!found) {
                return false; // Deadlock
            }
        }

        System.out.print("\nSAFE STATE ✅\nSafe Sequence: ");
        for (int i = 0; i < n; i++) {
            System.out.print("P" + safeSequence[i] + " ");
        }
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n====== DEADLOCK SIMULATOR MENU ======");
            System.out.println("1. Enter System Data");
            System.out.println("2. Display Matrices");
            System.out.println("3. Check Safe State");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    inputData(sc);
                    break;

                case 2:
                    displayMatrices();
                    break;

                case 3:
                    checkDeadlock();
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 4);

        sc.close();
    }

    static void inputData(Scanner sc) {

        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        System.out.print("Enter number of resources: ");
        m = sc.nextInt();

        allocation = new int[n][m];
        max = new int[n][m];
        available = new int[m];

        System.out.println("\nEnter Allocation Matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                allocation[i][j] = sc.nextInt();

        System.out.println("\nEnter Max Matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                max[i][j] = sc.nextInt();

        System.out.println("\nEnter Available Resources:");
        for (int i = 0; i < m; i++)
            available[i] = sc.nextInt();

        calculateNeed();
        System.out.println("System data loaded successfully ✔");
    }

    static void displayMatrices() {

        if (allocation == null) {
            System.out.println("Please enter system data first!");
            return;
        }

        System.out.println("\nAllocation Matrix:");
        printMatrix(allocation);

        System.out.println("\nMax Matrix:");
        printMatrix(max);

        System.out.println("\nNeed Matrix:");
        printMatrix(need);

        System.out.print("\nAvailable Resources: ");
        for (int i = 0; i < m; i++) {
            System.out.print(available[i] + " ");
        }
        System.out.println();
    }

    static void printMatrix(int[][] matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void checkDeadlock() {

        if (allocation == null) {
            System.out.println("Please enter system data first!");
            return;
        }

        System.out.println("\nChecking system state...");
        boolean safe = isSafeState();

        if (!safe) {
            System.out.println("\nDEADLOCK DETECTED ❌");
            System.out.println("Processes unable to execute due to insufficient resources.");
        }
    }
}




