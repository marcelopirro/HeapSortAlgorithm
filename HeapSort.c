#include <stdio.h>

void swap(int *a, int *b);
void printArray(int array[], int n); //function to print a array
void heapify(int array[], int n, int i); //To heapify a subtree with node i as root. Size of heap is n
void buildHeap(int array[], int n); //fuction to build a Max-Heap from given array

int main(){
    int size;
    printf("define the size of array: ");
    scanf("%d", &size);
    int array[size];
    printf("insert the values:");
    for(int i=0; i<size; i++){
        scanf("%d", &array[i]);
    }
    //print array
    printf("Array is:\n");
    printArray(array, size);
    
    //printf the new array
    buildHeap(array, size);
    printf("Array representation of Heap is :");
    printArray(array, size);
    return 0;
}
void swap(int *a, int *b){
    int temp = *b;
    *b=*a;
    *a=temp;
}
void printArray(int array[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void heapify(int array[], int n, int i){
    int largest=i; //initialize largest as root
    int leftChild=2*i+1; //left child 2*i+1
    int rightChild=2*i+2; //right child 2*i+1

    //If left child is grater than root
    if(leftChild < n && array[leftChild]>array[largest])
    largest=leftChild;

    //if right child is grater than new largest
    if(rightChild< n && array[rightChild]>array[largest])
    largest=rightChild;

    //if largest is not the root
    if(largest !=i){
        //swap root whit the new largest
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void buildHeap(int array[], int n){
    //index of last non-leaf node
    int lastNonLeafNode = (n/2) - 1;
    for (int i = lastNonLeafNode; i>=0; i--){
        heapify(array, n, i);
    }
}

