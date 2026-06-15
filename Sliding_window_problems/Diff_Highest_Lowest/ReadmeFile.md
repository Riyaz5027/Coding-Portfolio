# Minimum Difference Between Highest and Lowest of K Scores

**Source:** LeetCode Problem #1984
**Difficulty:** Easy

## Topics

* Array
* Sorting
* Sliding Window
* Greedy

---

# 📌 Problem Summary

You are given an array of student scores.

Your task is to select exactly `k` scores such that the difference between the highest score and the lowest score in the selected group is as small as possible.

Return the minimum possible difference.

---

# 📝 Sample Scenario

Consider:

```cpp
nums = [9,4,1,7]
k = 2
```

Possible groups:

```text
[9,4] → Difference = 5
[9,1] → Difference = 8
[9,7] → Difference = 2
[4,1] → Difference = 3
[4,7] → Difference = 3
[1,7] → Difference = 6
```

Minimum:

```cpp
2
```

Answer:

```cpp
2
```

---

# 🎯 What Should We Notice First?

Most beginners see:

```text
Highest Value
Lowest Value
Minimum Difference
```

and immediately think:

❌ Set

❌ Multiset

❌ Heap

❌ Priority Queue

This is exactly where many students get stuck.

In fact, you had a very natural first thought:

> "Let's use a set so that everything remains sorted and we can easily access the smallest and largest element."

That thought is not wrong.

The real question becomes:

```text
Which k elements should we select?
```

Before choosing a data structure, we must understand the structure of the problem.

---

# 🧠 Beginner Thought Process

Suppose:

```cpp
nums = [9,4,1,7]
k = 2
```

You might think:

```text
Let's keep elements in a set.
```

But then a question appears:

```text
How do I know which k elements belong together?
```

Example:

```cpp
[9,4,1,7]
```

The array is unsorted.

The best pair is:

```cpp
[7,9]
```

But these elements are not adjacent.

This tells us something important:

```text
The original order does not matter.
```

This is the biggest clue.

---

# 🚨 Important Observation

The problem never asks about:

```text
Index Positions
Subarrays
Original Order
```

It only cares about:

```text
Values
```

Whenever order does not matter:

Think:

```text
Sorting
```

---

# 🤔 Why Sorting?

Let's sort the array.

```cpp
nums = [9,4,1,7]
```

After sorting:

```cpp
[1,4,7,9]
```

Now look carefully.

Possible groups of size 2:

```text
[1,4]
[4,7]
[7,9]
```

Differences:

```text
3
3
2
```

Answer:

```text
2
```

Notice something amazing.

After sorting:

```text
The best group must be consecutive.
```

We never need:

```text
[1,9]
```

because:

```text
9 - 1
```

is larger than using closer values.

This is the key insight.

---

# 💡 Core Observation

After sorting:

```cpp
[1,4,7,9]
```

If we need exactly:

```cpp
k = 2
```

We simply check every window of size 2.

```text
[1,4]
[4,7]
[7,9]
```

For each window:

```text
Difference
=
Largest - Smallest
```

Because the array is sorted:

```cpp
largest = nums[right]
smallest = nums[left]
```

So:

```cpp
difference = nums[right] - nums[left]
```

---

# 🧠 The Sliding Window Insight

Many beginners get stuck here.

You asked:

> "How do we loop through a k-sized window? Do we need two loops?"

The answer is:

```text
No.
```

After sorting:

```cpp
[1,4,7,9]
```

For:

```cpp
k = 2
```

Window positions are:

```text
[1,4]
 [4,7]
  [7,9]
```

Notice:

```text
Left moves by 1
Right moves by 1
```

This is a fixed-size sliding window.

We only need one loop.

---

## Example with k = 4

Suppose:

```cpp
nums = [1,2,4,7,10,12]
k = 4
```

Windows:

```text
[1,2,4,7]
[2,4,7,10]
[4,7,10,12]
```

First Window:

```cpp
7 - 1 = 6
```

Second Window:

```cpp
10 - 2 = 8
```

Third Window:

```cpp
12 - 4 = 8
```

Minimum:

