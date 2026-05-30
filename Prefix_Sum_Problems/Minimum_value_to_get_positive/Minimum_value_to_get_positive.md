# 🟢 LeetCode 1413 - Minimum Value to Get Positive Step by Step Sum

> Difficulty: Easy
>
> Topics: Array, Prefix Sum

---

# 📖 Problem Statement

Given an integer array `nums`, find the minimum positive integer `startValue` such that when we start with `startValue` and add the elements of the array one by one, the running sum never becomes less than `1`.

Return the minimum possible value of `startValue`.

---

# 📝 Example 1

### Input

```cpp
nums = [-3,2,-3,4,2]
```

### Output

```cpp
5
```

### Explanation

Start with:

```cpp
startValue = 5
```

Running sums:

```cpp
5 + (-3) = 2
2 + 2 = 4
4 + (-3) = 1
1 + 4 = 5
5 + 2 = 7
```

Every value remains:

```cpp
>= 1
```

Therefore:

```cpp
Answer = 5
```

---

# 🎯 Beginner Thinking Process

Most students immediately think:

❌ Sorting

❌ Sliding Window

❌ Two Pointers

❌ Binary Search

None of them solve the actual requirement.

The problem repeatedly says:

```text
Step by Step Sum
Running Sum
Current Total
```

Whenever you see these words, ask yourself:

> "Do I need to know the cumulative sum up to every position?"

If the answer is YES, think:

✅ Prefix Sum

---

# 🧠 Pattern Recognition

When solving array problems, ask:

### Question 1

Do I need information about previous elements?

Examples:

```text
Running Sum
Cumulative Sum
Total till current index
```

Think:

```text
Prefix Sum
```

---

### Question 2

Do I need information about future elements?

Think:

```text
Suffix Sum
```

---

### Question 3

Am I searching for a continuous subarray?

Think:

```text
Sliding Window
Kadane's Algorithm
```

---

### Question 4

Am I searching for pairs?

Think:

```text
Two Pointers
Hashing
```

---

For this problem:

```text
Running Sum ✅
Subarray ❌
Pairs ❌
Sorting ❌
```

Therefore:

```text
Prefix Sum is the natural choice.
```

---

# 🤔 Why Prefix Sum?

Let's examine:

```cpp
nums = [-3,2,-3,4,2]
```

Running sums:

```cpp
-3
-1
-4
0
2
```

Notice something important:

The answer depends entirely on the lowest running sum.

We don't care about:

```text
Largest Element
Smallest Element
Sorted Order
Pairs
Subarrays
```

We only care about:

```text
The minimum running sum
```

Running sums are exactly:

```text
Prefix Sums
```

Therefore Prefix Sum is the correct tool.

---

# ❌ Why Not Sliding Window?

Sliding Window is useful when we need:

```text
Fixed Size Subarray
Variable Size Subarray
Continuous Segment
```

Examples:

```text
Maximum Sum Subarray
Longest Substring
```

This problem never asks about subarrays.

Therefore:

```text
Sliding Window ❌
```

---

# ❌ Why Not Two Pointers?

Two pointers are useful when dealing with:

```text
Pairs
Triplets
Sorted Arrays
```

Examples:

```text
Two Sum II
3 Sum
Container With Most Water
```

This problem has none of these.

Therefore:

```text
Two Pointers ❌
```

---

# ❌ Why Not Binary Search?

Binary Search is useful when:

```text
Data is sorted
Answer space is monotonic
```

This problem does not require searching.

Therefore:

```text
Binary Search ❌
```

---

# 🔍 Core Observation

Suppose:

```cpp
nums = [-3,2,-3,4,2]
```

Start with:

```cpp
startValue = x
```

Running sums become:

```cpp
x - 3
x - 1
x - 4
x
x + 2
```

Every value must satisfy:

```cpp
>= 1
```

The worst point occurs when the prefix sum becomes minimum.

Prefix sums:

