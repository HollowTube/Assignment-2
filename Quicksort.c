#include<stdio.h>
int num[20] = {15,98,160,1341,69,12,12,16,14,23,153,256,20,485,264,985,1002,521,785,111};
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
  for (int k = left + 1; k<=right; k++ ){
    // printf("arr[k] = %d, i = %d\n", arr[k], i);
    if(arr[k] <= pivot){
      i++;
      swap(i,k,arr);
      //printf("Swap\n" );
      // for (int i=0; i < 10; i ++){
      //   printf("%d", num[i]);
      // }
      // printf("\n");
    }
  }
  swap(left, i, arr);
  for (int i=0; i < 20; i ++){
    printf("%d ", num[i]);
  }
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

  quickSort(0,20, num);
  for (int i=0; i < 20; i ++){
    printf("%d ", num[i]);
  }
  return 0;
}
