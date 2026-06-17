# Maximum Length Substring With Two Occurrences

**Source:** LeetCode Problem #3090
**Difficulty:** Easy

## Topics

* String
* Hash Map
* Sliding Window
* Variable Size Window

---

# 📌 Problem Summary

You are given a string consisting of lowercase English letters.

Your task is to find the length of the longest substring such that:

```text
No character appears more than 2 times.
```

Return the maximum valid substring length.

---

# 📝 Sample Scenario

Consider:

```cpp
s = "bcbbbcba"
```

One valid substring is:

```text
bcbb
```

Character frequencies:

```text
b → 2
c → 1
```

Valid ✅

Length:

```cpp
4
```

A longer substring:

```text
bcbbbc
```

Character frequencies:

```text
b → 4
c → 2
```

Invalid ❌

Because:

```text
b appears more than 2 times
```

Answer:

```cpp
4
```

---

# 🎯 What Should We Notice First?

Most beginners see:

```text
Longest
Substring
Frequency
```

and immediately become confused.

Some students think:

❌ Prefix Sum

❌ Sorting

❌ Binary Search

❌ Fixed Window

But let's focus on the most important word:

```text
Longest
```

Whenever a problem asks:

```text
Longest Substring
Shortest Substring
Maximum Length
Minimum Length
```

you should immediately think:

✅ Variable Size Sliding Window

---

# 🧠 Beginner Thinking Process

Ask yourself:

### Question 1

Are we looking for a substring?

Answer:

```text
YES
```

---

### Question 2

Is the window size given?

Example:

```text
Length = 3
Length = k
Exactly 5 characters
```

Answer:

```text
NO
```

---

### Question 3

Are we trying to find the longest valid substring?

Answer:

```text
YES
```

This is a huge clue.

Whenever:

```text
Window Size Not Fixed
+
Longest / Shortest
```

Think:

```text
Variable Size Sliding Window
```

---

# 🔍 Pattern Recognition

## Fixed Size Window Problems

Examples:

```text
Count Good Substrings of Size Three
K-Beauty of a Number
Maximum Number of Vowels of Length k
```

Characteristics:

```text
Window Size = Fixed
```

Example:

```cpp
k = 3
```

Window:

```text
abc
 bcd
  cde
```

The size never changes.

---

## Variable Size Window Problems

Examples:

```text
Longest Substring Without Repeating Characters
Minimum Window Substring
Maximum Length Substring
```

Characteristics:

```text
Window grows
Window shrinks
Window size changes dynamically
```

Example:

```text
abc
abcd
abcde
abcd
abc
```

This is exactly the pattern used in this problem.

---

# 🪟 Understanding Variable Size Sliding Window

This is the most important concept.

Imagine two pointers:

```text
left
right
```

Initially:

```text
left = 0
right = 0
```

Window:

```text
[a]
```

Expand:

```text
[a b]
```

Expand:

```text
[a b c]
```

Expand:

```text
[a b c b]
```

Still valid.

Expand:

```text
[a b c b b]
```

Now:

```text
b appears 3 times
```

Invalid ❌

What do we do?

Move left forward:

```text
[a b c b b]
 ^
```

Remove:

```text
a
```

Window becomes:

```text
[b c b b]
```

Still invalid.

Move left again:

```text
[b c b b]
 ^
```

Remove:

```text
b
```

Window becomes:

```text
[c b b]
```

Now:

```text
b appears only 2 times
```

Valid again ✅

This process is called:

```text
Expand → Violate Rule → Shrink → Become Valid
```

This is the heart of Variable Size Sliding Window.

---

# 🤔 Why Sliding Window?

Let's examine:

```cpp
s = "bcbbbcba"
```

We need:

```text
Longest substring
```

such that:

```text
Every character frequency <= 2
```

Notice:

The validity of a substring depends on:

```text
Character Frequencies
```

Whenever:

```text
Substring
+
Frequency Constraint
+
Longest / Shortest
```

Think:

```text
Sliding Window + Frequency Map
```

---

# ❌ Why Not Prefix Sum?

Prefix Sum is useful when:

```text
Running Totals
Range Queries
Numerical Sums
```

Examples:

```text
Pivot Index
Subarray Sum Equals K
Running Sum
```

This problem is about:

```text
Character Frequencies
```

Therefore:

```text
Prefix Sum ❌
```

---

# ❌ Why Not Sorting?

Sorting would destroy:

```text
Substring Order
```

Example:

