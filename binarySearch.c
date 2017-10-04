#include <stdio.h>
int binarySearch(int goal, int arr[]){
  int left = 0;
  int right  = 9;
  int middle  = (left + right)/2;
  while (left <= right){
    if(arr[middle] < goal){
      left = middle + 1;
    }
    else if(arr[middle] == goal){
      printf("found at location %d \n", middle);
      break;
    }
    else{
      right = middle - 1;
    }
    int middle  = (left + right)/2;
  }
  if(left > right){
    printf("not found");
  }
}
int main(int argc, char const *argv[]) {
  int num[10] = {1,12,25,45,46,68,79,100,145,167};
  binarySearch(25, num);
  return 0;
}
