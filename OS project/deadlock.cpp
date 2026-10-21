#include <iostream>
#include <vector>
using namespace std;

bool isLessOrEqual(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > b[i]) return false;
    return true;
}

int main() {
    int n = 5, m = 3; // 5 processes, 3 resources

    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 3},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> request = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}
    };

    vector<int> available = {0, 0, 0};

    vector<int> work = available;
    vector<bool> finish(n, false);

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i] && isLessOrEqual(request[i], work)) {
                for (int j = 0; j < m; j++)
                    work[j] += allocation[i][j];
                finish[i] = true;
                changed = true;
            }
        }
    }

    bool deadlock = false;
    cout << "Processes that cannot finish: ";
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            cout << "P" << i + 1 << " ";
            deadlock = true;
        }
    }
    cout << endl;

    if (deadlock)
        cout << "System is in Deadlock!" << endl;
    else
        cout << "No Deadlock detected." << endl;

    return 0;
}
