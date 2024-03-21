# A Simple Algorithm

Showing an very useful algorithm to introduction the importance of DSA.

## Fibonacci Numbers

The Fibonacci numbers are named after 13th century Italian mathematician known as Fibonacci.

The two first Fibonacci numbers are 0 and 1, and the next Fibonacci numbers always the sum of the two previous numbers, so we get 0, 1, 1, 2, 3, 5, 8, 13, 21...

## The Fibonacci Number Algorithm

To generate a Fibonacci number, all we need to do is to add the two previous Fibonacci numbers.

THe Fibonacci numbers is a good way of demonstrating what an algorithm is. We know the principle of how to find the next number, so we can write an algorithm to create as many Fibonaccu numbers as possible.

Bellow is the algorithm to create the 20 first Fibonacci numbers.

### How it works

1. Start with the two previous numbers together to create a new Fibonacci number.
   - a) Add the two previous numbers together to create a new Fibonacci number.
   - b) Update the value of the two previous numbers.
2. Do point a and $\ n$ above 18 times.

## Loops vs Recursion

To show the difference between loops and recursion, we will implement solutions to find Fibonacci numbers in three different ways:

1. An implementation of the Fibonacci algorithm above using a for loop.
2. An implementation of the Fibonacci algorithm above using recursion.
3. Finding the nth Fibonacci number using recursion.

## 1. ImplementationUsing a For Loop

It can be a good idea to list what the code must contain or do before programming it:

- Two variables to hold the previous two Fibonacci numbers;
- A for loop that runs 18 times;
- Create new Fibonacci numbers by adding the two previous ones;
- Print the new Fibonacci number;
- Update the variables tha hold the previous two Fibonacci numbers.

Using the list above, ir is easier to write the program:

```c
#include <stdio.h>

int main() {
    int prev2 = 0;
    int prev1 = 1;

    printf("%d\n", prev2);
    printf("%d\n", prev1);

    for (int i = 0; i < 18; i++) {
        int newFibo = prev1 + prev2;
        printf("%d\n", newFibo);
        prev2 = prev1;
        prev1 = newFibo;
    }

    return 0;
}
```

## 2. Implementation Using Recursion

Recursion is when a function calls itself.

To implement the Fibonacci algorithm we need most of the same things as in the code example above, but we need to replace the for loop with recursion.

To replace the for loop with recursion, we need to enxapsulate much of the code in a function, and we need the function to call itself to create a new Fibonacci number as long as the produced number of Fibonacci number is below, or equal to, 19.

Our code looks like this:

```c
#include <stdio.h>

void fibonacci(int prev1, int prev2, int count);

int main() {
    printf("%d\n", 0);
    printf("%d\n", 1);

    fibonacci(1, 0, 2);

    return 0;
}

void fibonacci(int prev1, int prev2, int count) {
    if (count <= 19) {
        int newFibo = prev1 + prev2;
        printf("%d\n", newFibo);
        prev2 = prev1;
        prev1 = newFibo;
        count++;
        fibonacci(prev1, prev2, count);
    } else {
        return;
    }
}
```

## 3. Finding the nth Fibonacci Number Using Recursion

To find the nth Fibonacci number we can write code based on the mathematic formula for Fibonacci number $\ n$:

$$\ F(n) = F(n - 1) + F(n - 2)$$

This just means that for example the 10th Fibonacci number is the sum of the 9th and 8th Fibonacci numbers.

When usign this concept with recursion, we can let the function call itself as long as $\ n$ is less than, or eqaul to 1. If $ n \leq $ it means that the code execution has reached one of the first two Fibonacci number 1 or 0.

The code looks like this:

```c
#include <stdio.h>

int F(int n) {
    if (n <= 1) {
        return n;
    } else {
        return F(n - 1) + F(n - 2);
    }
}

int main() {
    printf("%d\n", F(5));
    return 0;
}
```

**Note:** that this recursive method calls itself two times, not just one. This makes a huge difference in how the program will actually tun on our computer. The number of calculations will explode when we increase the number of the Fibonacci number we want. To be more precise, the number of function calls will double every time we increase the Fibonacci number we want by one.

There are two important things to notice here: the amount of function calls, and the amount of times the function is called with the same arguments.

So even though the code is fascinating and shows how recrusion work, the actual code execution is too slow and ineffective to use for creating large Fibonacci numbers.
