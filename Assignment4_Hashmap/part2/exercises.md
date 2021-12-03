# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap?
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity?
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. *edit your answer here for Part 2 question 1* I think so, HashMap is backed by a combination of Bins and TreeBin-TreeNodes data structure. Memory-wise, this data structure would end up being non-contiguous, with each node/bin containing a pointer to adjacent nodes/bins, and allows a resize to execute into various addresses across memory.
2. *edit your answer here for Part 2 question 2* I suggest define the bucket max capacity, if the bucket max capacity reached, put into next bucket, to make more evenly.
3. *edit your answer here for Part 2 question 3* It best and average case for Search, Insert and Delete is O(1) and worst case is O(n).
4. *edit your answer here for Part 2 question 4* Like separate chaining, open addressing is a method for handling collisions. In Open Addressing, all elements are stored in the hash table itself. So at any point, the size of the table must be greater than or equal to the total number of keys.


