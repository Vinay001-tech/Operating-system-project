// another cpu scheduling problem
// shotest job first
#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, bt;
};

bool cmp(Process a, Process b) {
    return a.bt < b.bt; // sort by burst time
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];
    for(int i=0;i<n;i++){
        p[i].id = i+1;
        cout << "Burst time P" << i+1 << ": ";
        cin >> p[i].bt;
    }

    sort(p, p+n, cmp);

    int wt[n], tat[n];
    wt[0] = 0;
    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + p[i-1].bt;
    for(int i=0;i<n;i++)
        tat[i] = wt[i] + p[i].bt;

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << p[i].id << "\t" << p[i].bt << "\t" << wt[i] << "\t" << tat[i] << "\n";
}
