#include<stdio.h>

int swap(int a, int b, int arr[]){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;

  for (int i=0; i < 3; i ++){
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char const *argv[]) {
  int num[3] = {1,2,3};
  swap(0,3,num);
  // for (int i=0; i < 3; i ++){
  //   printf("%d\n", num[i]);
  // }
  return 0;
}
