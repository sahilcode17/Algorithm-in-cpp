

#include <stdio.h>
#include <limits.h>
using namespace std ;

int max(int a, int b) { return (a > b)? a : b; }


int max(int a, int b, int c) { return max(max(a, b), c); }


int MaxCrossingSum(int arr[] , int l , int mid , int h){
    int sum = 0 ;
    int leftsum = INT_MIN;
    for(int i = mid ; i>=l ; i--){
        sum+= arr[i];
        if(sum>leftsum)
            leftsum = sum;

    }
      sum = 0 ;
    int rightsum = INT_MIN;

    for(int i = mid+1 ; i<=h ; i++){
        sum+= arr[i];
        if(sum>rightsum)
            rightsum = sum;

    }
        return max(rightsum+leftsum , rightsum , leftsum);
}

int MaxSumSubarray(int arr[] , int l , int h){
   if(l==h){
       return arr[l];
   }
       int mid = (l + h)/2;
        return  max(MaxSumSubarray(arr , l , mid) ,
        MaxSumSubarray(arr , mid+1 , h) ,
        MaxCrossingSum(arr , l , mid , h));

}

int main()
{

int arr[] = {2, 3, 4, 5, 7};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = MaxSumSubarray(arr, 0, n-1);
  printf("%dn" , max_sum) ;
  getchar();
return 0;
}
