#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], waiting[n], turnaround[n], completion[n];
    int visited[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
        visited[i] = 0;
    }

    printf("\nGantt Chart:\n");

    while(count < n) {
        int shortest = -1;
        int min_burst = 9999;

        for(i = 0; i < n; i++) {
            if(arrival[i] <= time && visited[i] == 0) {
                if(burst[i] < min_burst) {
                    min_burst = burst[i];
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        printf("P%d ", shortest + 1);

        time += burst[shortest];
        completion[shortest] = time;
        turnaround[shortest] = completion[shortest] - arrival[shortest];
        waiting[shortest] = turnaround[shortest] - burst[shortest];

        visited[shortest] = 1;
        count++;
    }

    float total_wait = 0, total_turn = 0;

    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        total_wait += waiting[i];
        total_turn += turnaround[i];
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, arrival[i], burst[i],
               waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turn / n);

    return 0;
}
