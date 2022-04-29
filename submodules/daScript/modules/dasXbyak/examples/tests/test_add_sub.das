
options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def add_jit ( a, b: int )
    return a + b

[jit_x86_64]
def sub_jit ( a, b: int )
    return a - b

[jit_x86_64]
def add_equ_jit ( a, b: int )
    var c = a
    c += b
    return c

[jit_x86_64]
def sub_equ_jit ( a, b: int )
    var c = a
    c -= b
    return c

[test]
def test_add_sub(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@add_jit)
        verify_jit(t, @@sub_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                t |> strictEqual( add_jit(i,j), i+j)
                t |> strictEqual( sub_jit(i,j), i-j)

[test]
def test_add_sub_equ(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@add_equ_jit)
        verify_jit(t, @@sub_equ_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                t |> strictEqual( add_equ_jit(i,j), i+j)
                t |> strictEqual( sub_equ_jit(i,j), i-j)

[jit_x86_64]
def add3_jit ( a, b, c: int )
    return a + b + c

[jit_x86_64]
def add3_local_jit ( a, b, c: int )
    // this one generates lea for a 3-way add
    let A = a
    let B = b
    let C = c
    return A + B + C

[test]
def test_add3_sub(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@add3_jit)
        verify_jit(t, @@add3_local_jit)
        for i in range(-10,10)
            for j in range(-10,10)
                for k in range(-10,10)
                    t |> strictEqual( add3_jit(i,j,k), i+j+k)
                    t |> strictEqual( add3_local_jit(i,j,k), i+j+k)

[export]
def main
    let t = add_jit(2,3)
    print("t = {t}\n")