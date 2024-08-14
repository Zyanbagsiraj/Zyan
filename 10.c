#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	// Function to swap two integers
	void swap(int* a, int* b) {
   	 int temp = *a;
   	 *a = *b;
    	*b = temp;
	}

	// Function to partition the array for quick sort
	int partition(int arr[], int low, int high) {
  	  int pivot = arr[high];
 	   int i = low - 1;

 	   for (int j = low; j <= high - 1; j++) {
       	 if (arr[j] < pivot) {
        	    i++;
           	 swap(&arr[i], &arr[j]);
       	 }
   	 }
   	 swap(&arr[i + 1], &arr[high]);
   	 return i + 1;
	}

	// Quick Sort function
	void quickSort(int arr[], int low, int high) {
  	  if (low < high) {
    	    int pi = partition(arr, low, high);

     	   quickSort(arr, low, pi - 1);
     	   quickSort(arr, pi + 1, high);
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
       	 quickSort(arr, 0, n - 1);
      	  clock_t end = clock();

       	 double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
       	 printf("%d\t%f\n", n, timeTaken);

      	  free(arr); // Free memory allocated for array
    	}

    	return 0;
	}
