options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

var A, B : int

def output_result(a,b:int)
    A = a
    B = b
    return 123

[jit_x86_64]
def test_call(n:int)
    let q = output_result(n,n+1)
    return q + 1

[test]
def test_inc_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_call)
        A = -1
        B = -1
        let res = test_call(13)
        t |> equal(res,124)
        t |> equal(A,13)
        t |> equal(B,14)


