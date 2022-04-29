module jit_x86_64_test

require jit/jit_x86_64
require dastest/testing_boost public

[generic]
def test_jit_levels ( blk:block )
    test_jit_levels(false, blk)

[generic]
def test_jit_levels ( verbose:bool; blk:block )
    test_jit_levels(verbose, false, blk)

[generic]
def test_jit_levels ( verbose, pverbose:bool; blk:block )
    for opt_level in range(-1,JIT_MAX_POSSIBLE_OPT_LEVEL+1)
        if verbose || pverbose
            print("--------------------------\n")
            if opt_level != -1
                print("JIT_OPTLEVEL = {opt_level}\n")
            else
                print("INTERPRETED\n")
            print("--------------------------\n")
        JIT_VERBOSE = verbose
        JIT_DISASM = false
        JIT_MAX_OPT_LEVEL = opt_level
        __::all`things`jit()
        invoke(blk)

def verify_jit(t, func)
    if JIT_MAX_OPT_LEVEL!=-1 && !is_jit_function(func)
        t->error("{func} - did not jit")

