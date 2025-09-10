
#include <stdio.h>
#include <conio.h>

int binary_search(int array[],int lb, int ub, int ele){
if(lb<=ub){
int mid=lb+(ub-lb)/2;
if(array[mid]==ele)
    return mid;
 if(array[mid]>ele)
    return binary_search(array,lb,mid-1,ele);
return binary_search(array,mid+1,ub,ele);
}
return -1;
}


void swap(int *a,int *b){
int t = *a;
*a = *b;
*b = t;
}

int partition(int array[], int low, int high){
int pivot = array[high];
int i = (low - 1);
for (int j=low;j<=high-1;j++){
    if (array[j]<= pivot){
    i++;
    swap(&array[i], &array[j]);
    }
}
swap(&array[i+1],&array[high]);
return (i+1);
}

void quicksort(int array[], int low , int high){
if (low<high){
    int pi = partition(array,low,high);
    quicksort(array,low,pi-1);
    quicksort(array,pi+1,high);
}
}

void printarray(int array[],int size){
for(int i = 0;i < size; i++){
    printf("\t%d",array[i]);
}
}



int main(){
int array[10],i,size,ele;
printf("\n Enter the size of the array: ");
scanf("%d",&size);
for(i=0;i<size;i++){
    printf("Enter element no. %d : ",i+1);
    scanf("%d",&array[i]);
}
printf("\n");
printf("sorting the array using quick sort algorithm: ");
quicksort(array,0,size-1);
printarray(array,size);
printf("\n Enter the element you want to search for: ");
scanf("%d",&ele);
printf("\n");
printf("Searching the element in the array using binary search algorithm");
printf("\n");
int result = binary_search(array,0,size-1,ele);
if (result == -1)
    printf("\n**ELEMENT NOT FOUND!**");
else
    printf("\n**ELEMENT FOUND!** at position %d",result+1);

return ;
}
