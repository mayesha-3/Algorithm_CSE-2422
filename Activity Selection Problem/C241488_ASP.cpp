#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end, index;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and end times:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
        activities[i].index = i + 1;
    }

    sort(activities.begin(), activities.end(), compare);

    cout << "\nSelected activities:\n";
    int lastEnd = 0;
    for (const auto& act : activities) {
        if (act.start >= lastEnd) {
            cout << "Activity " << act.index << ": (" << act.start << ", " << act.end << ")\n";
            lastEnd = act.end;
        }
    }

    return 0;
}
