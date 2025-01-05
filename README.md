# Sorting Techniques in C++

This repository contains a collection of sorting algorithms implemented in C++. These algorithms are designed for both educational purposes and practical use, demonstrating various sorting techniques with different time and space complexities.

---

## 📋 List of Sorting Algorithms

The following sorting algorithms are implemented in the `Sorting_Techniques.cpp` file:

1. **Bubble Sort**  
   - Compares adjacent elements and swaps them if they are in the wrong order.  
   - Time Complexity:  
     - Worst Case: O(N²)  
     - Best Case: O(N) (adaptive if the array is already sorted).  

2. **Insertion Sort**  
   - Builds the sorted array one element at a time by shifting elements to their correct position.  
   - Time Complexity:  
     - Worst Case: O(N²)  
     - Best Case: O(N) (adaptive and stable).  

3. **Selection Sort**  
   - Finds the smallest element from the unsorted part and swaps it with the first unsorted element.  
   - Time Complexity:  
     - Always O(N²) (non-adaptive).

4. **Merge Sort (Iterative and Recursive)**  
   - Divides the list into smaller parts, sorts them, and merges them back together using a divide-and-conquer approach.  
   - Time Complexity: O(N log N)  
   - Stable sorting algorithm.

5. **Quick Sort**  
   - Partitions the array using a pivot element and recursively sorts the partitions.  
   - Time Complexity:  
     - Worst Case: O(N²)  
     - Average Case: O(N log N).  
   - In-place but not stable.

6. **Counting Sort**  
   - Counts the occurrences of each element and constructs the sorted array based on the counts.  
   - Time Complexity: O(N + K), where `K` is the range of input values.  
   - Suitable for small-range integer data.

7. **Bucket Sort**  
   - Distributes elements into buckets, sorts each bucket individually, and then combines them.  
   - Time Complexity: O(N) (ideal case).

8. **Radix Sort** *(Not Yet Implemented)*  
   - A non-comparative sorting algorithm that processes integers digit by digit.  
   - Time Complexity: O(N × d), where `d` is the number of digits in the largest number.

---

## 🛠️ File Structure

The implementation of all the sorting algorithms is available in a single file:  
`Sorting_Techniques.cpp`.

The file also includes a testable `main()` function with a sample vector of integers to demonstrate the algorithms. Uncomment the desired sorting function call in `main()` to test it.

