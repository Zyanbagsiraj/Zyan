#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	// Function to perform selection sort
	void selectionSort(int arr[], int n) {
 	   for (int i = 0; i < n - 1; ++i) {
   	     int minIndex = i;
       	 for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        	}
        	// Swap the found minimum element with the first element
       	 int temp = arr[minIndex];
       	 arr[minIndex] = arr[i];
      	  arr[i] = temp;
   	 }
	}

	int main() {
    	srand(time(NULL)); // Seed for random number generation

   	 const int numPoints = 10; // Number of data points
   	 const int startingN = 5000; // Starting value of n
   	 const int stepSize = 5000; // Step size for increasing n
  	   printf("n\tTime (seconds)\n");

 	   // Loop through different values of n and record time taken
        	for (int i = 0; i < numPoints; ++i) {
       	 int n = startingN + i * stepSize;
       	 int* arr = (int*)malloc(n * sizeof(int));

        	// Generate random numbers
        	for (int j = 0; j < n; ++j) {
            arr[j] = rand();
        	}

      	  // Measure time taken for sorting
        	clock_t start = clock();
       	 selectionSort(arr, n);
        	clock_t end = clock();

       	 double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
       	 printf("%d\t%f\n", n, timeTaken);

        	free(arr); // Free memory allocated for array
   	 }

   	 return 0;
	}
