# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			# register and pushes the base pointer onto the stack
	movq  %rsp, %rbp		# move the datas to make a copy to destination.

					# (2) What is going on here
					# Ans:
	movq $1, %rax			# set value 1 to register rax.
	movq $1, %rdi			# set value 1 to register rdi.
	leaq .hello.str,%rsi		# Load effective address that put value to the location.


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: it's the system which going to call to use. This is important for system to know which to calls.
	syscall				# Which syscall is being run?
					# Ans: ?Linux in functions for system calls.

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: use other functions and defines pre for use.

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: set value 60 and 0 to register rax and rdi.
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans: know the size and location for print.
