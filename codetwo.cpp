/*Algorithm :

1) First count the maximum consecutive A's in the array as total_A. Also count the total number of A's in the array.
2) Maintain two vectors to get the consecutive A's at a particular index both from left and right.
3) Then we traverse through the array then whenever we find B we check one condition that is :
	if(left[i-1] + right[i+1] < total_A and sum + 1 >= answer) then answer = left[i-1] + right[i+1]; result = i.
	else answer = left[i-1]+right[i+1].
4) Then we display the result.

Code:-*/

#include <bits/stdc++.h>
using namespace std;
// Function for maximum_A
int maximum_A(vector<char> s, int n)
{
    // To count all A's in the array
    int total_A = 0;
 
    int answer = 0, curr= 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            total_A ++;
            curr++;
        }
        else {
            answer= max(curr, answer);
            curr = 0;
        }
    }

    answer = max(answer, curr);
    // To store cumulative A's at an index
    int left[n], right[n];
 
    if (s[0] == 'A')
        left[0] = 1;
    else
        left[0] = 0;
 
    if (s[n - 1] == 'A')
        right[n - 1] = 1;
    else
        right[n - 1] = 0;
 
    // Counting cumulative A's from left
    for (int i = 1; i < n; i++) {
        if (s[i] == 'A')
            left[i] = left[i - 1] + 1;
 
        // If B then start new cumulative A from that i
        else
            left[i] = 0;
    }
 // Counting cumulative A's from right
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '1')
            right[i] = right[i + 1] + 1;
 // If B then start new cumulative A from that i
        else
            right[i] = 0;
    }
 int res = 0;
    for (int i = 1; i < n - 1; i++) {
        // perform step 3 of the algorithm
        if (s[i] == 'B') {
 
            // step 3
            int sum = left[i - 1] + right[i + 1];
 
            if (sum < total_A and (sum+1) >= answer){
                answer = max(answer, sum + 1);
                res = i;
            }
 
            else
                answer = max(answer, sum);
        }
    }
 
    return res;
}

int main(){
vector<char> s = {'A', 'A', 'B', 'B', 'A','B', 'A', 'A', 'A', 'B', 'A', 'A', 'A', 'A'};
cout << maximum_A(s,14);
return 0;
}
