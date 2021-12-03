Please edit this document below with your responses. Each question is worth 1/8 of your lab.

# Exercise 1

1. Record here how long it took you to run bubblesort and csort (Note: If you want to run several trials, say '10' and take an average that is an even better result!).

*edit your answer here for question 1* 1.518s vs 0.009s

# Exercise 2

What is the Big-O complexity of bubblesort?

1. *edit your answer here for question 2* O(n2)

# Exercise 3

Do a little research and discover what algorithm qsort is in the C standard library. What is the algorithm? https://en.wikipedia.org/wiki/Qsort

1. *edit your answer here for question 3* The algorithm was developed by a British computer scientist Tony Hoare in 1959. The name "Quick Sort" comes from the fact that, quick sort is capable of sorting a list of data elements significantly faster (twice or thrice faster) than any of the common sorting algorithms. It is one of the most efficient sorting algorithms and is based on the splitting of an array (partition) into smaller ones and swapping (exchange) based on the comparison with 'pivot' element selected. Due to this, quick sort is also called as "Partition Exchange" sort. Like Merge sort, Quick sort also falls into the category of divide and conquer approach of problem-solving methodology.

# Exercise 4

What is the Big-O complexity of 'qsort' that we use in the csort program?

1. *edit your answer here for question 4* O(n2)

# Exercise 5

Is qsort's Big-O complexity better or worse than bubblesort? (Anser: Yes it is better/ No it is worse/ It is equal)

1. *edit your answer here for question 5* worse case It is equal as O(n2)

# Exercise 6

List the following functions in terms of their Big-O complexity from **smallest** to **largest**.
<img src="./media/bigo.jpg"/>

1. *edit your answer here for question 6* logN,N,N2,N3,2N,N!

# Exercise 7

- Given: f(n) = 3n^3 + n^2 + 27
- What is the O(n) of f(n)?

1. *edit your answer here for question 7* n^3

# Exercise 8

- Given: f(n) = 3n^3 + n^2 + 27
- What are two constants c and k that prove your answer in exercise 7. c=30,k=1
