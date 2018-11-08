	.text 
	.globl __start
__start: 
	la $a0, str1
	li $v0, 4
	syscall
	
	li $v0, 8
	la $a0, buffer
	li $a1, 4
	move $t0, $a0
	syscall

