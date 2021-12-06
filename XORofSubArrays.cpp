// C++ program to get total
// xor of all subarray xors

// Given an array of integers, 
// we need to get the total XOR of all subarray XORs 
// where subarray XOR can be obtained by XORing all elements of it.
// Examples : 
// Input : arr[] = [3, 5, 2, 4, 6]
// Output : 7
// Total XOR of all subarray XORs is,
// (3) ^ (5) ^ (2) ^ (4) ^ (6)
// (3^5) ^ (5^2) ^ (2^4) ^ (4^6)
// (3^5^2) ^ (5^2^4) ^ (2^4^6)
// (3^5^2^4) ^ (5^2^4^6) ^
// (3^5^2^4^6) = 7     

// Input : arr[] = {1, 2, 3}
// Output : 2

// Input : arr[] = {1, 2, 3, 4}
// Output : 0

#include <bits/stdc++.h>
using namespace std;

// Returns XOR of all subarray xors
int getTotalXorOfSubarrayXors(int arr[],
							int N)
{
	// initialize result by 0
	// as (a XOR 0 = a)
	int res = 0;

	// loop over all elements once
	for (int i = 0; i < N; i++)
	{
		// get the frequency of
		// current element
		int freq = (i + 1) * (N - i); // freq = 5, 8, 9, 8, 5

		// Uncomment below line to print
		// the frequency of arr[i]
		// cout << arr[i] << " " << freq << endl;

		// if frequency is odd, then
		// include it in the result
		if (freq % 2 == 1) // 5%2,9%2, 5%2
			res = res ^ arr[i]; // res = 3, 1, 6, 7 
	}

	// return the result
	return res;
}

// Driver Code
int main()
{
	int arr[] = {1,2,3,4};
    // int arr[] = {1,2,3};
    // int arr[] = {3,5,2,4,6}
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << getTotalXorOfSubarrayXors(arr, N);
	return 0;
}

// 101
// 110
// 011