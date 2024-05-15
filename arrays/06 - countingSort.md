# Counting Sort

The Counting Sort algorithm sorts an array by counting the number of times each value occurs.

Counting Sort does not compare values like the previous sorting algorithms we have looked at, and only works on non negative integers.

Furthermore, Counting Sort is fast when the range of possible value $k$ is smaller than the number of values $n$.

### How it works

1. Create a new array for counting how many there are of the different values.
2. Go through the array that needs to be sorted.
3. For each value, count it by increasing the counting array at the corresponding index.
4. After counting the values, go through the counting array to create the sorted array.
5. For each count in the counting array, create the correct number of elements, with values that correspond to the counting array index.

## Conditions for Counting Sort

These are the reasons why Counting Sort is said to only work for a limited range of non-negative integer value:

- **Integer values:** Counting Sort relies on counting occurrences of distinct values, so they must be integers. With integers, each fits with an index (for non negative values), and there is a limited number of different values, so that the number of possible different values $k$ is not too big compared to the number of values $n$.
- **Non negative values:** Counting Sort is usually implemented by creating an array for counting. When the algorithm goes through the values to be sorted, value x is counted by increasing the counting array value at index x. If we tried sorting negative values, we would get in trouble with sorting value -3, because index -3 would be outside the counting array.
- **Limited range of values:** If the number of possible different values to be sorted $k$ is larger than the number of values to be sorted $n$, the counting array we need for sorting will be larger than the original array we have that needs sorting, and the algorithm becomes ineffective.

## Manual Run Through

Before implement the Counting Sort algorithm in a programming language, let's manually run through a short array, just to get the idea.

**Step 1:** we start with an unsorted array.

[2, 3, 0, 2, 3, 2]

**Step 2:** we create another array for counting how many there are of each value. The array has 4 elements, to hold values 0 through 3.

myArray = [2, 3, 0, 2, 3, 2]

countingArray = [0, 0, 0, 0]

**Step 3:** now let's start counting. The first element is 2, so we must increment the counting array element at index 2.

myArray = [`2`,3, 0, 2, 3, 2]

countingArray = [0, 0, `1`,0]

**Step 4:** After counting a value, we can remove it, and count the next value, which is 3.

myArray = [`3`,0, 2, 3, 2]

countingArray = [0, 0, 1, `1`]

**Step 5:** The next value we counts is 0, so we increment index 0 in the counting array.

myArray = [`0`,2, 3, 2]

countingArray = [`1`,0, 1, 1]

**Step 6:** we continue like this until all values are counted.

myArray = []

countingArray = [`1`, `0`, `3`, `2`]

**Step 7:** now we will recreate the elements from the initial array, and we will do it so that the elements are ordered lowest to highest.

The first element in the counting array tells us that we have 1 element with value 0. So we push 1 element with value 0 into the array, and we decrease the element at index 0 in the counting array with 1.

myArray = [`0`]

countingArray = [`0`,0, 3, 2]

**Step 8:** from the counting array we see that we do not need to create any elements with value 1.

myArray = [0]

countingArray = [0, `0`,3, 2]

**Step 9:** we push 3 elements with value 2 into the end of array. And as we create these elements we also decrease the counting array at index 2.

myArray = [0, `2`, `2`, `2`]

countingArray = [0, 0, `0`,2]

**Step 10:** at last we must add 2 elements with value 3 at the end of the array.

myArray = [0, 2, 2, 2, `3`, `3`]

countingArray = [0, 0, 0, `0`]

Finally! THe array is sorted.

## Manual Run Through: What Happened?

Before we implement the algorithm in a programming language we need to go through what happened above in more detail.

<!-- <center>
    <img src="../images/arrays/img_runtime_n^2.png" alt="Runtime Insertion Sort">
</center> -->
