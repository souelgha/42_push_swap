# Sort data on a stack with limited set of instructions
 Write a C program which sorts and displays on the standard output the integers received as arguments.

## We have 2 stacks and a set of instructions to manipulate both stacks.
  - sa (swap a) : swap the 2 first elements at the top of stack A.
  - sb (swap b ) : swap the 2 first elements at the top of stack B.
  - ss : sa et sb at the same time.
  - pa (push a) :  take the  first element at the top of stack b and put at the top of A.
  - pb (push b) :  take the  first element at the top of stack a and put at the top of B.
  - ra (rotate a) : shift up all elements of stack A by 1. the first become last one.
  - rb (rotate b) : shift up all elements of stack B by 1. the first become last one.
  - rr : ra et rb at the same time.
  - rra (reverse rotate a) : shift down all elements of stack A by 1. the last become first one.
  - rrb (reverse rotate b) : shift down all elements of stack B by 1. the last become first one.
  - rrr : rra et rrb at the same time.
    
## Algo used
- We push (pb) in B until there are only three elements left in A. we sorted A by descending order.
- As long as B is not empty, we look for the element of B that will require the least number of instructions to reach A (in the right place). for that :
  - calculate target element from stack A for each B element.
  - calculate the cost value (number of instructions we need to put element at the right place in A).
  - choose the cheapest one
  - and move it to the top of stack A.
  - recalculate target element and cost value after each push a.
 - At the end rotate A to put the smallest element on top.
 
