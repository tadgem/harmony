
options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def init_arg_to_local ( arg:int )
    var res = arg
    return res

[test]
def test_init_arg_to_local(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@init_arg_to_local)
        for e in range(10)
            t |> strictEqual( init_arg_to_local(e+1), e+1)

[jit_x86_64]
def copy_arg_to_local ( arg:int )
    var res : int
    res = arg
    return res

[test]
def test_copy_arg_to_local(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@copy_arg_to_local)
        for e in range(10)
            t |> strictEqual( copy_arg_to_local(e+1), e+1)

[jit_x86_64]
def copy_local_to_local ( arg:int )
    var res : int
    res = arg
    return res

[test]
def test_copy_local_to_local(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@copy_local_to_local)
        for e in range(10)
            t |> strictEqual( copy_local_to_local(e+1), e+1)

[jit_x86_64]
def copy_local_to_arg ( var arg:int )
    var res = arg + 1
    arg = res
    return res

[test]
def test_copy_local_to_arg(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@copy_local_to_arg)
        for e in range(10)
            t |> strictEqual( copy_local_to_arg(e+1), e+2)

[export]
def main
    test_jit_levels(false,true) <|
        let q = copy_local_to_arg(11)
        print("q = {q}\n")