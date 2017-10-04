#include<stdio.h>
int num[10] = {5,8,6,1,9,0,2,3,4,7};
int swap(int a, int b, int arr[]){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
  // for (int i=0; i < 10; i ++){
  //   printf("%d ", num[i]);
  // }
}

int pivot(int left, int right, int arr[]){
  int pivot  = arr[left]; //pivot value defined as first element in partition
  int i = left; //storing location of last swap, also tracks the number of elements below partition
  for (int k = left + 1; k< right; k++ ){
    printf("arr[k] = %d, i = %d\n", arr[k], i);
    if(arr[k] < pivot){
      i++;
      swap(i,k,arr);
      printf("Swap\n" );
      for (int i=0; i < 10; i ++){
        printf("%d", num[i]);
      }
      printf("\n");
    }
  }
  swap(left, i, arr);
  return 1;
}

int main(int argc, char const *argv[]) {

  pivot(0,10,num);
  for (int i=0; i < 10; i ++){
    printf("\n ");
    printf("%d ", num[i]);
  }
  return 0;
}
