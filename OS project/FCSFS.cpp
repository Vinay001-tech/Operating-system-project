#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], tat[n];
    cout << "Enter burst times:\n";
    for(int i=0;i<n;i++) cin >> bt[i];

    wt[0] = 0;  // first process waiting time = 0

    for(int i=1;i<n;i++) 
        wt[i] = wt[i-1] + bt[i-1]; // waiting time

    for(int i=0;i<n;i++) 
        tat[i] = wt[i] + bt[i];    // turnaround time

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";

    return 0;
}