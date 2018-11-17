# N = 29
.data
	userInput: 	.space 500
	isTooLong:	.asciiz "Input is too long."
	isEmpty:	.asciiz "Input is empty."
	invalidInput:	.asciiz "Invalid base-N number."
.text
	main: #gets the user input
		li $v0, 8
		la $a0, userInput
		li $a1, 250
		syscall

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

	deleteSpace:
		li $t8, 32 #loads a space into temporary register
		lb $t9, 0($a0) #takes the memory from temp register makes it NULL and store it to register a0
