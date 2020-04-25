#include <stdlib.h>
#include <iostream>

void max_across(int arr[], int s, int m, int e,
    int *temp_s, int *temp_e, int *temp_sum) {

    *temp_s = m - 1, *temp_e = m;
    int leftSum = arr[*temp_s], rightSum = arr[*temp_e];
    int sum = 0;

    for (int i = m - 1; i >= s; i--) {
        sum += arr[i];
        if ( sum > leftSum ) {
            leftSum = sum;
            *temp_s = i;
        }
    }

    sum = 0;
    for (int i = m; i < e; i++) {
        sum += arr[i];
        if ( sum > rightSum ) {
            rightSum = sum;
            *temp_e = i;
        }
    }

    *temp_sum = leftSum + rightSum;
}

void max_sub_array(int arr[], int s, int e,
    int *left_index, int *right_index, int *sum) {

    if ( e - s == 1 ) {
        *left_index = s;
        *right_index = e;
        *sum = arr[s];
        return;
    }

    int m = (e + s) / 2;
    int temp_s, temp_e, temp_sum;

    max_sub_array(arr, s, m, left_index, right_index, sum);
    max_sub_array(arr, m, e, &temp_s, &temp_e, &temp_sum);

    if ( temp_sum > *sum ) {
        *left_index = temp_s;
        *right_index = temp_e;
        *sum = temp_sum;
    }

    max_across(arr, s, m, e, &temp_s, &temp_e, &temp_sum);

    if (temp_sum > *sum) {
        *left_index = temp_s;
        *right_index = temp_e;
        *sum = temp_sum;
    }
}


int main() {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18,
        20, -7, 12, -5, -22, 15, -4, 7};
    int n = 16;

    int left_index, right_index, sum;

    max_sub_array(arr, 0, n, &left_index, &right_index, &sum);

    std::cout <<left_index <<" " <<right_index <<" " <<sum <<std::endl;

    return 0;
}
