for x in 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 # additional edge number
do 
    for z in 100 # sample pairs num
    do
        for y in 1 # additional edge weight
        do
            python3 main.py 1000 $x $z $y RawResult.csv
        done
    done
done

for x in 100 # additional edge number
do 
    for z in 100 # sample pairs num
    do
        for y in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 # additional edge weight
        do
            python3 main.py 1000 $x $z $y RawResult.csv
        done
    done
done

for x in 100 # additional edge number
do 
    for z in 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 # sample pairs num
    do
        for y in 1 # additional edge weight
        do
            python3 main.py 1000 $x $z $y RawResult.csv
        done
    done
done