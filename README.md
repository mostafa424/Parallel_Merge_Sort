# Parallel_Merge_Sort
Mostafa Abd El Haliem Abd El Mohsen El Tawy

19016662

Lab#4

Input/Output:

Input: text file to enter input to sample runs 
1st line is number of sample runs (t) followed by t testcases each testcase contains number of elements(n) then number of processors(p) then N elements which is the array needed to be sorted.

Output: text file contains output of program in the following form:
The program shows number of elements with number of processing elements followed by the sorted array.

Logs: text file shows progress of threads throughout program.

Sample:

Input:
1

5

2

5 3 2 4 1	

Output:
n=5

p=2

sorted array:

1 2 3 4 5

CodeFlow:

The code is an implementation of parallel merge sort using multiple threads. The main logic of the program can be summarized as follows:
1.	Open input and output files and create a log file for recording the progress of the threads.
2.	Read the number of test cases and loop through each test case.
3.	Read the size of the array and the number of threads to be used for parallel sorting.
4.	If the size of the array is not divisible by the number of threads, add padding to the array to make it divisible.
5.	Compute the chunk size of each thread and create a lambda function to assign each thread to its respective part of the array.
6.	Start each thread, which calls the merge_sort function to sort its portion of the array.
7.	Wait for all threads to finish sorting.
8.	Merge the sorted subarrays using the merge function.
9.	Write the sorted array to the output file.
10.Close all input/output files and exit the program.

The merge_sort function implements the merge sort algorithm recursively by dividing the array into two halves and merging them back in sorted order. The merge function merges two sorted subarrays into a single sorted array.
