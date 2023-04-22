	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	mov	w9, #61856
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #15, lsl #12            ; =61440
	sub	sp, sp, #416
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #44]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	x9, sp
	sub	x8, x29, #124
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_scanf
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	sub	x1, x29, #224
	bl	_output_name
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	str	wzr, [sp, #40]
	add	x1, sp, #48
	bl	_read_csv
	str	w0, [sp, #40]
	ldr	w8, [sp, #40]
	adds	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	str	wzr, [sp, #44]
	b	LBB0_3
LBB0_2:
	ldrsw	x1, [sp, #40]
	add	x0, sp, #48
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	mov	x2, #616
	adrp	x3, _comparison@PAGE
	add	x3, x3, _comparison@PAGEOFF
	bl	_qsort
	ldr	x1, [sp, #16]                   ; 8-byte Folded Reload
	ldr	w2, [sp, #40]
	sub	x0, x29, #224
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_writer
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	str	wzr, [sp, #44]
	b	LBB0_3
LBB0_3:
	ldr	w8, [sp, #44]
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:
	bl	___stack_chk_fail
LBB0_5:
	ldr	w0, [sp, #12]                   ; 4-byte Folded Reload
	add	sp, sp, #15, lsl #12            ; =61440
	add	sp, sp, #416
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_output_name                    ; -- Begin function output_name
	.p2align	2
_output_name:                           ; @output_name
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
	adrp	x8, l_.str.2@PAGE
	add	x8, x8, l_.str.2@PAGEOFF
	str	x8, [sp, #8]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #8]
	ldrb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #8]
	ldrb	w8, [x8]
	ldr	x9, [sp, #16]
	strb	w8, [x9]
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	add	x8, x8, #1
	str	x8, [sp, #16]
	ldr	x8, [sp, #8]
	add	x8, x8, #1
	str	x8, [sp, #8]
	b	LBB1_1
LBB1_4:
	b	LBB1_5
LBB1_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	ldrb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_8
	b	LBB1_6
LBB1_6:                                 ;   in Loop: Header=BB1_5 Depth=1
	ldr	x8, [sp, #24]
	ldrb	w8, [x8]
	ldr	x9, [sp, #16]
	strb	w8, [x9]
	b	LBB1_7
LBB1_7:                                 ;   in Loop: Header=BB1_5 Depth=1
	ldr	x8, [sp, #24]
	add	x8, x8, #1
	str	x8, [sp, #24]
	ldr	x8, [sp, #16]
	add	x8, x8, #1
	str	x8, [sp, #16]
	b	LBB1_5
LBB1_8:
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_read_csv                       ; -- Begin function read_csv
	.p2align	2
_read_csv:                              ; @read_csv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	ldur	x0, [x29, #-16]
	adrp	x1, l_.str.3@PAGE
	add	x1, x1, l_.str.3@PAGEOFF
	bl	_fopen
	stur	x0, [x29, #-32]
	ldur	x8, [x29, #-32]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_2
	b	LBB2_1
LBB2_1:
	mov	w8, #-1
	stur	w8, [x29, #-4]
	b	LBB2_9
LBB2_2:
	stur	wzr, [x29, #-36]
	b	LBB2_3
LBB2_3:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x0, [x29, #-32]
	bl	_feof
	subs	w8, w0, #0
	cset	w8, ne
	mov	w9, #0
	str	w9, [sp, #40]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB2_5
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldur	x0, [x29, #-32]
	bl	_ferror
	subs	w8, w0, #0
	cset	w8, eq
	str	w8, [sp, #40]                   ; 4-byte Folded Spill
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldr	w8, [sp, #40]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB2_8
	b	LBB2_6
LBB2_6:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-24]
	ldursw	x9, [x29, #-36]
	mov	x14, #616
	mul	x9, x9, x14
	add	x13, x8, x9
	ldur	x8, [x29, #-24]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x12, x8, #151
	ldur	x8, [x29, #-24]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x11, x8, #302
	ldur	x8, [x29, #-24]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x10, x8, #453
	ldur	x8, [x29, #-24]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x8, x8, #608
	mov	x9, sp
	str	x13, [x9]
	str	x12, [x9, #8]
	str	x11, [x9, #16]
	str	x10, [x9, #24]
	str	x8, [x9, #32]
	adrp	x1, l_.str.4@PAGE
	add	x1, x1, l_.str.4@PAGEOFF
	bl	_fscanf
	b	LBB2_7
LBB2_7:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB2_3
LBB2_8:
	ldur	x0, [x29, #-32]
	bl	_fclose
	ldur	w8, [x29, #-36]
	stur	w8, [x29, #-4]
	b	LBB2_9
LBB2_9:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_comparison                     ; -- Begin function comparison
	.p2align	2
_comparison:                            ; @comparison
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #16]
	str	x1, [sp, #8]
	ldr	x8, [sp, #16]
	ldr	d0, [x8, #608]
	ldr	x8, [sp, #8]
	ldr	d1, [x8, #608]
	fcmp	d0, d1
	cset	w8, le
	tbnz	w8, #0, LBB3_2
	b	LBB3_1
LBB3_1:
	mov	w8, #-1
	str	w8, [sp, #28]
	b	LBB3_5
LBB3_2:
	ldr	x8, [sp, #16]
	ldr	d0, [x8, #608]
	ldr	x8, [sp, #8]
	ldr	d1, [x8, #608]
	fcmp	d0, d1
	cset	w8, ne
	tbnz	w8, #0, LBB3_4
	b	LBB3_3
LBB3_3:
	str	wzr, [sp, #28]
	b	LBB3_5
LBB3_4:
	mov	w8, #1
	str	w8, [sp, #28]
	b	LBB3_5
LBB3_5:
	ldr	w0, [sp, #28]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_writer                         ; -- Begin function writer
	.p2align	2
_writer:                                ; @writer
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	w2, [x29, #-20]
	ldur	x0, [x29, #-8]
	adrp	x1, l_.str.5@PAGE
	add	x1, x1, l_.str.5@PAGEOFF
	bl	_fopen
	stur	x0, [x29, #-32]
	ldur	x8, [x29, #-32]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB4_2
	b	LBB4_1
LBB4_1:
	b	LBB4_7
LBB4_2:
	stur	wzr, [x29, #-36]
	b	LBB4_3
LBB4_3:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-36]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_6
	b	LBB4_4
LBB4_4:                                 ;   in Loop: Header=BB4_3 Depth=1
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-36]
	mov	x14, #616
	mul	x9, x9, x14
	add	x12, x8, x9
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x11, x8, #151
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x10, x8, #302
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-36]
	mul	x9, x9, x14
	add	x8, x8, x9
	add	x9, x8, #453
	ldur	x8, [x29, #-16]
	ldursw	x13, [x29, #-36]
	mul	x13, x13, x14
	add	x8, x8, x13
	ldr	d0, [x8, #608]
	mov	x8, sp
	str	x12, [x8]
	str	x11, [x8, #8]
	str	x10, [x8, #16]
	str	x9, [x8, #24]
	str	d0, [x8, #32]
	adrp	x1, l_.str.6@PAGE
	add	x1, x1, l_.str.6@PAGEOFF
	bl	_fprintf
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_3 Depth=1
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB4_3
LBB4_6:
	ldur	x0, [x29, #-32]
	bl	_fclose
	b	LBB4_7
LBB4_7:
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Enter the file name: "

l_.str.1:                               ; @.str.1
	.asciz	"%s"

l_.str.2:                               ; @.str.2
	.asciz	"sorted_"

l_.str.3:                               ; @.str.3
	.asciz	"r"

l_.str.4:                               ; @.str.4
	.asciz	"%[^,], %[^,], %[^,], %[^,], %lf\n"

l_.str.5:                               ; @.str.5
	.asciz	"w"

l_.str.6:                               ; @.str.6
	.asciz	"%s,%s,%s,%s,%.2lf\n"

.subsections_via_symbols
