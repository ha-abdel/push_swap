#!/bin/bash

make > /dev/null

total=$2
test_steps=0
for ((i=1; i <= $2; i++))
do
    percentage=$((i * 100 / total))
    bar=""
    for ((j=0; j<percentage/2; j++))
    do
        bar="${bar}#"
    done
    printf "\r[%-50s] %d%% (%d/%d)" "$bar" "$percentage" "$i" "$2"
    arg=$(shuf -i 0-$1 -n $1 | tr '\n' ' ')
    run=$(./push_swap $arg > tmp)
    steps=$(cat tmp | wc -l)
    result=$(cat tmp | ./checker_linux $arg)
    #my_result=$(cat tmp | ./checker $arg)
    if [ $steps -gt $test_steps ]; then
        nb=$i
        test_arg=$arg
        test_steps=$steps
        test_result=$result
        #test_checker=$my_result
    fi
    if [ $result != "OK" ]; then #|| [ $result != $my_result ]; then
        echo ""
        echo "Test <$i>: [$arg]"
        echo "Instructions: $steps"
        echo "Checker output: $result"
        #echo "My Checker output: $my_result"
        break
    fi
done

echo ""
printf "\n        << Max Instructions test >>\n"
echo "Test <$nb> : [$test_arg]"
echo ""
echo "Instructions: $test_steps"
echo "Checker output: $test_result"
#echo "My checker output: $test_checker"

rm -f tmp