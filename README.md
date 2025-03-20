# Sort data on a stack with limited set of instructions
 Write a C program which sorts and displays on the standard output the integers received as arguments.

## We have 2 stacks and a set of instructions to manipulate both stacks.
  - sa (swap a) : swap the 2 first elements at the top of stack a.
  - sb (swap b ) : swap the 2 first elements at the top of stack b.
  - ss : sa et sb at the same time.
  - pa (push a) :  take the  first element at the top of stack b and put at the top of a.
  - pb (push b) :  take the  first element at the top of stack a and put at the top of b.
  - ra (rotate a) : shift up all elements of stack a by 1. the first become last one.
  - rb (rotate b) : shift up all elements of stack b by 1. the first become last one.
  - rr : ra et rb at the same time.
  - rra (reverse rotate a) : shift down all elements of stack a by 1. the last become first one.
  - rrb (reverse rotate b) : shift down all elements of stack b by 1. the last become first one.
  - rrr : rra et rrb at the same time.
