# N = 29
.data
	userInput: 	.space 500
	isTooLong:	.asciiz "Input is too long."
	isEmpty:	.asciiz "Input is empty."
	invalidInput:	.asciiz "Invalid base-N number."
.text
	main: 
	li $v0, 8
	la $a0, userInput
	li $a1, 250
	syscall

	isTooLong_Function: 
	la $a0, isTooLong
	li $v0, 4
