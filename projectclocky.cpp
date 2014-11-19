#include <iostream>
#include <time.h> //Clock
#include <stdio.h> // For rand() function
#include <stdlib.h>
using namespace std;
// Code haye Algorithme Linear Search:
// Big O = n
bool linearsearch (int A[], int element_number, int key)
{
    for (int i = 0; i < element_number;i++)
        {
            if (A[i] == key)
                return true;
        }
    return false;
}
// End of Linear Search

// Code haye Algorithme Bubble Sort:
// Big O = n^2
// Start
void bubbleSort(int A[] , int element_number)
{
    int temp;
    for (int i = 0; i < element_number; i++)
    {
        for(int j = 0; j<element_number - i - 1; j++)
            {
                if ( A[j] > A [j+1])
                {
                    temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }

            }
    }
}
// End of bubble sort


// Codhaye Hanoi
// Big O = 2^n
// Start
void hanoi(int diskSize, int start, int finish, int temp)
{
  if(diskSize == 1)
	{
		return;
	}
	else
	{
		hanoi(diskSize - 1, start, temp, finish);
		hanoi(diskSize - 1, temp, finish, start);
	}
}

// End of Hanoi

// Code haye Algorithme Quick Sort:
// Big O = nlogn
// Start
int part(int A[] , int left , int right)
{
	int middle ;

	int x = A[left] ;
	int l = left ;
	int r = right ;
	while(l < r){
		while((A[l] <= x) && (l < right)) l++ ;
		while((A[r] > x) && (r >= left)) r-- ;
		if(l < r){
			int temp = A[l];
			A[l] = A[r];
			A[r] = temp ;
		}
	}
	middle = r ;
		int temp = A[left];
		A[left] = A[middle] ;
		A[middle] = temp;
	return middle ;
}
void quicksort(int A[] , int left , int right){
	if (left < right){
		int middle = part(A , left , right) ;
		quicksort(A , left , middle-1) ;
		quicksort(A , middle+1 , right);
	}
}
// End of Binary Saerch

// Code Haye Binary Search
// Big O = logn
// Start

bool binarySearch(int A[], int element_number, int key)
{

    int low, mid, high;
    /*
    Technically a binary search should be done only if the array
    is sorted. But since we don't want to calculate the time that
    sorting cosumes, we ignore this part and will do it once we're
    in the main() function.
    */
    //bubbleSort(A,element_number);
    low = 0;
    high = element_number;
    do
    {
        mid = (low + high) / 2;
        if(key<A[mid])
            high = mid - 1;
        else if (key > A[high])
            low = mid + 1;
    }
    while (key != A[mid] && low <=high);

    if(key == A[mid])
        return true;
    return false;

}

// End of Binary Search


