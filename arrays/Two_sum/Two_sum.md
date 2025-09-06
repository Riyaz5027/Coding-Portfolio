# Question: Return two index which will give the given target or sum
             
 #### Note: Should not take the same index


## Input: 2 1 5 3 4 7, target = 8
## Output: 2 3( index of 5 and 3 which on adding gives us 8)

## Ideas to solve the problem

### 1.Take each element and do a linear search
  example:-
    
Take eacah element and search for all the elements in array which on adding gives us 8

    for(i=0 to n)
      for( j=0 to n)
        if( i==j )
        continue

        if(ar[i]+ar[j]==target)
         return i,j;

    Dry Run of the code:

    Given array: 2 1 5 3 4 7, target = 8

    for i = 0:
    - j = 0: i==j, continue
    - j = 1: ar[0]+ar[1]=2+1=3
    - j = 2: ar[0]+ar[2]=2+5=7
    - j = 3: ar[0]+ar[3]=2+3=5
    - j = 4: ar[0]+ar[4]=2+4=6
    - j = 5: ar[0]+ar[5]=2+7=9

    for i = 1:
    - j = 0: ar[1]+ar[0]=1+2=3
    - j = 1: i==j, continue
    - j = 2: ar[1]+ar[2]=1+5=6
    - j = 3: ar[1]+ar[3]=1+3=4
    - j = 4: ar[1]+ar[4]=1+4=5
    - j = 5: ar[1]+ar[5]=1+7=8 ✅ (found target, return 1,5)

    for i = 2:
    - j = 0: ar[2]+ar[0]=5+2=7
    - j = 1: ar[2]+ar[1]=5+1=6
    - j = 2: i==j, continue
    - j = 3: ar[2]+ar[3]=5+3=8 ✅ (found target, return 2,3)
    - j = 4: ar[2]+ar[4]=5+4=9
    - j = 5: ar[2]+ar[5]=5+7=12

    for i = 3:
    - j = 0: ar[3]+ar[0]=3+2=5
    - j = 1: ar[3]+ar[1]=3+1=4
    - j = 2: ar[3]+ar[2]=3+5=8 ✅ (found target, return 3,2)
    - j = 3: i==j, continue
    - j = 4: ar[3]+ar[4]=3+4=7
    - j = 5: ar[3]+ar[5]=3+7=10

    for i = 4:
    - j = 0: ar[4]+ar[0]=4+2=6
    - j = 1: ar[4]+ar[1]=4+1=5
    - j = 2: ar[4]+ar[2]=4+5=9
    - j = 3: ar[4]+ar[3]=4+3=7
    - j = 4: i==j, continue
    - j = 5: ar[4]+ar[5]=4+7=11

    for i = 5:
    - j = 0: ar[5]+ar[0]=7+2=9
    - j = 1: ar[5]+ar[1]=7+1=8 ✅ (found target, return 5,1)
    - j = 2: ar[5]+ar[2]=7+5=12
    - j = 3: ar[5]+ar[3]=7+3=10
    - j = 4: ar[5]+ar[4]=7+4=11
    - j = 5: i==j, continue

    This dry run checks all pairs (excluding same indices) and returns the indices where the sum equals the target.



    Time Complexity is o(n*n) 
    Becuase for every value we are iterating the array

    Space Compleixty is o(1)
    We did not used extra space


If we use i==j condition:
We check all pairs including (i, j) where i and j can be the same, but skip when i==j.
This means we consider both (i, j) and (j, i) for i ≠ j, leading to duplicate checks.
    
### Small change


If we do NOT use i==j and instead start j from i+1:
We only check each unique pair once, never (i, i), and avoid duplicate pairs (i, j) and (j, i).

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ar[i] + ar[j] == target) {
                    return i, j;
                }
            }
        }

Summary:
- Using i==j condition with j from 0 to n checks all pairs twice (except when i==j).
- Using j from i+1 checks each unique pair once, is more efficient, and avoids duplicate results.n)
        


  


    
