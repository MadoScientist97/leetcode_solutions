#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

bool isprime(int n) 
{
  if (n == 1) return false;
  for (int i = 2; i <= (int)sqrt(n); i++)
    if (n%i == 0) return false;
  return true;
}


int get_prime_counts(vector<int>& nums) 
    {
      if (nums.size() < 1) return 0;
      if (nums.size() < 2) return 1;
      auto max_iter = std::max_element(nums.begin(), nums.end());
      int max = *max_iter;
      std::set<int> factors;
      for (auto i = 1; i <= max; i++ ) 
      {
        if (isprime(i)) 
        {
          for (int j = 0; j < nums.size(); j++) 
            if (nums[j]%i == 0) 
            {
              factors.insert(i);
              break;
            }
        }
      }
      cout<<"The Factors are: "; 
      for (auto p:factors)
        printf("%d ", p);
      return factors.size();
    }


int main (int argc, char *argv[])
{
  vector<int> nums = {2,4,8,16};
  int primeCounts = get_prime_counts(nums);
  cout<<"The Number of Prime Factors are: " << primeCounts;
  return 0;
}
