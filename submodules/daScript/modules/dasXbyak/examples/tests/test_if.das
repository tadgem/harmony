options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

var last_value = 0

def printreg(t:int)
    last_value = t

[jit_x86_64]
def test_ite(a:int)
    if a==13
        printreg(13)
    else
        printreg(a+100000)

[jit_x86_64]
def test_it(a:int)
    if a==13
        printreg(13)

[test]
def test_if(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_it)
        last_value=0;   test_it(13);    t |> equal(last_value,13)
        last_value=0;   test_it(1);     t |> equal(last_value,0)
[test]
def test_if_else(t: T?)
    test_jit_levels <|
        verify_jit(t, @@test_ite)
        last_value=0;   test_ite(13);   t |> equal(last_value,13)
        last_value=0;   test_ite(1);    t |> equal(last_value,100001)

