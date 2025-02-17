#!/bin/bash
testNum=0
longer_num=0
size=1
sing=0
ran_sign=0
while true; do
    clear
    num=$RANDOM
    ran_sign=$RANDOM
    echo "longer moves = $longer_num"
    echo -n "$num " > "$size".txt
    
    while [[ $(wc -w < "$size".txt) -lt "$size" ]]; do
        ((sing++))
        num=$RANDOM
        ran_sign=$RANDOM        
        if ! grep -q "$num" "$size".txt; then
            if (( ran_sign % sing == 0 )); then
                echo -n "-" >> "$size".txt
            fi
            echo -n "$num " >> "$size".txt
        fi
        if (( sing == 7 )); then
            sing=0
        fi
    done
    echo >> "$size".txt

    mv=""
    moves=0
    checker=ok
    while IFS= read -r nums;
    do
        ((testNum++))
        echo -n $testNum " try sort "
        echo $nums | wc -w | awk '{print $0 " Number"}'
        echo -e "\e[32m===> $nums <===\e[0m"
        mv=$(./push_swap $nums )
        moves=$(echo $mv | sed 's/ /\n/g' | wc -l)
        echo -n "$moves " | awk '{print $0 " move"}'
        checker=$(./push_swap $nums | ./checker_linux $nums)
        echo "$checker"
        echo -e "============================"
    done < "$size".txt
    if [[ $checker != "OK" ]]; then
        break
    fi
    if (( $moves >= 5500 )); then
        break 
    fi
    if (( moves > longer_num )); then
        longer_num=$moves
        echo $longer_num > longer_num.txt
        echo $(cat "$size".txt) >> longer_num.txt
    fi    
    if (( size == 1 )); then
        size=2
    elif (( size == 2 )); then
        size=5
    elif (( size == 5 )); then
        size=10
    elif (( size == 10 )); then
        size=20
    elif (( size == 20 )); then
        size=50
    elif (( size == 50 )); then
        size=100
    elif (( size == 100 )); then
        if (( $moves >= 700 )); then
            break
        fi
        size=500
    elif (( size == 500 )); then
        size=1
    fi
done