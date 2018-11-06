	.text 
	.globl __start
__start: 
	la $a0, str1
	li $v0, 4
	syscall
