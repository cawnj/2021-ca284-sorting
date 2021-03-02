---
title: 'CA284 Project'
date: 2020-11-30
summary: 'The Week 10+ CA284 Assessment'
topic:
topicNumber: 
weekNumber: 9
layout: 'layouts/lab.html'
labNumber: 
---

## Introduction

One of the most important skills for any developer to possess is knowing how to analyse how well their program is performing.  It is often necessary to look at systems to see how they can be tweaked or improved in order to improve their utilisation of system resources.  this project aims to do the following:

- to introduce you to writing larger-scale programs;
- To introduce you to performing analysis on program performance;
- To enable you to develop analytical skills through examination of results and data;
- To introduce you to aspects of presentation of results and findings on your program.

This is _an individual project_.  You should refer to the DCU academic integrity policy, and also the resources shared as part of this module's website before embarking on this project.

## Project Description

There are many ways to sort data.  These range from relatively simple algorithms such as _selection sort_ to more complex methods such as _Radix Sort_.  Some get the job done but lack efficiency on larger data sets.  the _C standard library_ even has its own sort function which is available to use.  

This project is all about measuring relative performance and trying to improve the efficiency of your code.  You will be working with data sets of integers of differing sizes.  They will also be arranged in different ways.  Your job is to run various algorithms over the data sets and see how efficiently they handle them.

The first thing you will do is to choose three algorithms.  You will run the algorithms on the same data sets and observe the results.  

On completion, you will analyse the results and either write a 
report detailing your findings or prepare a short video presentation providing the same information.  The exact contents of this report will be communicated _on 6th january 2021_.

## Step-by-step Details
### Step 0: Setting Up your Development Environment

