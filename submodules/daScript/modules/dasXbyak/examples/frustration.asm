def primesI_jit(n:int)
    var count = 0
    for i in range(2, n+1)
		count ++
		for j in range(2,i)
			if i % j == 0
				count --
				break
    return count

------------------
x86_64_jit version

0000024E1AC66010  mov r8d, 0x00                     count = 0
0000024E1AC66016  mov r10d, [rdx]
0000024E1AC66019  inc r10d
0000024E1AC6601C  mov r9d, 0x02                     j=2
0000024E1AC66022  cmp r10d, r9d
0000024E1AC66025  jle 0x0000024E1AC66062        END_LOOP_J
LOOP_I:      // 4 + 3 instructions
0000024E1AC66030  inc r8d                           count++
0000024E1AC66033  mov r11d, 0x02                    i = 2
0000024E1AC66039  cmp r9d, r11d
0000024E1AC6603C  jle 0x0000024E1AC6605A        END_LOOP_1
LOOP_J:      // 5 + 3 instructions for normal go
0000024E1AC66040  mov eax, r9d                      if i%j == 0
0000024E1AC66043  cdq
0000024E1AC66044  idiv r11d
000002732CC22047  test edx, edx
0000024E1AC6604B  jnz 0x0000024E1AC66052        CONTINUE_LOOP_J
0000024E1AC6604D  dec r8d                           count--
0000024E1AC66050  jmp 0x0000024E1AC6605A        END_LOOP_J  // break
CONTINUE_LOOP_J:
0000024E1AC66052  inc r11d                          loop(j)
0000024E1AC66055  cmp r11d, r9d
0000024E1AC66058  jnz 0x0000024E1AC66040        LOOP_J
END_LOOP_J:
0000024E1AC6605A  inc r9d                           loop(i)
0000024E1AC6605D  cmp r9d, r10d
0000024E1AC66060  jnz 0x0000024E1AC66030        LOOP_I
END_LOOP_I:

loop_j:
    if i%j==0
        count--
        jump    end_loop_j
    loop    loop_j
end_loop_j:

-----------------
MSVC 2019 version

00007FF73A370DE0  xor         r9d,r9d                   count = 0
00007FF73A370DE3  lea         r11d,[rcx+1]
00007FF73A370DE7  mov         r8d,2                     i = 2
00007FF73A370DED  cmp         r11d,r8d
00007FF73A370DF0  je          07FF73A370E2Eh        END_LOOP_J
LOOP_I: // 5 + 3 instructions
00007FF73A370E00  mov         r10d,r9d                  temp_count = count
00007FF73A370E03  mov         ecx,2                     j = 2
00007FF73A370E08  inc         r9d                       count ++
00007FF73A370E0B  cmp         r8d,ecx
00007FF73A370E0E  je          07FF73A370E26h        CONTINUE_LOOP_2
LOOP_J: // 5 + 3 instructions for normal go
00007FF73A370E10  mov         eax,r8d               if i%j==0
00007FF73A370E13  cdq
00007FF73A370E14  idiv        eax,ecx
00007FF73A370E16  test        edx,edx
00007FF73A370E18  je          07FF73A370E23h        BREAK_AND_FINISH_LOOP_J
00007FF73A370E1A  inc         ecx                       loop(j)
00007FF73A370E1C  cmp         ecx,r8d
00007FF73A370E1F  jne         07FF73A370E10h        LOOP_J
END_LOOP_J:
00007FF73A370E21  jmp         07FF73A370E26h        CONTINUE_LOOP_I
BREAK_AND_FINISH_LOOP_J:
00007FF73A370E23  mov         r9d,r10d                  count = temp_count // same as count --
CONTINUE_LOOP_I:
00007FF73A370E26  inc         r8d                       loop(i)
00007FF73A370E29  cmp         r8d,r11d
00007FF73A370E2C  jne         07FF73A370E00h        LOOP_I
END_LOOP_J:

loop_j:
    if ! (i%j==0)
        jump    break_loop_j
    loop    loop_j
    jump    end_loop_j
break_loop_j:
    count --
end_loop_j:


