#!/bin/sh

touch actual.txt
touch expected.txt

cd ..

test_suite () {
    ACTUAL=0
    EXPECTED=0

    echo $@ | ./evalexpr > tests/actual.txt
    ACTUAL=$(echo $?)
    ACTUAL=$((ACTUAL+0))

    echo $@ | bc > tests/expected.txt
    EXPECTED=$(echo $?)
    EXPECTED=$((EXPECTED+0))

    if [ "$ACTUAL" -ne "$EXPECTED" ]; then
        echo "Failed test: $@"
    fi

    diff 'tests/actual.txt' 'tests/expected.txt'
}

test_suite "1+1"
test_suite "5*(2^2+3)"
test_suite "((5*4)+2)"
