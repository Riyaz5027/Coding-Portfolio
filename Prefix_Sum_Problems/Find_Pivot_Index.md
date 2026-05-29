# Find Pivot Index

> Difficulty: Easy
> Topics: Arrays, Prefix Sum

---

## Problem Statement

Given an integer array `nums`, find an index such that:

* The sum of all elements to its left is equal to the sum of all elements to its right.
* The pivot element itself is not included in either sum.
* Return the leftmost pivot index if multiple exist.
* Return `-1` if no pivot index exists.

---

## Example

### Input

```cpp
nums = [1,7,3,6,5,6]
```

### Output

```cpp
3
```

---

## Visual Explanation



At index `3`:

```text
Left Side  = 1 + 7 + 3 = 11

Right Side = 5 + 6 = 11
```

Since both sums are equal, index `3` is the pivot index.

---

## Intuition

The first idea that comes to mind is:

For every index:

1. Calculate the left sum.
2. Calculate the right sum.
3. Compare them.

This works but repeatedly calculates the same sums.

We can do better using Prefix Sums.

---

# Approach 1: Brute Force

## Algorithm

For every index:

* Calculate the sum of elements on the left.
* Calculate the sum of elements on the right.
* If equal, return the index.

---

## Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int leftSum = 0;
            int rightSum = 0;

            for(int j = 0; j < i; j++)
                leftSum += nums[j];

            for(int j = i + 1; j < n; j++)
                rightSum += nums[j];

            if(leftSum == rightSum)
                return i;
        }

        return -1;
    }
};
```

---

## Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(n²) |
| Space  | O(1)  |

---

# Approach 2: Prefix Sum Array

## Idea

Instead of recalculating sums again and again, store cumulative sums.

### Example

```text
nums

[1] [7] [3] [6] [5] [6]
```

Prefix Array:

```text
[0] [1] [8] [11] [17] [22] [28]
```

---

## Visualization



---

## Observation

For any index:

```text
Left Sum  = prefix[i]

Right Sum = totalSum - prefix[i+1]
```

If both are equal:

```text
Pivot Found
```

---

## Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix;

        prefix.push_back(0);

        int sum = 0;

        for(int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }

        int total = prefix.back();

        for(int i = 1; i < prefix.size(); i++) {

            int leftSum = prefix[i - 1];

            int rightSum = total - prefix[i];

            if(leftSum == rightSum)
                return i - 1;
        }

        return -1;
    }
};
```

---

## Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(n)  |
| Space  | O(n)  |

---
# Approach 3: Optimal Solution

## Core Observation

Let's imagine we are standing at some index `i`.

For every index, the array can be divided into three parts:

```text
Left Part | Current Element | Right Part
```

Example:

```text
[1,7,3,6,5,6]
       ↑

Left Part      = [1,7,3]
Current Element= 6
Right Part     = [5,6]
```

We know that:

```text
Total Sum
=
Left Sum + Current Element + Right Sum
```

For the above example:

```text
28 = 11 + 6 + 11
```

---

## Deriving the Formula

Starting from:

```text
Total Sum
=
Left Sum + Current Element + Right Sum
```

Move the other terms to the left side:

```text
Right Sum
=
Total Sum - Left Sum - Current Element
```

This formula allows us to calculate the right sum in O(1) time.

---

## Why Is This Useful?

Normally, to find the right sum, we would need to traverse the remaining elements.

Example:

```text
[1,7,3,6,5,6]
       ↑
```

To calculate:

```text
5 + 6 = 11
```

we would need another loop.

But using the formula:

```text
Right Sum
=
Total Sum - Left Sum - Current Element
```

we can get the same answer instantly.

```text
Right Sum
=
28 - 11 - 6

=
11
```

No extra traversal needed.

---

## Visual Walkthrough

### Initial State

```text
nums = [1,7,3,6,5,6]

totalSum = 28
leftSum = 0
```

---

### Index 0

```text
Current = 1

leftSum = 0

rightSum
=
28 - 0 - 1

=
27
```

Compare:

```text
0 == 27
```

False

Move current element to left side:

```text
leftSum += 1

leftSum = 1
```

---

### Index 1

```text
Current = 7

leftSum = 1

rightSum
=
28 - 1 - 7

=
20
```

Compare:

```text
1 == 20
```

False

Update:

```text
leftSum = 8
```

---

### Index 2

```text
Current = 3

leftSum = 8

rightSum
=
28 - 8 - 3

=
17
```

Compare:

```text
8 == 17
```

False

Update:

```text
leftSum = 11
```

---

### Index 3

```text
Current = 6

leftSum = 11

rightSum
=
28 - 11 - 6

=
11
```

Compare:

```text
11 == 11
```

True ✅

Return:

```text
3
```

---

## Why Do We Update Left Sum After Checking?

Consider index 3:

```text
[1,7,3,6,5,6]
       ↑
```

The left side should contain:

```text
1 + 7 + 3
```

and NOT:

```text
1 + 7 + 3 + 6
```

The current element must not be included in either side.

That's why we first check:

```cpp
if(leftSum == rightSum)
```

and only then do:

```cpp
leftSum += nums[i];
```

---

## Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        for(int num : nums)
            totalSum += num;

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            int rightSum =
                totalSum - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
```

---

## Complexity Analysis

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

---

## Key Insight

The entire optimal solution is based on one equation:

```text
Total Sum
=
Left Sum + Current Element + Right Sum
```

which gives:

```text
Right Sum
=
Total Sum - Left Sum - Current Element
```

Once you discover this relationship, the problem becomes straightforward.


---

## Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(n)  |
| Space  | O(1)  |

---

# Complexity Comparison

| Approach    | Time  | Space |
| ----------- | ----- | ----- |
| Brute Force | O(n²) | O(1)  |
| Prefix Sum  | O(n)  | O(n)  |
| Optimal     | O(n)  | O(1)  |

---

# Edge Cases

## Single Element

```cpp
nums = [10]
```

```text
Left Sum = 0
Right Sum = 0
```

Answer:

```cpp
0
```

---

## All Zeros

```cpp
nums = [0,0,0,0]
```

Answer:

```cpp
0
```

---

## No Pivot Exists

```cpp
nums = [1,2,3]
```

Answer:

```cpp
-1
```

---

## Negative Numbers

```cpp
nums = [2,1,-1]
```

Answer:

```cpp
0
```

---

# Interview Discussion

### Why does the optimal solution work?

At every index:

```text
Total Sum
=
Left Sum + Current Element + Right Sum
```

Rearranging:

```text
Right Sum
=
Total Sum - Left Sum - Current Element
```

This allows us to calculate the right sum in O(1) time.

---

# Key Takeaways

✅ Prefix Sum is useful when repeated range-sum calculations are required.

✅ Brute Force is easy to understand but inefficient.

✅ The optimal solution avoids storing extra arrays.

✅ Always look for mathematical relationships before introducing additional data structures.

---

# Related Problems

* Range Sum Query
* Running Sum of 1D Array
* Subarray Sum Equals K
* Product of Array Except Self
* Continuous Subarray Sum
