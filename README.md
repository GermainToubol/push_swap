# Push-swap
Sort a stack using a constraint number of instruction

## Introduction
The aim of this project is to build a program able to give a short set of
instructions to sort a given list of integers with te following constraints:

 * Sorting can be done by moving the elements between two stacks
 * You can perform the following operations only:
   * _pa_, _pb_: push the top element from one stack to the other
   * _sa_, _sb_, _ss_: swap the top and the second element of the stack
   * _ra_, _rb_, _rr_: take the top element and put it at the bottom of the
     stack
   * _rra_, _rrb_, _rrr_: take the bottom element and put it at top of the stack

## Strategy
I chose to address this problem using a
[quicksort](https://en.wikipedia.org/wiki/Quicksort) approach, allowing to to
have a realy good computational performance (even if the project was not ment
originaly to handle more than 500 elements).

The tricky part of the execution of is to always split and join the current
subset in the right order to minimize the sorting instructions list.

## Use
This project is made of two parts:
 * The _push-swap_ program, to sort the integers
 * The _checker_, designed to assure that the set of instructions sorts the
   stack.
~~~bash
 ./push_swap 2 1
 $ARG = $(seq 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
~~~
