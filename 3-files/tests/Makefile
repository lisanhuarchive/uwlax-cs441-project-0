#
# Sanhu Li
# Aug. 19, 2014
#
# Unique test of my own
# Note: There will be more added when assessing your final grade.
#       These tests are -not- comprehensive!
#

#
# Tests
#
mycheck: mycheck-echo mycheck-verify mycheck-calc

###############################################
# Tests - echo
###############################################
mycheck-echo: echo mycheck-echo-1 mycheck-echo-2 mycheck-echo-3


MYTEST_C_1=./echo mine test asdfasdf
MYDIFF_C_1=tests/echo-1-output.txt
mycheck-echo-1:
	@$(call fn-test-simple,"echo",1,$(MYTEST_C_1),$(MYDIFF_C_1))

MYTEST_C_2=./echo tests/test1.txt 
MYDIFF_C_2=tests/echo-2-output.txt
mycheck-echo-2:
	@$(call fn-test-simple,"echo",2,$(MYTEST_C_2),$(MYDIFF_C_2))

MYTEST_C_3=./echo tests/test2.txt mine tests/test3.txt
MYDIFF_C_3=tests/echo-3-output.txt
mycheck-echo-3:
	@$(call fn-test-simple,"echo",3,$(MYTEST_C_3),$(MYDIFF_C_3))



###############################################
# Tests - verify
###############################################
mycheck-verify: verify mycheck-verify-basic mycheck-verify-op
mycheck-verify-basic: mycheck-verify-1 mycheck-verify-2 mycheck-verify-3
mycheck-verify-op: mycheck-verify-4 mycheck-verify-5

MYTEST_VE_1=./verify tests/verify-1-input.txt
MYDIFF_VE_1=tests/verify-1-output.txt
mycheck-verify-1:
	@$(call fn-test-simple,"verify",1,$(MYTEST_VE_1),$(MYDIFF_VE_1))

MYTEST_VE_2=./verify tests/verify-2-input.txt
MYDIFF_VE_2=tests/verify-2-output.txt
mycheck-verify-2:
	@$(call fn-test-simple,"verify",2,$(MYTEST_VE_2),$(MYDIFF_VE_2))

MYTEST_VE_3=./verify tests/verify-2-input.txt tests/verify-1-input.txt
MYDIFF_VE_3=tests/verify-3-output.txt
mycheck-verify-3:
	@$(call fn-test-simple,"verify",3,$(MYTEST_VE_3),$(MYDIFF_VE_3))

MYTEST_VE_4=./verify tests/verify-4-input.txt
MYDIFF_VE_4=tests/verify-4-output.txt
mycheck-verify-4:
	@$(call fn-test-simple,"verify",4,$(MYTEST_VE_4),$(MYDIFF_VE_4))

MYTEST_VE_5=./verify tests/verify-5-input.txt
MYDIFF_VE_5=tests/verify-5-output.txt
mycheck-verify-5:
	@$(call fn-test-simple,"verify",5,$(MYTEST_VE_5),$(MYDIFF_VE_5))


###############################################
# Tests - calc
###############################################
mycheck-calc: calc mycheck-calc-basic mycheck-calc-op
mycheck-calc-basic: mycheck-calc-1 mycheck-calc-2 mycheck-calc-3
mycheck-calc-op: mycheck-calc-4 mycheck-calc-5

MYTEST_CALC_1=./calc tests/verify-1-input.txt
MYDIFF_CALC_1=tests/calc-1-output.txt
mycheck-calc-1:
	@$(call fn-test-simple,"calc",1,$(MYTEST_CALC_1),$(MYDIFF_CALC_1))

MYTEST_CALC_2=./calc tests/verify-2-input.txt
MYDIFF_CALC_2=tests/calc-2-output.txt
mycheck-calc-2:
	@$(call fn-test-simple,"calc",2,$(MYTEST_CALC_2),$(MYDIFF_CALC_2))

MYTEST_CALC_3=./calc tests/verify-2-input.txt tests/verify-1-input.txt
MYDIFF_CALC_3=tests/calc-3-output.txt
mycheck-calc-3:
	@$(call fn-test-simple,"calc",3,$(MYTEST_CALC_3),$(MYDIFF_CALC_3))

MYTEST_CALC_4=./calc tests/verify-4-input.txt
MYDIFF_CALC_4=tests/calc-4-output.txt
mycheck-calc-4:
	@$(call fn-test-simple,"calc",4,$(MYTEST_CALC_4),$(MYDIFF_CALC_4))

MYTEST_CALC_5=./calc tests/verify-5-input.txt
MYDIFF_CALC_5=tests/calc-5-output.txt
mycheck-calc-5:
	@$(call fn-test-simple,"calc",5,$(MYTEST_CALC_5),$(MYDIFF_CALC_5))
