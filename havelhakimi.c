#include<stdio.h>
void bubblesort(int*data,int element);//昇順に並び替えるための関数
void havelhakimi(int*data,int element);//havelhakmiの定理を用いるための関数
char checkdata(int*data,int element);//dataの中身をチェックし，中身の数字に応じてC,F,Eの値を返す
void data_subt(int*data,int element);//一番大きい値を消す，その数字分1引いていく操作を行う関数
void printdata(int*data ,int element);//dataの中身を表示する関数

void main(){
   int input = 0;//標準入力した値を格納する変数
   printf("判定したい数列の要素数を入れてね！");
   scanf("%d",&input);//入力された値をinputに格納
   const int size = input;//定数sizeに入力された値を代入，定数にするため配列の要素も可
   int data[size];//入力された値でからの配列を初期化
   printf("要素の数字を入れてね！\n");
   for(int i = 0;i < size;i++){
      printf("%dつめの数字:",i+1);
      scanf("%d",&data[i]);//数列の標準入力をdataに格納する
      if(size <= data[i]){
         printf("位数よりも大きい次数なんてあるわけないだろ！！\n");
         i--;
      }
   }
   printdata(data,size);
   havelhakimi(data,size);//havelhakmiの関数を呼び出す．
}

void havelhakimi(int*data,int element){
   bubblesort(data,element);
   printdata(data,element);
   switch(checkdata(data,element)){
   case 'C'://checkdata関数からcontinueが返ってきた場合
         data_subt(data,element);
         printdata(data,element);
         havelhakimi(data,element);
         break;
   case 'E'://checkdata関数からendが返ってきた場合
         printf("次数列だったよ！！良かったね\n");
         return;
         break;
   default://それ以外(faultが帰ってきた場合)
         printf("次数列じゃないよ\n");
         return;
    }      
}
char checkdata(int*data,int element){//数列をチェックする．全て０であればendのE,0より大きい数字がある時点でcontinueのＣ，0より小さい数字があるとfaultのＦを返す
   char answer = 'E';
   for(int i = 0;i < element - 1;i++){
      if(data[i] < 0){//０より小さい値がある時点で返す
         answer = 'F';
         return answer;
      }else if(data [i] > 0){
         answer = 'C';
         return answer;//０より大きい数字がある時点で返す
      }
   }
   return answer;
}
void data_subt(int *data,int element){//データの引き算をする．
   int max = data[element - 1];//最大値を保存
   int index = element - 2;//右から二番目から引いていきたいのでこの値で初期化
   data[element - 1]  = 0;//０を入れる（理由はアルゴリズムの説明で記載）
   while(max > 0){
      max--;//最大値の数だけ，上から引いていく
      
      data[index] = data[index] - 1;//１引く
      index--;//配列の添字を一つずらす
   }
}
void bubblesort(int*data,int element){//昇順に並び替える
   int temp = 0;
   for(int i = element - 1;i > 0;i--){
      for(int j = 0;j < i;j++){
         if(data[j] > data[j + 1]){
            temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
         }
      }
   }
}
void printdata(int*data ,int element){
   for(int i = 0;i < element ;i++){
      printf("%d  ",data[i]);
   }
   printf("\n");
}
