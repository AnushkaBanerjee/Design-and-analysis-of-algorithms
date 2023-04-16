/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Function to swap numbers
void
swap (int *num1, int *num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

//Partition Function
int
partition (int arr[], int low, int high)
{
  int pivot = arr[high];
  int indx1 = (low - 1);
  int indx2;
  for (indx2 = low; indx2 <= high - 1; indx2++)
    {
      if (arr[indx2] <= pivot)
	{
	  indx1++;
	  swap (&arr[indx1], &arr[indx2]);
	}
    }
  swap (&arr[indx1 + 1], &arr[high]);
  return (indx1 + 1);
}

// Quick Sort function
void
quicksort (int Arr[], int low, int high)
{
  if (low < high)
    {
      // pi = Partition index
      int pi = partition (Arr, low, high);
      quicksort (Arr, low, pi - 1);
      quicksort (Arr, pi + 1, high);
    }
}


void merge(int arr[], int left, int mid, int right)
{
    int indx1, indx2, indx;
    int size_arr_1 = mid - left + 1;
    int size_arr_2 = right - mid;
 
    /* create temp arrays */
    int left_arr[size_arr_1], right_arr[size_arr_2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (indx1 = 0; indx1 < size_arr_1; indx1++)
        left_arr[indx1] = arr[left + indx1];
    for (indx2 = 0; indx2 < size_arr_2; indx2++)
        right_arr[indx2] = arr[mid + 1 + indx2];
 
    /* Merge the temp arrays back into arr[l..r]*/
    indx1 = 0; // Initial index of first subarray
    indx2 = 0; // Initial index of second subarray
    indx = left; // Initial index of merged subarray
    while (indx1 < size_arr_1 && indx2 <size_arr_2) {
        if (left_arr[indx1] <= right_arr[indx2]) {
            arr[indx] = left_arr[indx1];
            indx1++;
        }
        else {
            arr[indx] = right_arr[indx2];
            indx2++;
        }
        indx++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (indx1 < size_arr_1) {
        arr[indx] = left_arr[indx1];
        indx1++;
        indx++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (indx2 < size_arr_2) {
        arr[indx] = right_arr[indx2];
        indx2++;
        indx++;
    }
}
 

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
       
        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        merge(arr, left, mid, right);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void
printArray (int A[], int size)
{
  for (int indx = 0; indx < size; indx++)
    printf ("%d ", A[indx]);
  printf ("\n");
}

/* Driver code */
int
main ()
{
  int *arr, size, choice;
  clock_t start,end;
  double total_time_merge,total_time_quicksort;

  printf ("Enter the size of the array: ");
  scanf ("%d", &size);

  arr = (int *) malloc (size * (sizeof (int)));

  for (int indx = 0; indx < size; indx++)
    {
      arr[indx]=rand();
    }

  printf ("\n-----MENU-----\n1.Merge Sort.\n2.Quick Sort.");
  printf ("\nEnter your choice: ");
  scanf ("%d", &choice);
  switch (choice)
    {
    case 1:
      {
        start = clock();  
	mergeSort (arr, 0, size - 1);
	end = clock();
	total_time_merge = (double)(end-start)/CLOCKS_PER_SEC;
	printf("%f is the time taken to execute the mergeSort function",total_time_merge);
	break;
      }

    case 2:
      {
          start = clock(); 
	quicksort (arr, 0, size - 1);
	end = clock();
	total_time_quicksort = (double)(end-start)/CLOCKS_PER_SEC;
	printf("%f is the time taken to execute quickSort function",total_time_quicksort);
	break;
      }
    default:
      {
	printf ("\nWrong Choice!!\nEnter a valid choice.");
	break;
      }
    }
  return 0;
}



