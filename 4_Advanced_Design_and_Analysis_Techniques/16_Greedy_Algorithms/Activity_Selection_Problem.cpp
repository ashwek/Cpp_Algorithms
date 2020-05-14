#include <iostream>
#include <vector>
#include <algorithm>

bool comp(std::vector<int> a, std::vector<int> b) {
    return a[1] < b[1];
}

void activity_selector(std::vector<std::vector<int>> activities) {
    std::sort(activities.begin(), activities.end(), comp);

    std::vector<int> ans = {0};
    int lastActivity = 0;
    for (int i = 1; i < activities.size(); i++) {
        if ( activities[i][0] >= activities[lastActivity][1] ) {
            ans.push_back(i);
            lastActivity = i;
        }
    }

    std::cout <<"Number of activities : " <<ans.size();
    std::cout <<"\nActivities : ";
    for (int i : ans) {
        std::cout <<"(" <<activities[i][0] <<", " <<activities[i][1] <<"), ";
    }
}

int main() {
    std::vector<std::vector<int>> activities = {{3, 5}, {12, 16}, {8, 11},
                                                {8, 12}, {5, 9}, {5, 7},
                                                {3, 9}, {1, 4}, {6, 10},
                                                {2, 14}, {0, 6}};

    activity_selector(activities);

    std::cout <<std::endl;
    return 0;
}
