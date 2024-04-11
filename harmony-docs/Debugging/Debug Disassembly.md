```
uint64_t harmony::HashString::Hash(const String &input) {
00007FF66AD1B960  mov         qword ptr [rsp+8],rcx  
00007FF66AD1B965  push        rsi  
00007FF66AD1B966  push        rdi  
00007FF66AD1B967  sub         rsp,88h  
00007FF66AD1B96E  lea         rdi,[rsp+20h]  
00007FF66AD1B973  mov         ecx,1Ah  
00007FF66AD1B978  mov         eax,0CCCCCCCCh  
00007FF66AD1B97D  rep stos    dword ptr [rdi]  
00007FF66AD1B97F  mov         rcx,qword ptr [input]  
    uint64_t r;
    for (int i = 0; i < input.size(); i++) {
00007FF66AD1B987  mov         dword ptr [rsp+34h],0  
00007FF66AD1B98F  jmp         harmony::HashString::Hash+3Bh (07FF66AD1B99Bh)  
00007FF66AD1B991  mov         eax,dword ptr [rsp+34h]  
00007FF66AD1B995  inc         eax  
00007FF66AD1B997  mov         dword ptr [rsp+34h],eax  
00007FF66AD1B99B  movsxd      rax,dword ptr [rsp+34h]  
00007FF66AD1B9A0  mov         qword ptr [rsp+70h],rax  
00007FF66AD1B9A5  mov         rcx,qword ptr [input]  
00007FF66AD1B9AD  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::size (07FF669D9B3BFh)  
00007FF66AD1B9B2  mov         rcx,qword ptr [rsp+70h]  
00007FF66AD1B9B7  cmp         rcx,rax  
00007FF66AD1B9BA  jae         harmony::HashString::Hash+97h (07FF66AD1B9F7h)  
        char c = input[i];
00007FF66AD1B9BC  movsxd      rax,dword ptr [rsp+34h]  
00007FF66AD1B9C1  mov         rdx,rax  
00007FF66AD1B9C4  mov         rcx,qword ptr [input]  
00007FF66AD1B9CC  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator[] (07FF669D33B66h)  
00007FF66AD1B9D1  movzx       eax,byte ptr [rax]  
00007FF66AD1B9D4  mov         byte ptr [rsp+38h],al  
        r ^= 397 * c;
00007FF66AD1B9D8  movsx       eax,byte ptr [rsp+38h]  
00007FF66AD1B9DD  imul        eax,eax,18Dh  
00007FF66AD1B9E3  cdqe  
00007FF66AD1B9E5  mov         rcx,qword ptr [r]  
00007FF66AD1B9EA  xor         rcx,rax  
00007FF66AD1B9ED  mov         rax,rcx  
00007FF66AD1B9F0  mov         qword ptr [r],rax  
    }
00007FF66AD1B9F5  jmp         harmony::HashString::Hash+31h (07FF66AD1B991h)  
    log::info("HashString : Hashing Input : {} : Result {}", input, r);
00007FF66AD1B9F7  lea         rax,[rsp+40h]  
00007FF66AD1B9FC  mov         qword ptr [rsp+50h],rax  
00007FF66AD1BA01  lea         rdx,[__real@42c00000+4BCh (07FF66BFB2E08h)]  
00007FF66AD1BA08  mov         rcx,qword ptr [rsp+50h]  
00007FF66AD1BA0D  call        fmt::v9::basic_format_string<char,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const & __ptr64,unsigned __int64 & __ptr64>::basic_format_string<char,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const & __ptr64,unsigned __int64 & __ptr64><char [44],0> (07FF669DA6AA8h)  
00007FF66AD1BA12  lea         rcx,[rsp+60h]  
00007FF66AD1BA17  mov         rdi,rcx  
00007FF66AD1BA1A  mov         rsi,rax  
00007FF66AD1BA1D  mov         ecx,10h  
00007FF66AD1BA22  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF66AD1BA24  lea         r8,[r]  
00007FF66AD1BA29  mov         rdx,qword ptr [input]  
00007FF66AD1BA31  lea         rcx,[rsp+60h]  
00007FF66AD1BA36  call        spdlog::info<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const & __ptr64,unsigned __int64 & __ptr64> (07FF669D5DA29h)  
    return r;
00007FF66AD1BA3B  mov         rax,qword ptr [r]  
}
```