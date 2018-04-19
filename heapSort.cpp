#include <iostream>

using namespace std;

class MaxHeap
{
 int ar[50];
 int length;

 public :
 MaxHeap(int);
 void Heapify(int, int);
 void swap(int, int);
 void HeapSort();
};


MaxHeap :: MaxHeap(int size)
{
 length = size;

 cout << "\nEnter the elements of the unsorted array :\n\t";
 for(int i =0; i<length; ++i)
 {
  cout << "\nelement ar[" << i << "] :";
  cin >> ar[i];
 }
}

 
void MaxHeap :: swap(int a, int b)
{
 int t = ar[a];
 ar[a] = ar[b];
 ar[b] = t;
}


void MaxHeap :: Heapify(int i, int j=0)
{
 int ch;
 while(1) 
 { 
   if((2*i+1) >= (length-j)) break;
   else if((2*i+2) >= (length-j)) ch = ar[2*i+1];
   else  ch = ((ar[2*i+1] > ar[2*i+2])? 2*i+1 : 2*i+2);  

   if(ar[i] < ar[ch])
     {
       swap(ch, i);
       i = ch; 
     }
 }
}
 

void MaxHeap :: HeapSort()
{
 int i = length/2 -1;
 while(i >= 0)
         Heapify(i--);

 i = length-1;

 while(i)
 {
	swap(i, 0);
	Heapify(0, length-i);
	i = i -1;
 }
 cout << "\nThe sorted array is :\n\n";
 for(i =0; i<length; ++i)
 {
  cout << "\nar[" << i << "] :";
  cout << ar[i];
 }
 cout << endl;
}


int main()
{
 int size;
 cout << "\nProgram to implement HeapSort on an array.\n";
 do{
 	 cout << "\nEnter the number of elements in your array : ";
	 cin >> size; 
	 if(size < 1) cout << "\nEnter a positive number : ";
   }while(size < 1);
 MaxHeap H = MaxHeap(size);
 cout << "\nSorting the array.\n";
 H.HeapSort();
 return 0;
}