In this project you are expected to use the [School of Computing Gitlab Instance](https://gitlab.computing.dcu.ie) to manage your code, test-data and final report/video.  On Wednesday 2nd November at 16:00 a _gitlab repository_ will be made available to you.  This _gitlab repository_ will give you the directory structure  (and possibly one or two other things) which might be of use.  You will need to:

1. Fork this repository.
2. Keep the same name as the original repository.
3. Give the _module coordinator_ (Donal fitzpatrick) access to your repository.  He requests that you give him "maintainer" permissions.  You _must make the repository private_ and you may not share it with any other individual.

**note** you _must use gitlab_ to manage your project resources; this is _not an optional requirement_.  You should also regularly commit to the repository, and make use of any other aspects of _git_ with which you are familiar.

You may of course integrate this repository with _Visual Studio Code_ or any other text editor/development environment with which you work.  For something like this project, _gitlab_ will give you the safeguards to know that your work is regularly backed up.  Also if you make tweaks to your code (see below), and they don't work, you can always roll back to a previous version very easily.

### Step 1: Preparing your Data

The first thing you need to do is to write a short little program which generates a series of random integers.  There are no marks for this but it will help you.  YOu can always expand on this later if you wish.  Start with a program which takes a command-line argument and simply generates that number of integers.  You can run this and pipe the output into a file, or you can save the data you generate to a file in the program itself.  This way you're not typing in lots of numbers each time you want to run your program.  You can do some interesting things with this program as you go. for example:

1. you can generate datasets in random order;
2. you can generate partially sorted sets of numbers.  In other words: some of the data is sorted and some of it is still in random order.
3. You can generate reverse sorted data.
4. You can generate datasets which are already sorted before passing them to your own algorithms.  Why would you want to do this?  You tel me...

The following little snippets of _C code_ might be handy for you.  The first shows how to call the _sorting function_ which is provided in the _standard library_:

``` c
qsort (numbers, size, sizeof (int), compare_ints); // presumes an array of type int called numbers is to be sorted

/*** function compare_ints
** @params: void pointer a, void pointer b
** returns: int (negative if a<b, 0 if a=b, positive if a>b)
Description:  Modified from: https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html
*/

int compare_ints (const void *a, const void *b)
{
const int *da = (const int *) a;
const int *db = (const int *) b;

return (*da > *db) - (*da < *db);
}
```

Using this you can:

1. sort sub-sections of an array;
2. modify the comparison function to sort in reverse.
3. other things.

Note: you are not obliged to use this; but some of you may find it handy.

### Step 2: Your first algorithm

Take a nice easy algorithm like _Selection Sort_ or similar and sort the data.  Use this as your tester.  What you want to do is:

1. run the algorithm on, say, ten integers;
2. make sure that it works.
3. now run it on 1000.
4. make sure it works.
5. run it on 100,000.
6. Make sure that it works.
7. Run it on 1, 2, 5 million integers.
8. make sure that it works.

Once you're sure that it will handle this amount of data, time it.  You won't really detect much time passing below a certain threshold (I'll leave it to you to figure this out).  However make a note of your findings.  Does the algorithm increase by the amount of time you thought it would as the number of integers you pass to it increases?  For example: if you increase the number of integers from 1-to-2 million, you're doubling the amount of things it has to sort. What happens to the time that it takes the algorithm to run?

### Step 2: Algorithms two and 3

This is where you get creative.  Using _exactly the same approach_ as outlined in the previous section, write two more algorithms.  Marks will be awarded depending on how complex the algorithms you choose are.  For example: Something like a _Radix Sort_ will be worth far more marks than _Bubblesort_.  Again though, you need to be observing what is happening with your algorithms in the context of your data.

### Step 3: Playing with Data

Remember that discussion we had in the context of the initial program in Step 1?  This is where it comes into its own.  You need to come up with lots of different types of data-sets on which to run your algorithms.  So if you think about this little program before you do anything else, modifying it to produce the data you need to test your algorithms, or get data concerning their performance, will be far easier than if you don't give this a bit of time.

### Optimising Performance

You should do some research into things which slow a program down or give it that little extra kick of speed.  Are you using system resources efficiently?  Is your code passing data around in a way which enables it to run at optimal speed?  Is there anything you can do to make your various algorithms run faster?  If you discover tweaks which you can make, then take note of them.  You'll need them later.  Inefficient code will garner less marks than code which clearly shows that you have thought about how efficient it is.  Note that getting things wrong is okay.  If something doesn't work, make a note of that too.  For example: if you try a tweak to an algorithm and it runs slower, and you identify the reason then you've learned something.  Again make a note of this too.

## The Analysis

The exact questions your report (or video) will have to answer are not going to be released just now.  On the morning of _6th January 2021_ a series of questions and/or topics will be made available via the course website.  You will be required to write a short report, or prepare a brief presentation commenting on the questions which will be provided. You will submit everything (code, test data and analysis) by 14:00 on 11th January 2021y.  Suffice it to say that you should:

1. make notes on the reasons you designed your programs in the way which you did.
2. Make notes on the performance of your algorithms in the context of the various data-sets you generate.
3. Make notes on the types of data-set you generate, and the reason for doing so.
4. Make _sure you understand_ all of the algorithms you choose to implement.
5. If you make any performance improvements to your code, document them and the improvement (or disimprovement) which happened as a result.  Always remember that some of the best research has come out of situations where something the team tried failed.  Finding out that something doesn't work can be as important as determining that it does. _DO NOT_ be afraid to report failure _particularly_ if you can explain why the thing you tried didn't work.

In terms of the report structure itself, you will be given the layout you should follow.  Ine ssence, You will simply be given a series of questions based on what you have done.  You can include personal observations and findings in your answers; indeed you will need to do so.  the report will be about 800-1000 words long, or a 2-2.5 minute presentation which you can submit as a video.

Note that _some students may be contacted in the week following submission_.  Should this happen, those contacted will be asked further quesstions on their submissions.

## Submission

The submission will simply be the _gitlab repository_.  After the deadline, you will not be permitted to commit anything more to the repository.  If commits are detected after the deadline, then the repository will be rolled back to the last commit prior to the deadline.   

## Marks breakdown

This overall project is worth 50%.  It breaks down as follows:

- Code for the algorithms: 15%.  There are 3 marks going for the initial "easy" algorithm, and up to 6 for each of the other two.
- Choice of data sets: 5% (I.e., how many did you use, how creative were you etc.).  Here I'm looking to see how well you tested the algorithms.
- report and analysis: 30%.  Further breakdown of marks will be given as part of the questions to be released on 6th January.

## Updates

The following questions have been asked, and have not been addressed in the main body of the spec:

### 1.Can the deadline be extended?

yes it has been, however I _cannot_ accept submissions beyond this point. it's _absolutely as late as I can make it_.

### 2. Do we lose marks if our programs can't take over a certain amount of numbers?

this depends.  If you show evidence that you have used _heap memory_, understand pointers, and can explain why they don't work above a certain point then any marks lost will be minimal.  Failure to use _heap memory_, or programs which only accept a relatively small number of integers _will lose marks_.

### 3. Is it okay to write one general “driver function” in one program and change it depending on what sorting algorithm you are testing? 

Personally I would look at this another way:  You want to test the program's algorithms rigorously.  So why not have a program which call the three of them on the same data set and notes results for each?  However the basic principle of a standard driver program, running similar tests on different algorithms is the same basic idea.

### Report layout:

See above.

### 5. How many marks am I potentially losing for picking simpler algorithms over more complex ones? 

See above.

### 6.  Should the report only contain the answers to the questions that will be released on the 6th or should it also contain personal notes , analysis and observations you had throughout the project?

See above.


## Wrapping UP

this is a project which will take some time to complete.  The algorithms will need a certain amount of time to run on the various data-sets.  _Don't leave this until the last minute_.  It is _not_ a project which can be turned around in a day.
