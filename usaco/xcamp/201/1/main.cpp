#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void mergesort(int n[], int left, int right){
    int mid;
    if(left>right) return;
    mid = (left+right)/2;
    mergesort(n,left,mid);
    mergesort(n,mid+1,left);

}

int main(){
    int array[3] = {3,2,1};
    mergesort(array);
}