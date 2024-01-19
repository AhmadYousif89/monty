# This file demonstrates basic Monty operations
// Comment using [#, //]
// Printing values happens from top to bottom in case of stack

push 10				// Push 10 onto the stack
push -20			// Push 20 onto the stack
pall				// Print all values (outputs: 20 10) 
add					// Add the top two values (10 + 20 = 30)
pint				// Print the top value (outputs: 30) after replacing the top two values
pop					// Remove the top and only value (30)
push 5				// Push 5 onto the stack
push 4				// Push 4 onto the stack
swap				// Swap the top two values (4 and 5)
pall				// Print all values (outputs: 5 4)
pop					// Remove top value (5)
pop					// Remove top value (4)
pall				// Print all values (outputs: )
push 72				// Push 72 onto the stack
push 101			// Push 101 onto the stack
push 108			// Push 108 onto the stack
push 108			// Push 108 onto the stack
push 111			// Push 111 onto the stack
pall				// Print all values (outputs: 111 108 108 101 72)
pchar				// Print the top value as a character (outputs: o)
pstr				// Print all values inside the stack as a string (outputs: olleH)
rotr				// Move last node to the top of the stack
pstr				// Print all values as a string (outputs: Holle)
rotl				// Move top node to the bottom of the stack
pstr				// Print all values as a string (outputs: olleH)
prevs				// Print all values in reverse as a string (outputs: Hello)
