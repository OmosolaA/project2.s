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

	stringLength: #sets the length of the function and moves it from $a0 to $t4
		beqz $t0, isEmpty_Function
		slti $t3, $t0, 5 
		beqz $t3, isTooLong_Function
		move $a0, $t4
		j stringTest

	stringTest: #does all the string conversions based on the N
		lb $t5, 0($a0) #takes memory from t5 and put it in a0
		beqz $t5, stringConversion
		beq $t5, $t1 stringConversion #compares strings stored in t5 and t1
		slti $t6, $5, 48
		bne $t6, $zero, invalidInput #if t6 and  zero are not equal than input is invalid 
		slti $t6, $t5, 58
		bne $t6, $zero, moveChar #if t6 and zero are not equal then move the character 
		slti $t6, $t5, 65
		bne $t6, $zero, invalidInput 
		slti $t6, $t5, 84 #65 + 29 "N"  - 10 
		bne $t6, $zero, moveChar
		slti $t6, $t5, 97
		bne $t6, $zero, invalidInput
		slti $t6, $t5, 116 #97 + 29 "N"  - 10
		bne $t6, $zero, moveChar
		bgt $t5, 117, invalidInput #97 + 29 "N" - 9

	moveChar: 
		addi $a0, $a0, 1
		j stringTest
	
	stringCoversion: #converts string to character
		move $a0, $t4 #move value in a0 to temporary register
		addi $t7, $t7, 0
		add $s0, $s0, $t0
		addi $s0, $s0, -1
		li $s3, 3
		li $s2, 2
		li $s1, 1
		li $s5, 0
	
	baseConversion: 
		lb $s4, 0($a0)
		beqz $s4, printString
		beq $s4, $t1, printString
		slti $t6, $s4, 58
		bne $t6, $zero, baseTen	
		slti $t6, $s4, 88
		bne $t6, $zero, base33Up
		slti $t6, $s4, 120
		bne $t6, $zero, base33Low

	baseTen:

