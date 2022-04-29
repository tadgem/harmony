
options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def mod_jit ( a, b: int )
    return a % b

[jit_x86_64]
def div_jit ( a, b: int )
    return a / b

[test]
def div_and_mod(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@div_jit)
        verify_jit(t, @@mod_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                if j != 0
                    t |> strictEqual( div_jit(i,j), i/j)
                    t |> strictEqual( mod_jit(i,j), i%j)


[jit_x86_64]
def mod_equ_jit ( a, b: int )
    var c = a
    c %= b
    return c

[jit_x86_64]
def div_equ_jit ( a, b: int )
    var c = a
    c /= b
    return c

[test]
def div_and_mod_equ(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@div_equ_jit)
        verify_jit(t, @@mod_equ_jit)
        for i in range(-100,100)
            for j in range(-100,100)
                if j != 0
                    t |> strictEqual( div_equ_jit(i,j), i/j)
                    t |> strictEqual( mod_equ_jit(i,j), i%j)

[test]
def div_by_zero(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@div_jit)
        verify_jit(t, @@mod_jit)
        var div0 = false
        try
            if div_jit(30,0)==0
                t->error("no exception, expecting div by zero")
        recover
            div0 = true
        if !div0
            t->error("expecting division by zero")
        div0 = false
        try
            if mod_jit(30,0)==0
                t->error("no exception, expecting div by zero")
        recover
            div0 = true
        if !div0
            t->error("expecting division by zero")

[export]
def main
    test_jit_levels(false,true) <|
        let t = div_equ_jit(30,7)
        print("t = {div_equ_jit(30,7)} t = {mod_equ_jit(30,7)}\n")
