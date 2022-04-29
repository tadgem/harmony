options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64]
def inc_jit ( a : int )
    var b = a
    ++ b
    return b

[jit_x86_64]
def dec_jit ( a : int )
    var b = a
    -- b
    return b

[jit_x86_64]
def post_inc_jit ( a : int )
    var b = a
    b ++
    return b

[jit_x86_64]
def post_dec_jit ( a : int )
    var b = a
    b --
    return b

[jit_x86_64]
def r_inc_jit ( a : int )
    var b = a
    return ++b

[jit_x86_64]
def r_dec_jit ( a : int )
    var b = a
    return --b

[jit_x86_64]
def r_post_inc_jit ( a : int )
    var b = a
    return b++

[jit_x86_64]
def r_post_dec_jit ( a : int )
    var b = a
    return b--

[test]
def test_inc_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@inc_jit)
        t |> equal(inc_jit(10),11)

[test]
def test_dec_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@dec_jit)
        t |> equal(dec_jit(10),9)

[test]
def test_post_inc_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@post_inc_jit)
        t |> equal(post_inc_jit(10),11)

[test]
def test_post_dec_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@post_dec_jit)
        t |> equal(post_dec_jit(10),9)

[test]
def test_r_inc_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@r_inc_jit)
        t |> equal(r_inc_jit(10),11)

[test]
def test_r_dec_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@r_dec_jit)
        t |> equal(r_dec_jit(10),9)

[test]
def test_r_post_inc_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@r_post_inc_jit)
        t |> equal(r_post_inc_jit(10),10)

[test]
def test_r_post_dec_jit(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t, @@r_post_dec_jit)
        t |> equal(r_post_dec_jit(10),10)
