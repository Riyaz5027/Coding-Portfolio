
**Output:** single integer — print the largest array element if exists.

---
## Ideas to solve the problem
1. We can sort the array in ascending ordre and return the last element
   - As the elements are arranged in ascending order the last element is always large
   - #### Time Complexity for sorting is - O(N log N) --->N is the size of array
   - #### Space Complexity -o(1) --> We are not using any extra space so constant space time

2. Iterate through the array i=0 to size of n
   - Consider the first element as the greatest and initialize it as largset element
   -Compare the largest element with all the array elements
      if found the largest change the largest element value to that element
      else no change
    - #### Time Complexity O(N) --> we are iterating for whole array so linear time complexity
    - #### Space Complexity O(1) --> not using any extra space
---
## Approach
- ##### For every problem always consider the best time complexity becuase even a single second matters when we are working with large amount of data

We will use the approach 2 becuase it's time complexity is better as compared to the approach one

Do a single pass: start `max_so_far = a[0]`. For every element `x`, do `max_so_far = max(max_so_far, x)`.

This is optimal because every element must be considered at least once.

---

## Complexity
- Time: O(n)
- Space: O(1)

---

## Edge cases
- `n = 0` (if allowed): decide how to handle it — return error / sentinel.
- All negative numbers: still works.
- All equal elements: works.

---

## Example
- Input:
1 3 2 7 4
- Output:
7


---

## Notes
Used approaches 
- Sorting
- Iterating




