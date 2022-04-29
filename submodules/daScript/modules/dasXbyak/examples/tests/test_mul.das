
options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def imul_jit ( a, b: int )
    return a * b

[jit_x86_64]
def imul_equ_jit ( a, b: int )
    var c = a
    c *= b
    return c

[test]
def test_imul(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@imul_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                t |> strictEqual( imul_jit(i,j), i*j)

[test]
def test_imul_equ(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@imul_equ_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                t |> strictEqual( imul_equ_jit(i,j), i*j)

[jit_x86_64]
def imul3_jit ( a, b, c: int )
    return a * b * c

[jit_x86_64]
def imul3_local_jit ( a, b, c: int )
    // this one generates lea for a 3-way imul
    let A = a
    let B = b
    let C = c
    return A * B * C

[test]
def test_imul3(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@imul3_jit)
        verify_jit(t, @@imul3_local_jit)
        for i in range(-10,10)
            for j in range(-10,10)
                for k in range(-10,10)
                    t |> strictEqual( imul3_jit(i,j,k), i*j*k)
                    t |> strictEqual( imul3_local_jit(i,j,k), i*j*k)

[export]
def main
    let t = imul3_local_jit(-10,-9,-10)
    print("t = {t}\n")