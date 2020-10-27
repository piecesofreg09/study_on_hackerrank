
**Question**

Given an array of integers, any array element can be moved to the end in one move. Determine minimum numbers of moves required to sort the array in ascending order.

**Example**

Eg: [1,3,2]

Output: 1

Explanation: 3 to end

Eg: [5,1,3,2]

Output: 2

Explanation: 1) 3 to end

	     2) 5 to end
Eg: [ 1,3,2,5]

Output: 2

Explanation: 1) 3 to end

	     2) 5 to end

from [leetcode link](https://leetcode.com/discuss/interview-question/789524/determine-minimum-numbers-of-moves-required-to-sort-the-array-in-ascending-order)

**Answer**
```cs
 int moveMin(int[] arr)
{
    var minSeen = new int[arr.Length];
    minSeen[arr.Length - 1] = arr[arr.Length - 1];

    for (int i = arr.Length - 2; i >= 0; i--)
    {
        minSeen[i] = Math.Min(minSeen[i+1], arr[i]);
    }
    var count = 0;

    var maxMoved = int.MaxValue;
    for (int i = 0; i < arr.Length; i++)
    {
        if (arr[i] > maxMoved ) // if moved Higher number before then need to move
        {
            count++;
        }
        else if (arr[i]> minSeen[i]) // if there is lower number after then need to move
        {
            count++;
            maxMoved = arr[i];
        }
    }
    return count;
}

var input = new int[] { 1, 3, 2 };
Console.WriteLine(moveMin(input) == 1); // Move 3
input = new int[] { 5, 1, 3, 2 };
Console.WriteLine(moveMin(input) == 2); //Move 3,5
input = new int[] { 1, 3, 2, 5 };
Console.WriteLine(moveMin(input) == 2); //Move 3,5

input = new int[] { 1, 7, 2, 5 };
Console.WriteLine(moveMin(input) == 1); //Move 7
input = new int[] { 1, 3, 2, 5, 7, 4 };
Console.WriteLine(moveMin(input) == 4); //Move 3,5,7,4
input = new int[] { 4,5,1,7,3 };
Console.WriteLine(moveMin(input) == 3); //Move 4,5,7

input = new int[] { 1, 5, 2, 4, 3, 8, 9 };
Console.WriteLine(moveMin(input) == 4); //Move 5,4,8,9

input = new int[] { 5,4,3,2,1 };
Console.WriteLine(moveMin(input) == 4); //Move 5,4,3,2

input = new int[] { 2, 1 };
Console.WriteLine(moveMin(input) == 1);
```
