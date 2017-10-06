#include<stdio.h>
int num[15] = {15,98,160,1341,50,15,222,56,64,156,764,345,745,345,234};
int swap(int a, int b, int arr[]){
  //printf("swapping %d, with %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
  // parr(num);
}
int parr(int arr[]){
  for (int i=0; i < 15; i ++){
    printf("%d ", num[i]);
  }
  printf("\n");
}
int pivot(int left, int right, int arr[]){
  int pivot  = arr[left]; //pivot value defined as first element in partition
  int i = left; //storing location of last swap, also tracks the number of elements below partition
  for (int k = left + 1; k<=right-1; k++ ){
    // printf("arr[k] = %d, i = %d\n", arr[k], i);
    if(arr[k] <= pivot){
      i++;
      swap(i,k,arr);
      //printf("Swap\n" );
    }
  }
  swap(left, i, arr);
  parr(num);
  printf("\n");
  return  i;
}
int quickSort(int left, int right, int arr[]){
  int npivot = pivot(left, right, arr);
  printf("left = %d, right  = %d, pivotIndex  = %d \n",left, right, npivot);
    // if (left > right){
    //   printf("moving up stack\n");
    // }
  if (left < right)
  {
      // Separately sort elements before
      // partition and after partition
      printf("lower partition\n\n");
      quickSort(left, npivot - 1, arr);
      printf("upper partition\n\n");
      quickSort(npivot + 1, right, arr);
  }
}
int main(int argc, char const *argv[]) {
  parr(num);
  quickSort(0,15, num);
  parr(num);
  return 0;
}
