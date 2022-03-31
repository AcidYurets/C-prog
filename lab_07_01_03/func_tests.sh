echo "positive tests:"
for i in 1 2 3 4 5 6 7 8 9 10 11 12
do
    if [[ $i -lt 10 ]]
    then
        args=$(cat func_tests/pos_0${i}_args.txt)
        string=$(cat func_tests/pos_0${i}_out.txt)
    else
        args=$(cat func_tests/pos_${i}_args.txt)
        string=$(cat func_tests/pos_${i}_out.txt)
    fi
    ./app.exe $args  
    if [[ "$(cat pos_out.txt)" = "$string" ]]
    then
        echo $i - OK
    else
        echo $i - BAD
    fi
done
echo "negative tests:"
for i in 1 2 3 4 5 6 7 8
do
    args=$(cat func_tests/neg_0${i}_args.txt)
    string=$(cat func_tests/neg_0${i}_out.txt)
    ./app.exe $args > neg_out.txt
    if [[ "$(cat neg_out.txt)" = "$string" ]]
    then
        echo $i - OK
    else
        echo $i - BAD
    fi
done
rm neg_out.txt
rm pos_out.txt