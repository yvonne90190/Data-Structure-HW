# Compare Dynamic Array and Linked List

## Description
1. 測量上述資料結構新增n=2^k 個隨機數所需時間，其中k = 15, 16, 17, …, 30。
   若計算資源允許，可測試更大的n值。
   若無法測試到n=2^30，請預測執行時間並解釋你的預測。
2. 在新增n個隨機數後，計算這n個隨機數總和，並測量所需時間。
   （測量的時間不包含新增資料所需時間）
3. 為了降低誤差，重複上述實驗多次後取平均。

## Reports
1. 兩個折線圖（每個圖包含2條折線，分別代表dynamic array與linked list所需時間）。
   折線圖的x 軸為n，y 軸為時間。
2. dynamic array與linked list的程式碼來源，
   並解釋這些程式碼確實實作dynamic array與linked list。

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
experiments' raw data are stored in **.csv** files  