```cpp
6
```

Notice:

We never use nested loops.

We simply move the window forward.

---

# ❌ Why Not Set?

A set automatically keeps values sorted.

However:

```text
We still don't know which k elements
should form the group.
```

Sorting once is simpler.

After sorting:

```text
Every valid candidate group
appears as a consecutive window.
```

Therefore:

```text
Set becomes unnecessary.
```

---

# ❌ Why Not Two Pointers?

Two pointers are usually used when:

```text
Window size changes
```

Examples:

```text
Longest Substring
Container With Most Water
```

Here:

```text
Window size is fixed.
```

Therefore:

```text
Fixed Size Sliding Window
```

is sufficient.

---

# 🐢 Approach 1: Brute Force

## Idea

Generate every possible group of size k.

Compute:

```cpp
max - min
```

for each group.

Keep the minimum answer.

---

## Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | Very Large |
| Space  | O(1)       |

Not practical.

---

# 🚀 Approach 2: Sorting + Sliding Window (Optimal)

## Algorithm

Step 1:

```cpp
Sort the array
```

Step 2:

```cpp
Check every window of size k
```

Step 3:

```cpp
difference =
nums[i+k-1] - nums[i]
```

Step 4:

```cpp
Keep minimum difference
```

---

# 🔍 Dry Run

```cpp
nums = [9,4,1,7]
k = 2
```

Sort:

```cpp
[1,4,7,9]
```

Window 1:

```cpp
[1,4]

4 - 1 = 3
```

Answer:

```cpp
3
```

Window 2:

```cpp
[4,7]

7 - 4 = 3
```

Answer:

```cpp
3
```

Window 3:

```cpp
[7,9]

9 - 7 = 2
```

Answer:

```cpp
2
```

Final Answer:

```cpp
2
```

---

# ✅ Optimal Code

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for(int i = 0; i <= nums.size() - k; i++) {

            ans = min(
                ans,
                nums[i + k - 1] - nums[i]
            );
        }

        return ans;
    }
};
```

---

# ⚡ Complexity Analysis

## Time Complexity

Sorting:

```cpp
O(n log n)
```

Window Traversal:

```cpp
O(n)
```

Total:

```cpp
O(n log n)
```

---

## Space Complexity

```cpp
O(1)
```

Ignoring sorting implementation details.

---

# 📊 Complexity Comparison

| Approach                 | Time                     | Space |
| ------------------------ | ------------------------ | ----- |
| Brute Force              | Exponential / Very Large | O(1)  |
| Sorting + Sliding Window | O(n log n)               | O(1)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for(int i = 0; i <= nums.size() - k; i++) {

            ans = min(
                ans,
                nums[i + k - 1] - nums[i]
            );
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {9,4,1,7};
    int k = 2;

    Solution obj;

    cout << "Minimum Difference = "
         << obj.minimumDifference(nums, k);

    return 0;
}
```

### Output

```text
Minimum Difference = 2
```

---

# 🔥 Edge Cases

## k = 1

```cpp
nums = [4,7,9]
```

Any single element:

```cpp
max - min = 0
```

Answer:

```cpp
0
```

---

## All Elements Same

```cpp
nums = [5,5,5,5]
```

Answer:

```cpp
0
```

---

## Already Sorted

```cpp
nums = [1,2,3,4]
```

Algorithm still works.

---

# 🎤 Interview Takeaways

✅ If original order does not matter, consider sorting.

✅ After sorting, closest values become neighbors.

✅ Fixed-size group → Think Fixed-Size Sliding Window.

✅ For a window of size k:

```cpp
difference =
nums[i+k-1] - nums[i]
```

✅ The biggest insight is:

```text
After sorting,
the optimal group will always appear
as a consecutive window.
```

This observation completely transforms the problem from a difficult selection problem into a simple sliding window problem.

---

# 🔗 Related Problems

* Contains Duplicate III
* Maximum Number of Coins You Can Get
* Assign Cookies
* Longest Continuous Increasing Subsequence
* Maximum Number of Vowels in a Substring of Given Length

These problems also rely on sorting or sliding-window style observations.
