#include<stdio.h>
#include<math.h>

int main()
{
    int failures[] = {59,24,29,30,17,13};
    int time_intervals[] = {1000, 2000, 3000, 4000, 5000, 6000};
    int total_components=172;
    printf("Time Interval\tFailures\tN(i)\tHazard (z(t))\tDensity (f(t))\tCumulative Distribution (F(t))\tReliability (R(t))\n");
    int cumulative_failures = 0;
    int total_observation_time = 0;
    int survivors = total_components;
    for(int i=0;i<6;i++) {
        cumulative_failures+=failures[i];
        total_observation_time += (time_intervals[i]-total_observation_time);
        survivors -=failures[i];
        double hazard = (double)failures[i] / (double)(survivors * 1000);
        double density = (double)failures[i] / (double)(total_observation_time * 1000);
        double cumulative_distribution = (double)cumulative_failures / total_components;
        double reliability = (double)survivors / total_components;
        printf("[%d-%d]\t\t%d\t\t%d\t%.4f\t\t%.6f\t\t%.6f\t\t%.6f\n", (i > 0 ? time_intervals[i - 1] : 0), time_intervals[i]-1, failures[i], survivors, hazard, density, cumulative_distribution, reliability);
    }
    return 0;
}