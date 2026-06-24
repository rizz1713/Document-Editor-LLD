#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n = 5;


    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    sort(jobs, jobs + n, compare);


    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    char slot[10];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = '-';

    int totalProfit = 0;


    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == '-') {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    
    cout << "Selected Jobs:\n";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != '-') {
            // find job details
            for (int j = 0; j < n; j++) {
                if (jobs[j].id == slot[i]) {
                    cout << "Job " << jobs[j].id 
                         << " (Deadline: " << jobs[j].deadline 
                         << ", Profit: " << jobs[j].profit << ")\n";
                }
            }
        }
    }

    cout << "\nTotal Profit = " << totalProfit << endl;

    return 0;
}