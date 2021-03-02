---
title: 'CA284 Project Report'
date: '2021-01-11'
name: 'Conor Joyce'
studentNo: '19425804'
---

## Introduction

During this project I've improved my C programming a lot and have definitely experienced what it's like to work on a substantial project. The bulk of the code took me about a week to write, with the rest of the time spent testing and fixing bugs.
The algorithms I chose are **Merge Sort** and **Radix Sort**. The reason I chose these is because I have experience in both from my Python module, and I understand how they work, also both are very efficient algorithms - with time complexities of **O(nlogn)** and **O(kn)** respectively.

## Datasets

The datasets I chose are the same as the examples specified in the project spec - Random, Sorted, Partially Sorted and Reverse Sorted.
I chose these as I almost instantly knew how these could be implemented, I also had the idea of a dataset that would consist of every other number being in order, but without being able to think of an obious solution on implementing this off the top of my head, I gave priority to improving the robustness of my code rather than spending time on something I was unsure that I even had the ability to do!

Therefore, my choice in datasets is not very creative, but I do believe they still effectively demonstrate the differences in how different algorithms deal with data.

## Algorithm Performance

The results on the times for each sorting algorithm under many different circumstances can be found in **`results.md`** in the test folder of this repo. Also in this folder you will find different sample datasets, for example `1000000-reverseSorted.txt`, which is a list of 1 million numbers, sorted in reverse.

### Selection Sort

Selection Sort is quite disappointing in its results, which is unsurprisingly as its underlying code is very simple, find the nth smallest element in a list and swap it with the element as position n.

1. As the number of elements in the data sets grew, the amount of time taken to sort grew exponentially, which makes sense as its time complexity is O(n^2). Up to 10,000 numbers, it performs quite well, taking ~100ms. Any order of magnitude greater than this takes a substantial amount of time.
2. When using different types of data, the performance of Selection Sort doesn't change much. Regardless of the type of dataset used, Selection Sort will compare every element to every other element, and swap elements every single loop - this can be prevented with a simple if statement, but then this wouldn't be the standard selection sort, would it?
3. The best-case scenario in my testing was with Random data, but I believe this to be misleading as Sorted data should be the fastest, I think these times are within a margin of error with each other so that may be why. The same number of swaps are performed regardless so the only influencial factor is the number of assignments I believe. The worst-case scenario is with Reverse Sorted data, I believe this is because of it results in the maximum number of assignments possible using Selection Sort, and my results reflect this.

Overall, Selection Sort is an easy to implement algorithm and performs relatively well with small amounts of data, but struggles to keep up once datasets grow in size.

### Merge Sort

Merge Sort is quite impressive, with its divide and conquer approach, it's clear why it results in an efficient and often used algorithm.

1. As the number of elements in the data sets grew, the amount of time taken to sort grew exponentially, but nowhere near to the extent that which Selection Sort's time increased. Its time complexity is O(nlogn) so this makes sense. It performed very well in my tests, sorting 5 million random numbers in just over 1 second.
2. When using different types of data, Merge Sort's performance improves a decent amount. This is evident when you compare the times for a completely random dataset to sorted, partially sorted and even reverse sorted data. Merge Sort handles all of these datasets very well.
3. The best-case scenario in my testing was with Reverse Sorted data, doing ever so slightly better than Sorted. I would have expected it to be the other way around but perhaps this is also within a margin of error, or I don't understand how Merge Sort works as much I as thought I did! The worst-case scenario was Random data, which also makes sense as Merge Sort excels at dealing with already sorted data.

Overall, Merge Sort is very efficient and robust, and can be used for massive datasets with ease.

### Radix Sort

Radix Sort is a very impressive algorithm and I found it surprisingly easy to implement, considering I know the theory behind it. It's a non-comparitive algorithm, sorting using the digits in a number and organising numbers into buckets. It is super efficient and very interesting.

1. As the number of elements in the data sets grew, the amount of time taken to sort grew but not exponentially, the amount of time to sort 2 million numbers is about twice the amount to sort 1 million numbers. This is due to its time complexity of O(kn), which is more or less O(n) but with a constant overhead added.
2. When using different types of data, Radix Sort performs about the same, at least on the datasets I tested. This is most likely due to the way Radix Sort works, putting numbers into buckets regardless of where they already positioned in a list.
3. I can't really give a best or worst case scenario with confidence as all my results were about the same, the best performing in my tests was Reverse Sorted data but this was so close to every other result it is most definitely within a margin of error.

Overall, Radix Sort is one of the fastest sorting algorithms when it comes to large datasets containing numbers, its implementation and how it works is also super interesting to me!

## Negatives

A big issue I had coding my implementation of this was dealing with multiple user inputs, such as dataset size, sorting algorithm to use, input and output filenames, etc.
In the end I decided on simplicity and ease of use for myself and scripting, following the standard Unix-type CLI style, with informative error messages and a help section showing correct syntax. 

I had attempted to have more user input than I do right now, but it only led to a lot of bugs unfortunately. The most annoying of which is the inability to choose an output file in my programs, my compromise being a static macro variable at the top of the source code where it can be changed with relative ease. Another negative is my lack of creativity in datasets, as I explained above.

## Conclusion and Future Work

In conclusion, I found that certain algorithms like Merge Sort and Radix Sort can handle large datasets with ease, but with them being harder to implement than slower algorithms such as Selection Sort. If I had more time, I would have improved the usability for the end user, for example one who isn't as familiar with Unix-like systems and panics upon seeing any error message. Another thing I would had added is more datasets, but due to time constraints and me wanting to ensure the rest of my code was working how I wanted it to, I wasn't able to do this.

An interesting continuation of this analysis for me would be as simple as adding more sorting algorithms and scripting a program to automatically test all of these and output the results, due to the nature in which I went about coding this project, I feel like would not be too hard of a task. It would be very interesting!