int main()
{

    //arrays:
    int aSize= 100, bSize = 1000, cSize=5000, dSize = 10000, eSize = 20000;
    int A[aSize], B[bSize], C[cSize],D[dSize], E[eSize];

    //Meghdar Dadane Araye ha

    for(int i = 0; i < aSize ; i++)
    {
        A[i] = rand() % aSize + 1;
    }
    for (int i = 0; i<bSize;i++)
    {
        B[i] = rand() % bSize + 1;
    }
    for (int i = 0; i<cSize;i++)
    {
        C[i] = rand() % cSize + 1;
    }
    for (int i = 0; i<dSize;i++)
    {
        D[i] = rand() % dSize + 1;
    }
    for (int i = 0; i<eSize;i++)
    {
        E[i] = rand() % eSize + 1;
    }




    //key Generator for Binary & linear Search:
    int aKey = rand() % aSize +1;
    int bKey = rand() % bSize +1;
    int cKey = rand() % cSize +1;
    int dKey = rand() % dSize +1;
    int eKey = rand() % eSize +1;




    //linearsearch:
    cout<<"Linear Search:"<<endl;
    //A:
    clock_t lsAtimer = clock();
    linearsearch(A,aSize,aKey);
    cout<<"CPU Time for n = "<< aSize<<" is: "
    <<clock() - lsAtimer/CLOCKS_PER_SEC<<endl;
    //B:
    clock_t lsBtimer = clock();
    linearsearch(B,bSize,bKey);
    cout<<"CPU Time for n = "<< bSize<<" is: "
    <<clock() - lsBtimer/CLOCKS_PER_SEC<<endl;
    //C:
    clock_t lsCtimer = clock();
    linearsearch(C,cSize,cKey);
    cout<<"CPU Time for n = "<< cSize<<" is: "
    <<clock() - lsCtimer/CLOCKS_PER_SEC<<endl;
    //D:
    clock_t lsDtimer = clock();
    linearsearch(D,dSize,dKey);
    cout<<"CPU Time for n = "<< dSize<<" is: "
    <<clock() - lsDtimer/CLOCKS_PER_SEC<<endl;
    //E:
    clock_t lsEtimer = clock();
    linearsearch(A,eSize,eKey);
    cout<<"CPU Time for n = "<< eSize<<" is: "
    <<clock() - lsEtimer/CLOCKS_PER_SEC<<endl;
    //End of Linear Search




    //Bubble Sort:
    cout<<"Bubble Sort:"<<endl;
    //A:
    clock_t bsortAtimer = clock();
    bubbleSort(A, aSize);
    cout<<"CPU Time for n = "<< aSize<<" is:"
    <<clock() - bsortAtimer/CLOCKS_PER_SEC<<endl;
    //B:
    clock_t bsortBtimer = clock();
    bubbleSort(B, bSize);
    cout<<"CPU Time for n = "<< bSize<<" is:"
    <<clock() - bsortBtimer/CLOCKS_PER_SEC<<endl;
    //C:
    clock_t bsortCtimer = clock();
    bubbleSort(C, cSize);
    cout<<"CPU Time for n = "<< cSize<<" is:"
    <<clock() - bsortCtimer/CLOCKS_PER_SEC<<endl;
    //D:
    clock_t bsortDtimer = clock();
    bubbleSort(D, dSize);
    cout<<"CPU Time for n = "<< dSize<<" is:"
    <<clock() - bsortDtimer/CLOCKS_PER_SEC<<endl;
    //E:
    clock_t bsortEtimer = clock();
    bubbleSort(E, eSize);
    cout<<"CPU Time for n = "<< eSize<<" is:"
    <<clock() - bsortEtimer/CLOCKS_PER_SEC<<endl;
    //End of Buble Sort



    //Hanoi:
    cout<<"Hanoi Tower Problem:"<<endl;
    //3 Disks:
    clock_t htimer3 = clock();
    hanoi(3, 1,2,3);
    cout<<"CPU Time for n = 3 is: "
    <<clock() - htimer3/CLOCKS_PER_SEC<<endl;
    //6 Disks:
    clock_t htimer6 = clock();
    hanoi(6, 1,2,3);
    cout<<"CPU Time for n = 6 is: "
    <<clock() - htimer6/CLOCKS_PER_SEC<<endl;
    //9 Disks:
    clock_t htimer9 = clock();
    hanoi(9, 1,2,3);
    cout<<"CPU Time for n = 9 is: "
    <<clock() - htimer9/CLOCKS_PER_SEC<<endl;
    //12 Disks:
    clock_t htimer12 = clock();
    hanoi(12, 1,2,3);
    cout<<"CPU Time for n = 12 is: "
    <<clock() - htimer12/CLOCKS_PER_SEC<<endl;
    //15 Disks:
    clock_t htimer15 = clock();
    hanoi(15, 1,2,3);
    cout<<"CPU Time for n = 15 is: "
    <<clock() - htimer15/CLOCKS_PER_SEC<<endl;
    //End of Hanoi Tower Problem





/*
    //Binary search logn
    //buble sorting the arrays:
    bubbleSort(A, aSize);
    bubbleSort(B, bSize);
    bubbleSort(C, cSize);
    bubbleSort(D, dSize);
    bubbleSort(E, eSize);
    //A:
    clock_t aTimer = clock();
    binarySearch(A, aSize, aKey);
    cout<<" CPU time for n = "<<aSize<<" is: "
    <<clock() - aTimer/CLOCKS_PER_SEC<<endl;
    //B:
    clock_t bTimer = clock();
    binarySearch(B, bSize, bKey);
    cout<<" CPU time for n = "<<bSize<<" is: "
    <<clock()- bTimer/CLOCKS_PER_SEC<<endl;
    //C:
    clock_t cTimer = clock();
    binarySearch(C, cSize, cKey);
    cout<<" CPU time for n = "<<cSize<<" is: "
    <<clock()- cTimer/CLOCKS_PER_SEC<<endl;
    //D:
    clock_t dTimer = clock();
    binarySearch(D, dSize, dKey);
    cout<<" CPU time for n = "<<dSize<<" is: "
    <<clock()-dTimer/CLOCKS_PER_SEC<<endl;
    //E:
    clock_t eTimer = clock();
    binarySearch(E, eSize, eKey);
    cout<<" CPU time for n = "<<eSize<<" is: "
    <<clock()-eTimer/CLOCKS_PER_SEC<<endl;
    //End of Binary Search
*/



    //Quick Sort:
    cout<<"Quick Sort:"<<endl;


    cout<<"\nWorks Perfectly so far";
    return 0;
}
