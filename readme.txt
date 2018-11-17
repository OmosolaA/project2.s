# N = 29
.data
	userInput: 	.space 500
	isTooLong:	.asciiz "Input is too long."
	isEmpty:	.asciiz "Input is empty."
	invalidInput:	.asciiz "Invalid base-N number."

	main: #gets the user input
		li $v0, 8
		la $a0, userInput
		li $a1, 250
		syscall

.text
	isTooLong_Function: #calls isTooLong and prints the string
		la $a0, isTooLong
		li $v0, 4
		syscall
		j exit # jump to exit

	isEmpty_Function: # calls isEmpty and prints the string
		la $a0, isEmpty
		li $v0, 4
		syscall 
		j exit # jump to exit

	invalidInput_Function:
		la $a0, invalidInput
		li $v0, 4
		syscall
		j exit

	deleteChar: #adds 1 to $a0 and goes back to the deleteSpace function
		addi $a0, $a0, 1
		j deleteSpace 

	deleteSpace:
		li $t8, 32 #loads a space into temporary register
		lb $t9, 0($a0) #takes the memory from temp register makes it NULL and store it to register a0
		beq $t8, $t9 deleteChar #compares $t8 and $t9 to seee if equal if so deleteChar
		move $t9, $a0 #move null space in $t9 to $a0
		j inputLength

	inputLength:
		addi $t0, $t0, 0 #empties the temp register by giving it a null value
		addi $t2, $t2, 10 #give 10 bytes to temp register
		add $t4, $t4, $a0
	
	stringIteration: 
		lb $t2, 0($a0) #takes memory from $t2 to store in $a0
		beqz $t2, stringLength
		beq $t2, $t1, stringLength #compares length of values stored in $t2 and $t1
		addi $a0, $a0, 1
		addi $t0, t0, 1
		j stringIteration

	stringLength:
		beqz $t0, isEmpty_Function	
