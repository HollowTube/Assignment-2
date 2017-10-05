#include<stdio.h>
// int parr(int arr[]){
//   for (int i=0; i < 5; i ++){
//     printf("%d ", arr[i]);
//   }
//   printf("\n");
// }
// int swap(int** a, int** b, int *arr){
//   int *temp = *arr[a];
//   *arr[a] = *arr[b];
//   *arr[b] = temp;
// }
struct items{
  int price;
};

// void swap1(struct items *a struct items *b){
//   struct items t = *a;
//   *a = *b;
//   *b = t;
// }

// void swap2(int a, int b, struct items *arr[]){
//   struct items t = &arr[a];
//   arr[a] = &arr[b];
//   &arr[b] = t;
//   printf("done");
// }
void swap2(int a, int b, struct items *arr[]){
  struct items *t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

void swap(int a, int b, struct items arr[2]){
  struct items t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

int main(){
  struct items book[2];
  struct items *pbook[2];
  for (size_t i = 0; i < 2; i++) {
    pbook[i] = & book[i];
  }
  book[0].price = 10;
  book[1].price = 15;
  printf("%d\n", pbook[0]->price);
  printf("%d\n", pbook[1]->price);
  swap2(0,1,pbook);
  printf("%d\n", pbook[0]->price);
  printf("%d\n", pbook[1]->price);
  printf("%d\n", book[0].price);
  printf("%d\n", book[1].price);
  // swap3(0,1,book);
  // printf("%d\n", book[0].price);
  // printf("%d\n", book[1].price);
  // struct items book;
  // book.price = 15;
  // printf("%d\n", book.price);
  // int num[5] = {5,4,3,2,1};
  // int *pnum[5] = {0};
  // for (size_t i = 0; i <5 ; i++) {
  //   pnum[i] = &num[i];
  // }
  // // parr(pnum);
  // swap(1,2,pnum);
  // for (int i=0; i < 5; i ++){
  //   printf("%d", *pnum[i]);
  // }
  // printf("\n");
  return 0;
}
