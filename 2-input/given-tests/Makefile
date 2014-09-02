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
check: check-cmdline check-stdinput check-verify


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
# Tests - cmdline
###############################################
check-cmdline: cmdline check-cmdline-1 check-cmdline-2 check-cmdline-3


TEST_C_1=./cmdline
DIFF_C_1=given-tests/cmdline-1-output.txt
check-cmdline-1:
	@$(call fn-test-simple,"cmdline",1,$(TEST_C_1),$(DIFF_C_1))

TEST_C_2=./cmdline 1 23 4567
DIFF_C_2=given-tests/cmdline-2-output.txt
check-cmdline-2:
	@$(call fn-test-simple,"cmdline",2,$(TEST_C_2),$(DIFF_C_2))

TEST_C_3=./cmdline 1 2 3 4567 8907 asdf 08asdf 
DIFF_C_3=given-tests/cmdline-3-output.txt
check-cmdline-3:
	@$(call fn-test-simple,"cmdline",3,$(TEST_C_3),$(DIFF_C_3))



###############################################
# Tests - stdinput
###############################################
check-stdinput: stdinput check-stdinput-1 check-stdinput-2 check-stdinput-3


TEST_S_1=./stdinput
INPUT_S_1=given-tests/stdinput-1-input.txt
DIFF_S_1=given-tests/stdinput-1-output.txt
check-stdinput-1:
	@$(call fn-test-input,"stdinput",1,$(TEST_S_1),$(DIFF_S_1),$(INPUT_S_1))

TEST_S_2=./stdinput
INPUT_S_2=given-tests/stdinput-2-input.txt
DIFF_S_2=given-tests/stdinput-2-output.txt
check-stdinput-2:
	@$(call fn-test-input,"stdinput",2,$(TEST_S_2),$(DIFF_S_2),$(INPUT_S_2))

TEST_S_3=./stdinput
INPUT_S_3=given-tests/stdinput-3-input.txt
DIFF_S_3=given-tests/stdinput-3-output.txt
check-stdinput-3:
	@$(call fn-test-input,"stdinput",3,$(TEST_S_3),$(DIFF_S_3),$(INPUT_S_3))


###############################################
# Tests - verify
###############################################
check-verify: verify check-verify-cli check-verify-stdin
check-verify-cli: verify check-verify-1 check-verify-2 check-verify-3
check-verify-stdin: verify check-verify-4


TEST_VE_1=./verify 123 ++999 +456 --777 -789 8- 66+ 2+ 2-
DIFF_VE_1=given-tests/verify-1-output.txt
check-verify-1:
	@$(call fn-test-simple,"verify",1,$(TEST_VE_1),$(DIFF_VE_1))

TEST_VE_2=./verify 123. ++999.99 +456.3 --777.123 -789.4 8-.30 +.876 66+.3 .5 .5.4 -+0.2
DIFF_VE_2=given-tests/verify-2-output.txt
check-verify-2:
	@$(call fn-test-simple,"verify",2,$(TEST_VE_2),$(DIFF_VE_2))

TEST_VE_3=./verify 123 -123.4 +f 123f -fd -123df -1- 1000 0.+2
DIFF_VE_3=given-tests/verify-3-output.txt
check-verify-3:
	@$(call fn-test-simple,"verify",3,$(TEST_VE_3),$(DIFF_VE_3))


TEST_VE_4=./verify
INPUT_VE_4=given-tests/verify-4-input.txt
DIFF_VE_4=given-tests/verify-4-output.txt
check-verify-4:
	@$(call fn-test-input,"verify",4,$(TEST_VE_4),$(DIFF_VE_4),$(INPUT_VE_4))
