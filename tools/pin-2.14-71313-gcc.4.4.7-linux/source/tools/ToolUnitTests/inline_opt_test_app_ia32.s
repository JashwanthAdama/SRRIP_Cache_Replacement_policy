.global scratchVals

.text
.global GetIntegerScratches
.type GetIntegerScratches,  @function
GetIntegerScratches:
    push %esi
    lea scratchVals, %esi
    mov %eax, (%esi)
    mov %ecx, 0x4(%esi)
    mov %edx, 0x8(%esi)
    pop %esi
    ret
