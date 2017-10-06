#include<stdio.h>
int num[15] = {5,1,2,3,4,7,9,8,10,6,14,15,11,12,13};
int swap(int a, int b, int arr[]){
  //printf("swapping %d, with %d\n", a, b);
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
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
  printf("pivot is %d\n", pivot);
  for (int k = left+1; k<=right; k++ ){
    //  printf("arr[k] = %d, i = %d\n", arr[k], i);
    if(arr[k] <= pivot){
      i++;
      swap(i,k,arr);
      //printf("Swap\n" );
    }
  }
  swap(left, i, arr);
  parr(num);
  return  i;
}
int quickSort(int left, int right, int arr[]){

    // if (left > right){
    //   printf("moving up stack\n");
    // }
  if (left < right)
  {
    int npivot = pivot(left, right, arr);
    printf("left = %d, right  = %d\n\n",left, right);

      // Separately sort elements before
      // partition and after partition
      printf("lower partition\n\n");
      quickSort(left, npivot - 1, arr);
      printf("upper partition\n\n");
      quickSort(npivot+1, right, arr);
  }
}
int main(int argc, char const *argv[]) {
  parr(num);
  quickSort(0,14, num);
  parr(num);
  return 0;
}
