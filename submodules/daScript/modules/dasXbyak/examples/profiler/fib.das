// options log=true, print_var_access=true, print_ref=true

require testProfile

options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[sideeffects]
def fibR(n:int)
    if (n < 2)
        return n
    return fibR(n - 1) + fibR(n - 2)

[jit_x86_64]
def fibR_jit(n:int)
    if (n < 2)
        return n
    return fibR_jit(n - 1) + fibR_jit(n - 2)

[sideeffects]
def fibI(n:int)
    var last = 0
    var cur = 1
    for i in range(n-1)
        let tmp = cur
        cur += last
        last = tmp
    return cur

[jit_x86_64]
def fibI_jit(n:int)
    var last = 0
    var cur = 1
    for i in range(n-1)
        let tmp = cur
        cur += last
        last = tmp
    return cur

[test]
def test_fibI_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t,@@fibI_jit)
        let f1_j = fibI_jit(6511134)
        t |> equal( f1_j, 1781508648)

[test]
def test_fibR_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t,@@fibR_jit)
        var f3_j = fibR_jit(31)
        t |> equal( f3_j, 1346269)

[export]
def main()
    var f4 = 0
    profile(20,"fibbonacci loop c++") <|
        f4 = testProfile::testFibI(6511134)
    assert(f4==1781508648)
    var f5 = 0
    profile(20,"fibbonacci recursive c++") <|
        f5 = testProfile::testFibR(31)
    assert(f5==1346269)
    test_jit_levels(false, true) <|
        var f1_j = 0
        profile(20,"fibbonacci loop - jit") <|
            f1_j = fibI_jit(6511134)
        assert(f1_j==1781508648)
        var f3_j = 0
        profile(20,"fibbonacci recursive - jit") <|
            f3_j = fibR_jit(31)
        assert(f3_j==1346269)

