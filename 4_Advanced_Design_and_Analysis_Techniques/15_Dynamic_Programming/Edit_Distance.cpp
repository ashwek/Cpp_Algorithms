#include <iostream>
#include <string>
#include <vector>

int edit_distance(std::string a, std::string b) {
    std::vector<std::vector<int>> count(a.size() + 1,
                                    std::vector<int>(b.size() + 1));

    count[0][0] = 0;
    for (int i = 1; i <= a.size(); i++) {
        count[i][0] = i;
    }
    for (int i = 1; i <= b.size(); i++) {
        count[0][i] = i;
    }

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if ( a[i - 1] == b[j - 1] ) {
                count[i][j] = count[i - 1][j - 1];
            } else {
                count[i][j] = count[i - 1][j - 1];  // substitute
                count[i][j] = std::min(count[i][j], count[i - 1][j]);  // delete
                count[i][j] = std::min(count[i][j], count[i][j - 1]);  // insert
                count[i][j]++;
            }
        }
    }

    return count[a.size()][b.size()];
}

int main() {
    std::string a = "editing", b = "distance";

    std::cout<< edit_distance(a, b);

    return 0;
}
