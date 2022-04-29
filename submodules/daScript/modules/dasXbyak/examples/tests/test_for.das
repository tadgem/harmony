options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

var seq : array<int>

def verify_seq(var arr:array<int>)
    print("{seq} vs reference {arr}\n\n")
    if length(seq)!=length(arr)
        panic("sequence length mismatch")
    for T,S in arr,seq
        if T != S
            panic("sequence mismatch {T} vs {S}\n")
    delete seq
    delete arr

def verify_seq(t : T?; var arr:array<int>)
    t |> strictEqual(length(seq),length(arr))
    for T,S in arr,seq
        t |> strictEqual(T,S)
    delete seq
    delete arr

def printreg(t:int)
    seq |> push(t)

[jit_x86_64]
def test_continue(a,b:int)
    for t in range(a,b)
        if t % 2 == 0
            continue
        printreg(t)

[jit_x86_64]
def test_range(a,b:int)
    for t in range(a,b)
        printreg(t)

[jit_x86_64]
def test_break(a,b,c:int)
    for t in range(a,b)
        printreg(t)
        if t==c
            break

[jit_x86_64]
def test_range_1a_v(a:int)
    for t in range(a)
        printreg(t)

[jit_x86_64]
def test_range_1a_0(a:int)
    var j = 0
    for t in range(a)
        printreg(j)
        j ++

[jit_x86_64]
def test_range_2a_v(a,b:int)
    for t in range(a,b)
        printreg(t)

[jit_x86_64]
def test_range_2a_0(a,b:int)
    var j = a
    for t in range(a,b)
        printreg(j)
        j ++

[test]
def test_for_range_1arg_unused_value(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_range_1a_v)
        test_range_1a_v(5);     verify_seq(t,[{for t in range(0,5); t}])
[test]
def test_for_range_1arg(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_range_1a_0)
        test_range_1a_0(5);     verify_seq(t,[{for t in range(0,5); t}])

[test]
def test_for_range_2arg(t: T?)
    // range2
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_range_2a_v)
        test_range_2a_v(2,5);    verify_seq(t,[{for t in range(2,5); t}])
        test_range_2a_v(5,5);    verify_seq(t,[{for t in range(5,5); t}])
        test_range_2a_v(50,5);   verify_seq(t,[{for t in range(50,5); t}])

[test]
def test_for_range_2arg_unused_value(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_range_2a_0)
        test_range_2a_0(2,5);    verify_seq(t,[{for t in range(2,5); t}])
        test_range_2a_0(5,5);    verify_seq(t,[{for t in range(5,5); t}])
        test_range_2a_0(50,5);   verify_seq(t,[{for t in range(50,5); t}])

[test]
def test_for_range_any(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_range)
        test_range(0,5);        verify_seq(t,[{for t in range(0,5); t}])
        test_range(2,5);        verify_seq(t,[{for t in range(2,5); t}])
        test_range(5,5);        verify_seq(t,[{for t in range(5,5); t}])
        test_range(50,5);       verify_seq(t,[{for t in range(50,5); t}])
        test_range(-2,5);       verify_seq(t,[{for t in range(-2,5); t}])
        test_range(-2,-3);      verify_seq(t,[{for t in range(-2,-3); t}])
        test_range(-3,-2);      verify_seq(t,[{for t in range(-3,-2); t}])

[test]
def test_for_break(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_break)
        test_break(0,10,4);    verify_seq(t,[{for t in range(0,10); t; where t<=4}])

[test]
def test_for_continue(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@test_continue)
        test_continue(0,10);    verify_seq(t,[{for t in range(0,10); t; where t % 2 != 0}])

[export]
def main
    test_jit_levels(false, true) <|
        test_continue(0,10);    verify_seq([{for t in range(0,10); t; where t % 2 != 0}])
