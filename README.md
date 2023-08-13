# Lab 8: Managing Memory

In this lab we will look at some of the basic mechanisms for memory management in C++:

* Stack variables
* Reference parameters
* Raw pointers
* Unique smart pointers
* Shared smart pointers

In addition to reviewing how these mechanisms work, we'll also compare their pros, cons, and performance. Building intuition in this area will help you choose the best approach for a particular problem.

## Experimental Setup

To explore each mechanism, a sample project has been provided for you. It is not particularly realistic nor is it a perfect benchmark of performance. It is intended only as an exploration of the mechansisms and to help you draw conclusions about their _relative_ performance.

The program is based around a simple structure called `HomeData` that holds market statistics for a single home (number of bedrooms, square footage, sale price, etc.). The sales data will be completely fake and generated with code (and not, for example, from a file) in order to keep the project simple. In fact, each struct will contain exactly the same data.

For each mechansim, there is a separate file containing code specific to that mechanism. For instance, the code for exploring shared pointers is in the `shared_ptr.cpp` file. Each file has three functions that you must implement:

* `calculatePricePerSqFt`: performs a price-per-square-foot calculation on a single `HomeData` struct
* `allocateSalesData`: allocates a large number of `HomeData` structs
* `averagePricePerSqFt`: updates the `pricePerSqFt` field for all structs then returns the average

There is also a main program in `main.cpp` that invokes the functions above and measures their speed. It is shared across all mechanisms and does not need to be modified.

## Stack variables

The code for demonstrating stack variable usage is already implemented in `stack.cpp`. Try this now:

1. Study the `stack.cpp` and `main.cpp` code.
2. Switch to the `stack_main` target by:
    * Using the `CMake: Set Debug Target` command, or
    * Clicking the launch target in the VS Code status bar
3. Run the `stack_main` target by:
    * Using the `CMake: Run Without Debugging` command, or
    * Using the `Run > Run Without Debugging` menu option, or
    * Clicking the launch button (triangle) in the VS Code status bar
4. Observe the allocation and function call timings that appear in the Terminal window.

`HomeData` is a small and simple struct. What would happen to the code if it had a lot more data about the home? Instead of adding real data, let's simulate a larger struct by adding an array of unused data to it. Try this:

1. Add an array of 10 integers to the `HomeData` struct. Give it any name you like.
2. Run the program again and observe the performance.
3. Change the array to 100 integers and re-run the program.
4. Change the array to 1000 integers and re-run the program.

What happens to the performance of this program as the size of `HomeData` increases? Why does this happen?

Before moving to the next step, remove or comment out the integer array that you added.

## Reference parameters

Now look at the code in `reference.cpp` and note that its functions are empty. Your task is to implement the missing code. Feel free to copy and paste code from `stack.cpp` to use in `reference.cpp`, but do not change the function signatures or add new ones. (Note: The `allocateSalesData` function will be identical to the stack version because references cannot be stored.)

When you have finished:

1. Switch to the `reference_main` target.
2. Run the program and observe its performance.
3. As before, add an array of 10 integers to `HomeData` to simulate a larger struct. Re-run the program and observe its performance.
4. Repeat the previous step with 100 integers and again with 1000 integers.

What happens to the performance of this program as the size of `HomeData` increases? Why does this happen?

Before moving to the next step, remove or comment out the integer array that you added.

## Raw pointers

Let's repeat the exercise, but this time we'll allocate memory for the structs from the heap and keep track of it using raw pointers: `HomeData *`. As before, implement the missing code in `raw_ptr.cpp` and feel free to copy from your work on the previous steps. Do not change the function signatures.

You may have noticed that there is an `allocateSalesData` function but no corresponding `deallocate` or `free` function to invoke `delete` on the pointers. This results in a memory leak, but since the program is only used as a microbenchmark and exits immediately (which releases all memory), we will ignore memory leaks in this lab.

When finished with the implementation, run it and observe its performance. Then add a 10-integer array to `HomeData` and observe the effect this has on performance. Repeat with an array of 100 integers, then 1000 integers.

What happens to the performance of this program as the size of `HomeData` increases? Why does this happen?

Before moving to the next step, remove or comment out the integer array that you added.

## Unique smart pointers

To avoid the memory leak problem, we can write the same code using smart pointers instead of raw pointers. Let's do this now in the `unique_ptr.cpp` file. Don't change the function signatures, just implement the code. Remember to "move" the unique pointer when invoking `calculatePricePerSqFt`.

As before, run the program and observe its performance, then again with integer arrays of size 10, 100, and 1000. How does this impact performance and why?

Next, change the `calculatePricePerSqFt` so that it returns `void`, then run the program again. You should see it crash. Why does this happen?

Before moving on, restore `calculatePricePerSqFt` to a working state and remove or comment out the integer array.

## Shared smart pointers

Repeat the same exercise with shared pointers in `shared_ptr.cpp`. Implement the functions, then observe the program's performance. Check the performance again after adding integer arrays of sizes 10, 100, and 1000.

## Conclusion

This lab was an exploration of the various memory management features in C++. The key lessons are:

* Passing by value can be slow because it copies data. Use references (ideally `const`) whenever possible.
* Raw pointers offer dynamic memory, but they can introduce memory leaks. Heap allocations can be slow.
* Smart pointers prevent memory leaks but introduce ownership problems. Avoid passing them as function parameters and instead pass what they point to. (See [C++ Core Guideline F.7](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rf-smart) for more details.)
