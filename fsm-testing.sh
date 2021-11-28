#! /bin/bash

IFS=$'\n'
file=$1
lines=$(cat $file)

mut_killed=0
mut_survived=0

i=0
for m in $(mut-list -s fsm); do	
	mut_arr[$i]=0
	((i++))
done

for line in $lines; do
	input_seq=""
	expected_out=""

	for i in $(seq 1 ${#line}); do
		cur=${line:i-1:1}
		next=${line:i:1}

		if [[ ( $cur = "0" || $cur = "1" ) && $next = "/" ]]; then
			input_seq+=$cur
		elif [[ ($cur = "0" || $cur = "1") && ( $next = " " || $i = ${#line} ) ]]; then
			expected_out+=$cur
		elif [[ $cur = "/" && ( $next = "0" || $next = "1" ) ]]; then
			continue
		elif [[ $cur = " " && ( $next = "0" || $next = "1" || $i = ${#line} ) ]]; then
			continue
		else
			echo "Wrong input"
			exit 1
		fi
	done;

	program_out=$(./fsm $input_seq)

	if [ $program_out != $expected_out ]; then
		echo "Test failed. Test seq: $line, expected output:
			$expected_out, returned output: $program_out"
	#else
		#echo "Test passed"
	fi

	i=0
	for m in $(mut-list -s fsm); do		
		mut_out=$(mut-run -s "$m" ./fsm $input_seq)		

		if [ $mut_out != $expected_out ]; then
			mut_arr[$i]=1
			((mut_killed++))
		else 
			((mut_survived++))
		fi

		((i++))
	done
	
	echo "test seq.: $line"
	echo "mutants killed: $mut_killed"
	echo "mutants survived: $mut_survived"	
	echo ""
	
	mut_killed=0
	mut_survived=0
done

i=0

for elem in "${mut_arr[@]}"; do
    if [ mut_arr[$i] = 0 ]; then
		echo "Mutant $i survived" 
	fi

	((i++))
done
