
options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def cmp_less ( a, b: int ) : bool
    return a < b

[jit_x86_64]
def cmp_less_equ ( a, b: int ) : bool
    return a <= b

[jit_x86_64]
def cmp_equ ( a, b: int ) : bool
    return a == b

[jit_x86_64]
def cmp_not_equ ( a, b: int ) : bool
    return a != b

[jit_x86_64]
def cmp_greater ( a, b: int ) : bool
    return a > b

[jit_x86_64]
def cmp_greater_equ ( a, b: int ) : bool
    return a >= b

[test]
def test_cmp(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@cmp_less)
        verify_jit(t, @@cmp_less_equ)
        verify_jit(t, @@cmp_equ)
        verify_jit(t, @@cmp_not_equ)
        verify_jit(t, @@cmp_greater)
        verify_jit(t, @@cmp_greater_equ)
        for i in range(-10,10)
            for j in range(-10,10)
                t |> strictEqual(cmp_less(i,j),i<j)
                t |> strictEqual(cmp_less_equ(i,j),i<=j)
                t |> strictEqual(cmp_equ(i,j),i==j)
                t |> strictEqual(cmp_not_equ(i,j),i!=j)
                t |> strictEqual(cmp_greater(i,j),i>j)
                t |> strictEqual(cmp_greater_equ(i,j),i>=j)

[jit_x86_64]
def cond_less ( a, b, c, d: int ) : int
    return a < b ? c : d

[jit_x86_64]
def cond_less_equ ( a, b, c, d: int ) : int
    return a <= b ? c : d

[jit_x86_64]
def cond_equ ( a, b, c, d: int ) : int
    return a == b ? c : d

[jit_x86_64]
def cond_not_equ ( a, b, c, d: int ) : int
    return a != b ? c : d

[jit_x86_64]
def cond_greater ( a, b, c, d: int ) : int
    return a > b ? c : d

[jit_x86_64]
def cond_greater_equ ( a, b, c, d: int ) : int
    return a >= b ? c : d

[test]
def test_cond(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@cond_less)
        verify_jit(t, @@cond_less_equ)
        verify_jit(t, @@cond_equ)
        verify_jit(t, @@cond_not_equ)
        verify_jit(t, @@cond_greater)
        verify_jit(t, @@cond_greater_equ)
        for i in range(-10,10)
            for j in range(-10,10)
                t |> strictEqual(cond_less(i,j,12,13),i<j ? 12 : 13)
                t |> strictEqual(cond_less_equ(i,j,12,13),i<=j ? 12 : 13)
                t |> strictEqual(cond_equ(i,j,12,13),i==j ? 12 : 13)
                t |> strictEqual(cond_not_equ(i,j,12,13),i!=j ? 12 : 13)
                t |> strictEqual(cond_greater(i,j,12,13),i>j ? 12 : 13)
                t |> strictEqual(cond_greater_equ(i,j,12,13),i>=j ? 12 : 13)

var g_GOO = 0

def set_goo(value:int)
    g_GOO = value

[jit_x86_64]
def if_less ( a, b: int )
    if a < b
        set_goo(13)

[jit_x86_64]
def if_less_equ ( a, b: int )
    if a <= b
        set_goo(13)

[jit_x86_64]
def if_equ ( a, b: int )
    if a == b
        set_goo(13)

[jit_x86_64]
def if_not_equ ( a, b: int )
    if a != b
        set_goo(13)

[jit_x86_64]
def if_greater ( a, b: int )
    if a > b
        set_goo(13)

[jit_x86_64]
def if_greater_equ ( a, b: int )
    if a >= b
        set_goo(13)

[test]
def test_if(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@if_less)
        verify_jit(t, @@if_less_equ)
        verify_jit(t, @@if_equ)
        verify_jit(t, @@if_not_equ)
        verify_jit(t, @@if_greater)
        verify_jit(t, @@if_greater_equ)
        for i in range(-10,10)
            for j in range(-10,10)
                g_GOO=0; if_less(i,j);        t |> strictEqual(g_GOO,i<j ? 13 : 0)
                g_GOO=0; if_less_equ(i,j);    t |> strictEqual(g_GOO,i<=j ? 13 : 0)
                g_GOO=0; if_equ(i,j);         t |> strictEqual(g_GOO,i==j ? 13 : 0)
                g_GOO=0; if_not_equ(i,j);     t |> strictEqual(g_GOO,i!=j ? 13 : 0)
                g_GOO=0; if_greater(i,j);     t |> strictEqual(g_GOO,i>j ? 13 : 0)
                g_GOO=0; if_greater_equ(i,j); t |> strictEqual(g_GOO,i>=j ? 13 : 0)

[jit_x86_64]
def if_else_less ( a, b: int )
    if a < b
        set_goo(13)
    else
        set_goo(14)

[jit_x86_64]
def if_else_less_equ ( a, b: int )
    if a <= b
        set_goo(13)
    else
        set_goo(14)

[jit_x86_64]
def if_else_equ ( a, b: int )
    if a == b
        set_goo(13)
    else
        set_goo(14)

[jit_x86_64]
def if_else_not_equ ( a, b: int )
    if a != b
        set_goo(13)
    else
        set_goo(14)

[jit_x86_64]
def if_else_greater ( a, b: int )
    if a > b
        set_goo(13)
    else
        set_goo(14)

[jit_x86_64]
def if_else_greater_equ ( a, b: int )
    if a >= b
        set_goo(13)
    else
        set_goo(14)

[test]
def test_if_else(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@if_else_less)
        verify_jit(t, @@if_else_less_equ)
        verify_jit(t, @@if_else_equ)
        verify_jit(t, @@if_else_not_equ)
        verify_jit(t, @@if_else_greater)
        verify_jit(t, @@if_else_greater_equ)
        for i in range(-10,10)
            for j in range(-10,10)
                g_GOO=0; if_else_less(i,j);        t |> strictEqual(g_GOO,i<j ? 13 : 14)
                g_GOO=0; if_else_less_equ(i,j);    t |> strictEqual(g_GOO,i<=j ? 13 : 14)
                g_GOO=0; if_else_equ(i,j);         t |> strictEqual(g_GOO,i==j ? 13 : 14)
                g_GOO=0; if_else_not_equ(i,j);     t |> strictEqual(g_GOO,i!=j ? 13 : 14)
                g_GOO=0; if_else_greater(i,j);     t |> strictEqual(g_GOO,i>j ? 13 : 14)
                g_GOO=0; if_else_greater_equ(i,j); t |> strictEqual(g_GOO,i>=j ? 13 : 14)

[export]
def main
    pass
