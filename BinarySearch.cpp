
#include <bits/stdc++.h>

using namespace std;


int BinarySearch(int arr[] , int l ,int h , int key)
{
if(h>=1){

    int mid = l+(h-1)/2;

    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        return BinarySearch(arr , l , mid - 1 , key);
    }
    else{
       return BinarySearch(arr , mid + 1 , h , key);
    }
    }
    return - 1;
    }

int main()
{
   int n;
   cin >> n;
   int arr[n];
for (int i = 0; i < n; ++i)
{
    cin >> arr[i];
}
   int key;
   cin >> key ;
	int result = BinarySearch(arr, 0, n - 1, key);
	cout << "Index is at : " << result;
	return 0;
}

