#!/bin/bash

# Test 1: Simple test of the command interpreter
in="abbabaq"
out="0,3,5;"
echo -n "Test 1 (Basic Input - abbabaq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 2: Only 'a' commands to add elements to the collection
in="aaaaaq"
out="0,1,2,3,4;"
echo -n "Test 2 (All 'a' commands - aaaaaq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 3: Only 'b' commands (no change to the collection)
in="bbbbq"
out=";"
echo -n "Test 3 (Only 'b' commands - bbbbq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 4: Using 'c' to remove items from the collection
in="aabcq"
out="0;"
echo -n "Test 4 (Using 'c' to remove elements - aabcq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 5: 'c' command with empty collection (should handle gracefully)
in="cccq"
out=";"
echo -n "Test 5 ('c' with empty collection - cccq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 6: Combination of 'a', 'b', and 'c', followed by invalid character
in="abacbcaX"
out="6;"
echo -n "Test 6 (Combination of commands - abacbcaX): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 7: Large input sequence with more 'a' commands to test dynamic collection
in=$(printf 'a%.0s' {1..100})"q"
expected_output=$(seq -s ',' 0 99)";"
echo -n "Test 7 (Large sequence of 'a' commands - 100 'a's): "
[[ $(./cmd_int <<< "$in") == "$expected_output" ]] && echo "PASSED" || echo "FAILED"

# Test 8: Random mix of commands with early termination
in="abcbabcababacabq"
out="7,9,13;"
echo -n "Test 8 (Random mix of commands - abcbabcababacabq): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 9: Ending the program without pressing 'q' (with an invalid character)
in="abacba1"
out="0,5;"
echo -n "Test 9 (End with invalid character - abacba1): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# Test 10: No commands at all (only 'q' to quit)
in="q"
out=";"
echo -n "Test 10 (Empty input - q): "
[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"
