#include <iostream>
#include <vector>
using namespace std;

bool check(int target, int num_indices, int max_sum) {
    if(target != 1 && target != 2 && target != 3) {
        cout << "INVALID TARGET!!!" << endl;
        return false;
    }
    int min_possible_sum = 1 * num_indices;
    int max_possible_sum = 3 * num_indices;

    if(max_sum < min_possible_sum || max_sum > max_possible_sum) return false;

    int min_sum_with_target = target + (1 * (num_indices - 1));
    int max_sum_with_target = target + (3 * (num_indices - 1));

    return min_sum_with_target <= max_sum && max_sum <= max_sum_with_target;

}

int main() {

    int num_indices;
    int max_sum;

    while(true) {
        cout << "Enter num_indices: ";
        cin >> num_indices;
        cout << "Enter max_sum: ";
        cin >> max_sum;
        bool possible1 = check(1, num_indices, max_sum);
        bool possible2 = check(2, num_indices, max_sum);
        bool possible3 = check(3, num_indices, max_sum);
        possible1 ? cout << "1 POSSIBLE" << endl : cout << "1 NOT POSSIBLE" << endl;
        possible2 ? cout << "2 POSSIBLE" << endl : cout << "2 NOT POSSIBLE" << endl;
        possible3 ? cout << "3 POSSIBLE" << endl : cout << "3 NOT POSSIBLE" << endl;
    }

}