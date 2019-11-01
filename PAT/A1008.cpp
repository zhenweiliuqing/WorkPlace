/*******************************
1008. Elevator (20)
The highest building in our city has only one elevator. A request list is
made up with N positive numbers. The numbers denote at which floors the 
elevator will stop, in specified order. It costs 6 seconds to move the 
elevator up one floor, and 4 seconds to move down one floor. The elevator
will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill
the requests on the list. The elevator is on the 0th floor at the beginning
and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N,
followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.
Sample Input:
3 2 3 1
Sample Output:
41 = 2*6+5 + 1*6+5 + 2*4+5 
******************************/

#include <iostream>

using namespace std;

int main()
{
    int i;
    int n;
    cin >> n;
    int *f = new int[n];
    
    for (i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    int sum = n * 5;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            sum += f[0] * 6;
        sum += (f[i] > f[i - 1]) ? (6 * (f[i] - f[i - 1])) : (4 * (f[i - 1] - f[i]));
    }
    delete[] f;
    cout << sum;
    return 0;
}
