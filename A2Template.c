/*

 Assignment 2 ECSE202
 This program assumes that
 a names and IDs data file (location and name) is passed as the first argument
 a marks data files is passed as the second argument
 an ID number is passed as the third argument
 */
#define MAXRECORDS 100
#define MAXNAMELENGTH 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define structure to hold student data
struct StudentRecord
{
	char FirstNames[MAXNAMELENGTH];
	char LastNames[MAXNAMELENGTH];
	int IDNums;
	int Marks;
};
void swap(int a, int b, struct StudentRecord *arr[MAXRECORDS]){
  struct StudentRecord *t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}
// int parr(int arr[]){
//   for (int i=0; i < 15; i ++){
//     printf("%d ", num[i]);
//   }
//   printf("\n");
// }
int pivot(int left, int right, struct StudentRecord *arr[]){
  // char pivot[15]  = arr[left]->LastNames; //pivot value defined as first element in partition
  int i = left; //storing location of last swap, also tracks the number of elements below partition
  for (int k = left + 1; k<=right; k++ ){
    // printf("arr[k] = %d, i = %d\n", arr[k], i);
    if(strcmp(arr[k]->LastNames , arr[left]->LastNames) <= 	0){
      i++;
      swap(i,k,arr);
      //printf("Swap\n" );
    }
  }
  swap(left, i, arr);
  return  i;
}
int quickSort(int left, int right, struct StudentRecord *arr[]){
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
      quickSort(npivot +1 , right, arr);
  }
}

int main(int argc, char * argv[]) {

	struct StudentRecord SRecords[MAXRECORDS];
	struct StudentRecord *pSRecords[MAXRECORDS];
    	int numrecords, nummarks, recordnum;
	for(int i  = 0; i < MAXRECORDS; i ++){
		pSRecords[i] = &SRecords[i];
	}

	//Read in Names and ID data
	FILE * NamesIDsDataFile;
	if((NamesIDsDataFile = fopen(argv[1], "r")) == NULL){
		printf("Can't read from file %s\n", argv[1]);
		exit(1);
	}

	numrecords=0;
    	while (fscanf(NamesIDsDataFile,"%s%s%d",&(SRecords[numrecords].FirstNames[0]),
		      				&(SRecords[numrecords].LastNames[0]),
		      				&(SRecords[numrecords].IDNums)) != EOF) {
	  numrecords++;
 	}

	fclose(NamesIDsDataFile);

	//Read in marks data
	FILE * MarksDataFile;
	if((MarksDataFile = fopen(argv[2], "r")) == NULL){
		printf("Can't read from file %s\n", argv[2]);
		exit(1);
	}
	nummarks=0;
	while(fscanf(MarksDataFile,"%d",&(SRecords[nummarks].Marks)) != EOF) {
	    nummarks++;
	}

	fclose(MarksDataFile);

	int ret = strcmp(SRecords[0].FirstNames , SRecords[1].FirstNames);
	if(ret < 0) {
		 printf("str1 is less than str2");
	} else if(ret > 0) {
		 printf("str2 is less than str1");
	} else {
		 printf("str1 is equal to str2");
	}
	//Print out data as read in
	//actual values
	for(recordnum=0;recordnum<numrecords;recordnum++){
		printf("%s\n",pSRecords[recordnum]->LastNames);
	}
	quickSort(0,50,pSRecords);
	printf("\n\n\n");
	for(recordnum=0;recordnum<numrecords;recordnum++){
		printf("%s\n",SRecords[recordnum].LastNames);
	}
	printf("sorted list\n\n");
	for(recordnum=0;recordnum<numrecords;recordnum++){
		printf("%s\n",pSRecords[recordnum]->LastNames);
	}
	// printf("A total of %d records printed.\n",numrecords);
	// swap(0,1,pSRecords);
	// for(recordnum=0;recordnum<2;recordnum++){
	// 	printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
	// }
	// for(recordnum=0;recordnum<2;recordnum++){
	// 	printf("%s %s %d %d\n",pSRecords[recordnum]->FirstNames);
	// }
	return EXIT_SUCCESS;
}
