
// C++ program for insertion sort  
#include <bits/stdc++.h>
#include <chrono>
#include <thread> 
using namespace std;
  
// function for insertion sort
void ins_sort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        // for each item that is key move all the elements of the array[0..i-1]
        // that are greater than key,to one position ahead of there current position
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// function to print the array when array and its size is given 
void show_arr(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";  
    }  
    cout << endl; 
}  
  
int main()  
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif   
    // Input format
    // first line contains a single integer n that is the size of the array
    // second line contains n space seperated integers the elements of the array
    int n;
    cin>>n;
    int arr[n+5];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    // array before sorting
    show_arr(arr,n);
    clock_t time_req; 
    // we start the clock before calling ins_sort function
    time_req = clock(); 
    ins_sort(arr,n);
    cout.flush();
    std::this_thread::sleep_for (std::chrono::seconds(1));
    // and stop the clock after sorting is done using ins_sort
    time_req = clock()- time_req; 
    cout << "Processor time taken for sorting using insertion sort : "
        << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 
  
    // printing the sorted array
    show_arr(arr,n); 
  
    return 0;  
}  
  
// This is code is contributed by rathbhupendra 