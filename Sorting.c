#include <stdio.h>
#include <stdlib.h>

//bubble sort with modification to deal with sorted array
void bubblesort(int* arr,int n){
  int temp,isSorted;
  for(int i=0;i<n-1;i++){
    printf("pass no.:%d: ",i);
    isSorted=1;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        isSorted=0;
      }
    }
    if(isSorted){
      return;
    }
  }
}

//insertion sort
void insertionsort(int* A, int n){
  int key;
  for(int i=1;i<=n-1;i++){
    key=A[i];
    int j=i-1;
    while(j>-1&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
}

//selection sort

void selectionsort(int* A,int n){
  int temp,indexOfMin;
  for(int i=0;i<n-1;i++){//loop for a pass
    indexOfMin=i;
    for(int j=i+1;j<n;j++){
      if(A[indexOfMin]>A[j]){
        indexOfMin=j;
      }
    }
    temp=A[i];
    A[i]=A[indexOfMin];
    A[indexOfMin]=temp;
  }
}
//a probably anoymous sorting algorithm
void abctionsort(int* A,int n){
  int temp;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(A[i]>A[j]){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }
    }
  }
}

//quick sort



/void quicksort(int A,int low,int high){
  int partitionIndex;
  partitionIndex=part
}*/

//merge sort
void merge(int A[], int mid, int low, int high){
  int i,j,k;
  int* B=malloc((high-low+1)*sizeof(int));//reqest memory in heap
  if(B==NULL){
    printf("memory allocation failed!");
    return;
  }
  i=low;
  j=mid+1;
  k=0;//starting from 0
  while(i<=mid&&j<=high){
    if(A[i]<=A[j]){//line 1:here instead of <, <= is used; this makes this algo stable
      B[k]=A[i];
      i++;
      k++;
    }
    else{
      B[k]=A[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    B[k]=A[i];
    i++;
    k++;
  }
  while(j<=high){
    B[k]=A[j];
    j++;
    k++;
  }
  for(int i=low,j=0;i<=high;i++,j++){//2 different variables are used
    A[i]=B[j];
  }
  free(B);//freeing B
}

void mergesort(int A[],int low,int high){
  if(low<high){
    int mid=(low+high)/2;
    mergesort(A,low,mid);//this is a recursive algo
    mergesort(A,mid+1,high);
    merge(A,mid,low,high);
  }
}

//count sort
void countsort(int A[],int n){
  //finding largest val
  int max=A[0];
  for(int i=1;i<n;i++){
    if(max<A[i]){
      max=A[i];
    }
  }
  
  //creating count array
  int B=(int)calloc(max+1,sizeof(int));
  if(B==NULL){
    printf("memory allocation failed!");
    return;
  }
  for(int i=0;i<n;i++){
    B[A[i]]++;
  }
  
  //copying back
  for(int i=0,j=0;i<=max;i++){
    while(B[i]!=0){
      A[j]=i;
      B[i]--;
      j++;
    }
  }
  free(B);//freeing B
}

void printArray(int *arr,int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int main() {
  int a[8]={23,5,83,34,24,34,35,67};
  int a2[5]={1,3,2,4,5};
  countsort(a,8);
  printArray(a,8);
  countsort(a2,5);
  printArray(a2,5);
  return 0;
}