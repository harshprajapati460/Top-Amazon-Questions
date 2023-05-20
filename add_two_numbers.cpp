#include<bits/stdc++.h>
using namespace std;

// Function to return total valid pairs
int ValidPairs(int arr[],int n)
{

	// Initialize count of all the elements
	int count[121]={0};

	// frequency count of all the elements
	for(int i=0;i<n;i++)
		count[arr[i]] += 1;

	int ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if( arr[i] > arr[j])
				continue;
			if (arr[i] - arr[j] % 2 == 1)
				continue;

			// Add total valid pairs
			ans += count[arr[i]]* count[arr[j]];
			if (arr[i] == arr[j])

				// Exclude pairs made with a single element
				// i.e. (x, x)
				ans -= count[arr[i]];
		}
	return ans;
}

// Driver Code
int main()
{
    int n;
    cin>>n;
int arr[n];
for(int i=0; i<n;i++){
    cin>>arr[i];
}
// Function call to print required answer
cout<<(ValidPairs(arr,n));
return 0;
}