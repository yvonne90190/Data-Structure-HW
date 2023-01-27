# 比較insertion sort, merge sort, 三種randomized quick sort (Lomuto Partition, Hoare Partition, 與3-Way Partition)與Counting sort

## 比較方法
計算上述演算法在input array 大小為2^k時（k = 15, 16, …, 30）的平均執行時間。針對每個input array 大小，分別產生10 個input array，最後取10 次執行時間的平均。若執行時間超過1小時或無法測試到n=2^30，請估計執行時間，並解釋你的估計方法。

## Input array 產生方法
陣列的每個數字都從1~1000 中的正整數中隨機選擇，且每個數字被選到的機率都相同（0.001）。

## Report 
1. 一個折線圖（包含6 條折線）。折線圖的x 軸為陣列大小，y 軸為對應的平均執行時間。每個排序方法用一條折線表示其執行時間。請解釋你的實驗結果。
2. 每個Sorting 演算法的程式碼來源。


## Execution
To complie files :
```
make
```
To remove executable files :
```
make clean 
```
To run experiments :
```
./run.sh 
```
experiment raw data results are stored in **.csv** files  
