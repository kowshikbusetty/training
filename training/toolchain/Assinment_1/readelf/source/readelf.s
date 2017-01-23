	.file	"readelf.c"
	.section	.rodata
.LC0:
	.string	"No files are passed "
.LC1:
	.string	"r"
.LC2:
	.string	"file opening failed"
	.align 4
.LC3:
	.string	"Error: test: Failed to read file's magic number"
.LC4:
	.string	"FILE: \t %s\n"
.LC5:
	.string	"Section Headers : "
	.align 4
.LC6:
	.string	"[Nr] Name\tType\t\tAddr\tOff\tSize\tES\tFlg\tLk\tInf\tAl"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
	movl	$0, 28(%esp)
	movl	$52, (%esp)
	call	malloc
	movl	%eax, 24(%esp)
	movl	$52, (%esp)
	call	malloc
	movl	%eax, 28(%esp)
	cmpl	$1, 8(%ebp)
	jg	.L2
	movl	$.LC0, (%esp)
	call	puts
.L2:
	movw	$1, 18(%esp)
	jmp	.L3
.L7:
	movswl	18(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	$.LC1, 4(%esp)
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, 20(%esp)
	cmpl	$0, 20(%esp)
	jne	.L4
	movl	$.LC2, (%esp)
	call	perror
	movl	$1, (%esp)
	call	exit
.L4:
	movl	20(%esp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$52, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	fread
	testl	%eax, %eax
	jne	.L5
	movl	$.LC3, (%esp)
	call	perror
	movl	$1, (%esp)
	call	exit
.L5:
	movswl	18(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	elf_func
	movl	$.LC5, (%esp)
	call	puts
	movl	$.LC6, (%esp)
	call	puts
	movl	24(%esp), %eax
	movl	32(%eax), %edx
	movl	24(%esp), %eax
	movzwl	46(%eax), %eax
	movzwl	%ax, %ecx
	movl	24(%esp), %eax
	movzwl	50(%eax), %eax
	movzwl	%ax, %eax
	imull	%ecx, %eax
	addl	%edx, %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	fseek
	movl	24(%esp), %eax
	movl	32(%eax), %eax
	addl	$40, %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	fseek
	movl	20(%esp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$52, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	fread
	testl	%eax, %eax
	jne	.L6
	movl	$.LC3, (%esp)
	call	perror
	movl	$1, (%esp)
	call	exit
.L6:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	sec_hdr_fun
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	fclose
	movzwl	18(%esp), %eax
	addl	$1, %eax
	movw	%ax, 18(%esp)
.L3:
	movswl	18(%esp), %eax
	cmpl	8(%ebp), %eax
	jl	.L7
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
