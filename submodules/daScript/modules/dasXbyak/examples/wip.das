options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

/*
def recv3(n1,n2,n3:int)
    print("recv3 {n1} {n2} {n3}\n")

[jit_x86_64(asm)]
def test_call(i:int)
    recv3(i,2,3)

[test]
def main
    test_call(13)
*/

[jit_x86_64(asm)]
def fibR_jit(n:int)
    if (n < 2)
        return n
    return fibR_jit(n - 1) + fibR_jit(n - 2)

[export]
def main
    fibR_jit(31)
