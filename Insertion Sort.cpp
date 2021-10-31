#include<iostream>
using namespace std;
void insertion_sort(int a[],int n){
for(int i=1;i<n;i++)
{
    int value = a[i];
    int hole = i;
    while(hole > 0 && a[hole-1] > value)
    {
        a[hole] = a[hole-1];
        a[hole-1] = value;
        hole--;
    }
}
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    return 0;
}
// Time Complexity : O(n^2)
