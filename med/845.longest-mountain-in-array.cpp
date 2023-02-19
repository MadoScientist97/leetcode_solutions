#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int longestMountain(vector<int>& arr) {
    if (arr.size() <= 2) return 0;
    int local_max_len = 0;
    int global_max = 0;
    bool up = false;
    bool down = false;
    int size = arr.size();
    for (int i = 1; i < size;) {
        while (i < size && arr[i-1] == arr[i])
            i++;
        while (i < size && arr[i-1] < arr[i]) {
            local_max_len++;
            i++;
            up = true;
        }
        while (i < size && arr[i-1] > arr[i]) {
            local_max_len++;
            i++;
            down = true;
        }
        if (up & down && local_max_len+1 > global_max) {
            global_max = local_max_len+1;
            local_max_len = 0;
        }
        up = false;
        down = false;
    }
    return global_max;
}

int main (int argc, char *argv[])
{
  vector<int> arr = {2,1,4,7,3,2,5};
  cout<<"The answer is: " << longestMountain(arr);
  return 0;
}

