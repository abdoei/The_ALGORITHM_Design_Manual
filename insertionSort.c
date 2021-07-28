#include <stdio.h>

void swap(int *xp, int *yp)	// this function is not mine
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int n = 0;
    int arr[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    for (int i = 0; arr[i] != 0; i++)
        n++;

    //bubble sort
    /*
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
*/

    /*
    selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
                minInd = j;
        }
        arr[i] = arr[i] + arr[minInd];		//this methode is called swap without variable 
        arr[minInd] = arr[i] - arr[minInd];	//this methode is not appicable in this sorting algorithm
        arr[i] = arr[i] - arr[minInd];		//cuz if an element is in its proper place it is going to be 0
    }
*/

    int lastj = 0;	// For each iteration of the the outer for loop,in the inner loop if the program entered the 
    				// "if body" we want to know where the moving of elements stopped to insert the proper element
	int active = 0;	// To know if any changes happened to the array in this whole outer iteration to make the insertion
    int i = 1, j, temp;
	for (; i < n - 1; i++)	// for each of the unsorted elements
    {
        temp = arr[i + 1];		// hold the value of the first unsorted element as it is going to be overwritten
        active = 0;					// to know if the program entered the if body or not in the whole outer iteration
        j = i
		for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                lastj = j;
                active = 1;
            }
        }
        if (active == 1)
            arr[lastj] = temp;
    }
	
	// printing the sorted array
    for (int i = 0; i < n; i++)
        printf("%d,", arr[i]);

    return 0;
}
