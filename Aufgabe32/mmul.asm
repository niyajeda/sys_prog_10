.text

.global mmul

#void mmul(int n)
mmul:
    pushl %ebp
    movl  %esp, %ebp
    
    subl $20, %esp   #lokale Variable i

    #i = n
    movl 16(%ebp), %eax    
    #movl %eax,-4(%ebp)
    pushl %ebx    

    movl $0, -8(%ebp) #y=0
firstloop:    
    movl -8(%ebp), %eax
    cmpl %eax, 8(%ebp) #y<n?
    jge exit
    incl -8(%ebp) #y++
    movl $0, -4(%ebp) #x=0
secondloop:
    movl -4(%ebp), %eax
    cmpl %eax, 16(%ebp) #x<k?
    jge exit1
    incl -4(%ebp) #x++    
    movl $0, -16(%ebp) #temp = 0
    movl $0, -12(%ebp) #z=0
thirdloop:
    movl -12(%ebp), %eax
    cmpl %eax, 12(%ebp) #z<m?
    jge exit2 
    incl -12(%ebp)  #z++ 
    #loopbody temp += M1[y*m+z]*M2[z*k+x];
    #test
    movl $42, -12(%ebp)
    jmp thirdloop
exit2:
    #M[y*k+x] = temp
    jmp secondloop
exit1:
    jmp firstloop
exit:
    popl %ebx
    leave
    ret


#void mmul(int n, int m, int k, int *M1, int *M2, int *M)
#{
#  int x;  %ebp-4
#  int y;  %ebp-8
#  int z;  %ebp-12
#  int temp; %ebp-16
#  for (y=0;y<n;y++) {
#    for (x=0;x<k;x++) {
#      temp = 0;
#      for (z=0;z<m;z++){
#	        temp += M1[y*m+z]*M2[z*k+x];
#      }
#     M[y*k+x] = temp;
#    }
#  }
#}*/
