#
# Josh Hursey
# Aug. 15, 2014
#
# Given set of correctness tests
# Note: There will be more added when assessing your final grade.
#       These tests are -not- comprehensive!
#

#
# Tests
#
CHECK_OUTPUT=~/tmp/check-tmp.txt
check: check-echo check-verify check-calc


#
# Some helper functions
#
fn-banner = echo "\#-----------------------------------------------------"
fn-display-cmd-simple = \
	$(call fn-banner) ; \
	echo "        shell$$" $1

fn-display-cmd-input = \
	$(call fn-banner) ; \
	echo "        shell$$" $1 " < " $2

fn-run-cmd-simple = \
	 $1 > $(CHECK_OUTPUT) || \
	(cat $(CHECK_OUTPUT) && \
	 echo "\#----------------" && \
	 false)
fn-run-cmd-input = \
	$1 < $2 > $(CHECK_OUTPUT) || \
	(cat $(CHECK_OUTPUT) && \
	 echo "\#----------------" && \
	 false)

fn-diff-cmd-simple = \
	diff -w $(CHECK_OUTPUT) $3 &&  \
	echo "Passed: $1: $2 " || \
	(echo "Failed: $1: $2 " && \
	 echo "    \"<\" line prefix shows your output" && \
	 echo "    \">\" line prefix shows the expected output from $3)")
fn-diff-cmd-input = \
	diff -w $(CHECK_OUTPUT) $3 && \
	echo "Passed: $1: $2 " || \
	(echo "Failed: $1: $2 " && \
	 echo "    \"<\" line prefix shows your output" && \
	 echo "    \">\" line prefix shows the expected output from $3)")

# $ 1 = Binary name
# $ 2 = Test number
# $ 3 = Test Command
# $ 4 = Diff file
fn-test-simple = \
	$(call fn-display-cmd-simple,$3) ; \
	$(call fn-run-cmd-simple,$3) ; \
	$(call fn-diff-cmd-simple,$1,"Test $2",$4) ; \
	$(RM) $(CHECK_OUTPUT) ; \
	echo ""

# $ 1 = Binary name
# $ 2 = Test number
# $ 3 = Test Command
# $ 4 = Diff file
# $ 5 = input file
fn-test-input = \
	$(call fn-display-cmd-input,$3,$5) ; \
	$(call fn-run-cmd-input,$3,$5) ; \
	$(call fn-diff-cmd-input,$1,"Test $2",$4) ; \
	$(RM) $(CHECK_OUTPUT) ; \
	echo ""




###############################################
# Tests - echo
###############################################
check-echo: echo check-echo-1 check-echo-2 check-echo-3


TEST_C_1=./echo fake
DIFF_C_1=given-tests/echo-1-output.txt
check-echo-1:
	@$(call fn-test-simple,"echo",1,$(TEST_C_1),$(DIFF_C_1))

TEST_C_2=./echo given-tests/test1.txt 
DIFF_C_2=given-tests/echo-2-output.txt
check-echo-2:
	@$(call fn-test-simple,"echo",2,$(TEST_C_2),$(DIFF_C_2))

TEST_C_3=./echo given-tests/test2.txt fake given-tests/test3.txt
DIFF_C_3=given-tests/echo-3-output.txt
check-echo-3:
	@$(call fn-test-simple,"echo",3,$(TEST_C_3),$(DIFF_C_3))



###############################################
# Tests - verify
###############################################
check-verify: verify check-verify-basic check-verify-op
check-verify-basic: check-verify-1 check-verify-2 check-verify-3
check-verify-op: check-verify-4 check-verify-5

TEST_VE_1=./verify given-tests/verify-1-input.txt
DIFF_VE_1=given-tests/verify-1-output.txt
check-verify-1:
	@$(call fn-test-simple,"verify",1,$(TEST_VE_1),$(DIFF_VE_1))

TEST_VE_2=./verify given-tests/verify-2-input.txt
DIFF_VE_2=given-tests/verify-2-output.txt
check-verify-2:
	@$(call fn-test-simple,"verify",2,$(TEST_VE_2),$(DIFF_VE_2))

TEST_VE_3=./verify given-tests/verify-2-input.txt given-tests/verify-1-input.txt
DIFF_VE_3=given-tests/verify-3-output.txt
check-verify-3:
	@$(call fn-test-simple,"verify",3,$(TEST_VE_3),$(DIFF_VE_3))

TEST_VE_4=./verify given-tests/verify-4-input.txt
DIFF_VE_4=given-tests/verify-4-output.txt
check-verify-4:
	@$(call fn-test-simple,"verify",4,$(TEST_VE_4),$(DIFF_VE_4))

TEST_VE_5=./verify given-tests/verify-5-input.txt
DIFF_VE_5=given-tests/verify-5-output.txt
check-verify-5:
	@$(call fn-test-simple,"verify",5,$(TEST_VE_5),$(DIFF_VE_5))


###############################################
# Tests - calc
###############################################
check-calc: calc check-calc-basic check-calc-op
check-calc-basic: check-calc-1 check-calc-2 check-calc-3
check-calc-op: check-calc-4 check-calc-5

TEST_CALC_1=./calc given-tests/verify-1-input.txt
DIFF_CALC_1=given-tests/calc-1-output.txt
check-calc-1:
	@$(call fn-test-simple,"calc",1,$(TEST_CALC_1),$(DIFF_CALC_1))

TEST_CALC_2=./calc given-tests/verify-2-input.txt
DIFF_CALC_2=given-tests/calc-2-output.txt
check-calc-2:
	@$(call fn-test-simple,"calc",2,$(TEST_CALC_2),$(DIFF_CALC_2))

TEST_CALC_3=./calc given-tests/verify-2-input.txt given-tests/verify-1-input.txt
DIFF_CALC_3=given-tests/calc-3-output.txt
check-calc-3:
	@$(call fn-test-simple,"calc",3,$(TEST_CALC_3),$(DIFF_CALC_3))

TEST_CALC_4=./calc given-tests/verify-4-input.txt
DIFF_CALC_4=given-tests/calc-4-output.txt
check-calc-4:
	@$(call fn-test-simple,"calc",4,$(TEST_CALC_4),$(DIFF_CALC_4))

TEST_CALC_5=./calc given-tests/verify-5-input.txt
DIFF_CALC_5=given-tests/calc-5-output.txt
check-calc-5:
	@$(call fn-test-simple,"calc",5,$(TEST_CALC_5),$(DIFF_CALC_5))