```cpp
abcba
```

becomes:

```cpp
aabbc
```

which completely changes the problem.

Therefore:

```text
Sorting ❌
```

---

# 💡 Core Observation

A window is valid when:

```text
Every frequency <= 2
```

Invalid when:

```text
Any frequency > 2
```

Example:

```text
abcb
```

Frequency:

```text
a → 1
b → 2
c → 1
```

Valid ✅

---

Example:

```text
abcbb
```

Frequency:

```text
a → 1
b → 3
c → 1
```

Invalid ❌

As soon as a frequency becomes:

```cpp
3
```

we must shrink the window.

---

# 🐢 Approach 1: Brute Force

## Idea

Generate every possible substring.

For each substring:

1. Count frequencies.
2. Check validity.
3. Update answer.

---

## Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(n³)      |
| Space  | O(26)      |

Very slow.

---

# 🚀 Approach 2: Variable Size Sliding Window (Optimal)

## Algorithm

Maintain:

```cpp
left
right
frequency map
```

Expand:

```cpp
right++
```

Add current character.

---

If:

```cpp
freq[s[right]] > 2
```

Window becomes invalid.

Shrink:

```cpp
left++
```

until valid again.

---

Update:

```cpp
answer =
max(answer,
windowLength)
```

---

# 🔍 Dry Run

```cpp
s = "bcbbbcba"
```

Start:

```text
b
```

Length:

```cpp
1
```

---

Expand:

```text
bc
```

Valid ✅

Length:

```cpp
2
```

---

Expand:

```text
bcb
```

Frequency:

```text
b → 2
c → 1
```

Valid ✅

Length:

```cpp
3
```

---

Expand:

```text
bcbb
```

Frequency:

```text
b → 3
```

Invalid ❌

Shrink:

Remove:

```text
b
```

Window:

```text
cbb
```

Valid again ✅

Length:

```cpp
3
```

Continue until end.

Final Answer:

```cpp
4
```

---

# ✅ Optimal Code

```cpp
class Solution {
public:

    int maximumLengthSubstring(string s) {

        unordered_map<char,int> freq;

        int left = 0;
        int answer = 0;

        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while(freq[s[right]] > 2) {

                freq[s[left]]--;
                left++;
            }

            answer =
                max(answer,
                    right - left + 1);
        }

        return answer;
    }
};
```

---

# ⚡ Complexity Analysis

## Time Complexity

Every character:

```text
Enters window once
Leaves window once
```

Therefore:

```cpp
O(n)
```

---

## Space Complexity

At most:

```cpp
26
```

lowercase letters.

Therefore:

```cpp
O(1)
```

---

# 📊 Complexity Comparison

| Approach       | Time  | Space |
| -------------- | ----- | ----- |
| Brute Force    | O(n³) | O(26) |
| Sliding Window | O(n)  | O(1)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int maximumLengthSubstring(string s) {

        unordered_map<char,int> freq;

        int left = 0;
        int answer = 0;

        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while(freq[s[right]] > 2) {

                freq[s[left]]--;
                left++;
            }

            answer =
                max(answer,
                    right - left + 1);
        }

        return answer;
    }
};

int main() {

    string s = "bcbbbcba";

    Solution obj;

    cout << "Maximum Length = "
         << obj.maximumLengthSubstring(s);

    return 0;
}
```

### Output

```text
Maximum Length = 4
```

---

# 🔥 Edge Cases

## Single Character

```cpp
s = "a"
```

Answer:

```cpp
1
```

---

## All Same Characters

```cpp
s = "aaaaaa"
```

Maximum valid substring:

```text
aa
```

Answer:

```cpp
2
```

---

## Every Character Unique

```cpp
s = "abcdef"
```

All frequencies:

```text
<= 2
```

Answer:

```cpp
6
```

---

# 🎤 Interview Takeaways

✅ Fixed Length → Fixed Sliding Window

✅ Longest / Shortest → Variable Sliding Window

✅ Frequency Constraint → Hash Map

✅ Invalid Window → Shrink From Left

✅ Valid Window → Expand Right

✅ The golden rule:

```text
Expand the window.

If rule breaks,
shrink until valid.

Update answer.
```

This single pattern solves a huge number of Sliding Window interview problems.

---

# 🔗 Related Problems

* Longest Substring Without Repeating Characters
* Maximum Erasure Value
* Fruit Into Baskets
* Permutation in String
* Minimum Window Substring

All of these use Variable Size Sliding Window concepts.
