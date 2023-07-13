#include<stdio.h>
#include<stdlib.h>
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Heapify(int Heap[], int i,int length){
    int largest=0;
    int lson=0;
    int rson=0;
    int parent=i;
    while(parent <= length ){
        largest=parent;
        lson=2*parent;
        rson=2*parent+1;
        if(lson <= length && Heap[largest] < Heap[lson]){
            largest=lson;
        }
        if(rson <= length && Heap[largest] < Heap[rson]){
            largest=rson;
        }
        if(largest != parent){
            swap(Heap[largest],Heap[parent]);
            parent=largest;
        }
        else{
            break;
        }
    }
    return;
}
void Heapify_Recursion(int Heap[],int i,int length){
    
    int largest=i;
    int lson=2*i;
    int rson=2*i+1;
    
    if(lson <= length && Heap[largest] < Heap[lson]){
        largest=lson;
    }
    if(rson <= length && Heap[largest] < Heap[rson]){
        largest=rson;
    }
    if(largest != i){
        swap(Heap[largest],Heap[i]);
        Heapify(Heap,largest,length);
    }

}

void HeapBuild(int Heap[],int length){
    int i=0;
    for(i=length/2;i>=1;i--){
        Heapify(Heap,i,length);
    }

}

void Heap_sort(int Heap[],int length){
    int i=0;
    for(i=1;i<=length;i++){
        swap(Heap[1],Heap[length-i+1]);
        Heapify(Heap,1,length-i);
    }
}

void Print(int Heap[],int length){
    for(int i=1;i<=length;i++){
        printf("%d ",Heap[i]);
    }
    printf("\n");
}


int main()
{
    int Heap[]={-1,2,3,8,1,4,9,10,7,16,14};
    int n=10;
    HeapBuild(Heap,n);
    Heap_sort(Heap,n);
    Print(Heap,n);
    return 0;
}