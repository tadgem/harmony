// options log=true, print_var_access=true, print_ref=true

require testProfile

options rtti
require jit/jit_x86_64
require jit/jit_x86_64_test

[jit_x86_64(no_exceptions)]
def isprime_jit(n:int)
    for i in range(2, n)
        if (n % i == 0)
            return false
    return true

[jit_x86_64(no_exceptions)]
def primes_jit(n:int)
    var count = 0
    for i in range(2, n+1)
        if isprime_jit(i)
            ++count
    return count

def isprime(n)
    for i in range(2, n)
        if (n % i == 0)
            return false
    return true

[sideeffects]
def primes(n)
    var count = 0
    for i in range(2, n+1)
        if isprime(i)
            ++count
    return count

[sideeffects]
def primesI(n:int)
    var count = 0
    for i in range(2, n+1)
		count ++
		for j in range(2,i)
			if i % j == 0
				count --
				break
    return count

[jit_x86_64(no_exceptions)]
def primesI_jit(n:int)
    var count = 0
    for i in range(2, n+1)
		count ++
		for j in range(2,i)
			if i % j == 0
				count --
				break
    return count

[test]
def test_primes(t: T?)
    test_jit_levels(t.verbose) <|
        verify_jit(t,@@primes_jit)
        verify_jit(t,@@primesI_jit)
        for vv in range(1,14)
            let v = vv * 100
            let R = testProfile::testPrimes(v)
            let pj = primes_jit(v)
            t |> equal( R, pj)
            let pji  = primesI_jit(v)
            t |> equal( R, pji)

[export]
def main()
	var f3 = 0
    profile(20,"primes loop C++") <|
        f3 = testProfile::testPrimes(14000)
	assert(f3==1652)
    test_jit_levels(false, true) <|
        var f1j = 0
        profile(20,"primes loop - jit") <|
            f1j = primes_jit(14000)
        assert(f1j==1652)
        var f2j = 0
        profile(20,"primes loop, inline - jit") <|
            f2j = primesI_jit(14000)
        assert(f2j==1652)

