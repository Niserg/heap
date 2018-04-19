#include <iostream>

using namespace std;

class MaxHeap
{
 int ar[50];
 int index;
 public:
 void display(int);
 void displayHeap();
 void swap(int, int);
 int Delete();
 void insert(int);
 MaxHeap();
};

MaxHeap :: MaxHeap()
{
 for(int i =0; i<50; ++i) ar[i] = 0;
 index =-1;
}

void MaxHeap :: swap(int a, int b)
{
 int t = ar[a];
 ar[a] = ar[b];
 ar[b] = t;
}

void MaxHeap :: insert(int n)
{
 ar[++index] = n;
 int i = index, par = (index-1)/2;
 while(n > ar[par])
 {
  if(par < 0) break;
  swap(par,i);
  i = par; 
  par = (par-1)/2;
 }
}

int MaxHeap :: Delete()
{
 int i, n, n2, ch;
 if(index >= 0) 
   {
    n = ar[index];
    n2 = ar[0];
    i =0;
    swap(0, index);
    ar[index--] = 0;
   }
 else return -1;

 if(index > 0)
 while(n<ar[2*i+1])
 {
  if(i > index) break;
  ch = ((ar[2*i+1]>ar[2*i+2]) ? (2*i+1) : (2*i+2));
  swap(ch,i);
  i = ch;
 }
 return n2;
}  
  
void MaxHeap :: display(int n)
{
  int i, pos =-1;
  for(i =0; i<index; ++i)
    if(ar[i] == n)
	 break;
  pos = i;
  if(pos == -1)
     cout << "\nElement found.";
  else
  {
   if((pos-1)/2 > 0) 
     cout << "\nThe element has parent : "<< ar[(pos-1)/2];
   else cout << "\nNo parent.";
   if((2*pos+1) < index)
     cout << "\nThe element has left child : "<< ar[2*pos+1];
   if(2*pos+2 < index) 
     cout << "\nThe element has right child : "<< ar[2*pos+2];
   else cout << "\nThe element has no child.";
  }  
}

/*void MaxHeap :: displayHeap()
{
  
}
*/

int main()
{
 MaxHeap H;
 int choice, data;
 char ch = 'y';
 cout << "\nProgrm to implement a max heap.";
 do
 {
  cout << "\nOPTIONS :\n\t1.insert\n\t2.delete\n\t3.display heap\n\t4.display a node\n";
  cin >> choice;
  switch(choice) 
  {
   case 1 :     cout << "\nEnter the integer element it will store :";
 		cin >> data;
		H.insert(data);
 		break;
   case 2 : 	cout << "\nDeleting ...";
 		data = H.Delete();
		if(data == -1) cout << "\nNo element to delete.";
		else cout << "\nSuccessfully deleted :"<< data;
		break;
   case 3 :     break;
   case 4 : 	cout << "\nEnter the element stored in node : ";
		cin >> data;
		H.display(data);
		break;
   default: 	cout << "\nWrong choice!!";
		break; 
  }

  cout << "\nWanna do again? (enter y for yes): ";
  cin >> ch;

 }while(ch == 'y' || ch == 'Y');
 
return 0;
}