```cpp
-3
-1
-4
0
2
```

Minimum prefix:

```cpp
-4
```

Requirement:

```cpp
x + (-4) >= 1
```

Therefore:

```cpp
x >= 5
```

Answer:

```cpp
5
```

---

# 💡 Mathematical Insight

We need:

```cpp
startValue + minimumPrefix >= 1
```

Rearranging:

```cpp
startValue >= 1 - minimumPrefix
```

Therefore:

```cpp
Answer = 1 - minimumPrefix
```

This is the entire solution.

---

# 🐢 Approach 1: Brute Force

## Idea

Try:

```cpp
startValue = 1
startValue = 2
startValue = 3
...
```

Keep testing until a valid value is found.

---

## Code

```cpp
class Solution {
public:

    bool valid(vector<int>& nums, int start) {

        int sum = start;

        for(int num : nums) {
            sum += num;

            if(sum < 1)
                return false;
        }

        return true;
    }

    int minStartValue(vector<int>& nums) {

        int start = 1;

        while(true) {

            if(valid(nums, start))
                return start;

            start++;
        }
    }
};
```

---

## Complexity

| Metric | Value    |
| ------ | -------- |
| Time   | O(k × n) |
| Space  | O(1)     |

where `k` is the answer.

---

# 🚀 Approach 2: Prefix Sum (Optimal)

## Idea

Find:

```cpp
Minimum Prefix Sum
```

Then use:

```cpp
Answer = 1 - Minimum Prefix
```

---

## Dry Run

```cpp
nums = [-3,2,-3,4,2]
```

| Element | Prefix Sum | Minimum Prefix |
| ------- | ---------- | -------------- |
| -3      | -3         | -3             |
| 2       | -1         | -3             |
| -3      | -4         | -4             |
| 4       | 0          | -4             |
| 2       | 2          | -4             |

Final:

```cpp
minimumPrefix = -4
```

Answer:

```cpp
1 - (-4)
=
5
```

---

## Code

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int prefix = 0;
        int minimumPrefix = 0;

        for(int num : nums) {

            prefix += num;

            minimumPrefix =
                min(minimumPrefix, prefix);
        }

        return 1 - minimumPrefix;
    }
};
```

---

# ⚡ Complexity Analysis

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

---

# 🧪 Driver Code (For Local Testing)

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int prefix = 0;
        int minimumPrefix = 0;

        for(int num : nums) {

            prefix += num;

            minimumPrefix =
                min(minimumPrefix, prefix);
        }

        return 1 - minimumPrefix;
    }
};

int main() {

    vector<int> nums = {-3,2,-3,4,2};

    Solution obj;

    cout << "Minimum Start Value = "
         << obj.minStartValue(nums);

    return 0;
}
```

---

# 🔥 Edge Cases

### Single Positive Number

```cpp
nums = [5]
```

Answer:

```cpp
1
```

---

### Single Negative Number

```cpp
nums = [-5]
```

Answer:

```cpp
6
```

---

### All Positive Numbers

```cpp
nums = [1,2,3]
```

Answer:

```cpp
1
```

---

### All Negative Numbers

```cpp
nums = [-1,-2,-3]
```

Answer:

```cpp
7
```

---

# 📊 Complexity Comparison

| Approach             | Time     | Space |
| -------------------- | -------- | ----- |
| Brute Force          | O(k × n) | O(1)  |
| Prefix Sum (Optimal) | O(n)     | O(1)  |

---

# 🎤 Interview Takeaways

✅ Running Sum → Think Prefix Sum

✅ We only care about the minimum prefix value

✅ The entire problem can be solved using:

```cpp
Answer = 1 - MinimumPrefix
```

✅ Prefix Sum is not just for range queries. It is also useful for tracking cumulative behavior of an array.

---

# 🔗 Related Problems

* Running Sum of 1D Array
* Pivot Index
* Subarray Sum Equals K
* Range Sum Query
* Continuous Subarray Sum
