#include <iostream>
#include <string>
#include <vector>

void lcs(std::string a, std::string b, std::vector<std::vector<int>> *count,
                                std::vector<std::vector<char>> *direction) {
    for (int i = 1; i < count->size(); i++) {
        for (int j = 1; j < (*count)[i].size(); j++) {
            if ( a[j - 1] == b[i - 1] ) {
                (*count)[i][j] = (*count)[i - 1][j - 1] + 1;
                (*direction)[i][j] = 'D';
            } else if ( (*count)[i - 1][j] >= (*count)[i][j - 1] ) {
                (*count)[i][j] = (*count)[i - 1][j];
                (*direction)[i][j] = 'U';
            } else {
                (*count)[i][j] = (*count)[i][j - 1];
                (*direction)[i][j] = 'S';
            }
        }
    }
}

void print_lcs(std::vector<std::vector<char>> *direction,
                        std::string a, int i, int j) {
    if ( i == 0 || j == 0 )
        return;

    if ( (*direction)[i][j] == 'D' ) {
        print_lcs(direction, a, i - 1, j - 1);
        std::cout <<a[j - 1];
    } else if ( (*direction)[i][j] == 'U' ) {
        print_lcs(direction, a, i - 1, j);
    } else {
        print_lcs(direction, a, i, j - 1);
    }
}

int main() {
    std::string b = "ABCBDAB", a = "BDCABA";

    std::vector<std::vector<int>> count(b.size() + 1,
                                            std::vector<int>(a.size() + 1, 0));
    std::vector<std::vector<char>> direction(b.size() + 1,
                                        std::vector<char>(a.size() + 1, ' '));

    lcs(a, b, &count, &direction);

    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i].size(); j++) {
            std::cout <<count[i][j] <<direction[i][j] <<" ";
        }
        std::cout <<std::endl;
    }

    std::cout <<"\nLongest common subsequence : ";
    print_lcs(&direction, a, direction.size() - 1, direction[0].size() - 1);

    std::cout <<std::endl;
    return 0;
}
