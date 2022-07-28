#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  //임의의 세 수 중복없이 컴퓨터가 인지
  int arr[3];
  srand(time(NULL));

  for(int i=0; i<3; i++){
    arr[i]=rand()%10;//0부터 9까지
    for(int j=0; j<i; j++){
      if(arr[i]==arr[j]){//중복없는 3개의 숫자 생성
        i--;
        break;
      }
    }
  }
  //사용자 입력
  int user[3];

  //사용자와 컴퓨터 숫자 비교
  int k=0;
  int str=0;
  int ball=0;

  while(k<10){//10회차까지
    str=0;
    ball=0;

    printf("0~9사이의 숫자 3개를 입력해주세요: ");
    for(int i=0; i<3; i++){
      scanf("%d",&user[i]);
    }

    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        if(arr[i]==user[j]){
          if(i==j){//strike
            str++;
            break;
          }
          else{//ball
            ball++;
            break;
          }
        }
      }
    }
    printf("[%d회차] 스트라이크:%d 볼:%d\n",k+1,str,ball);

    if(str==3){
      printf("승리하였습니다!\n");
      break;
    }
    k++;
  }

  if(k==10){
    printf("컴퓨터가 승리하였습니다..");
  }

  return 0;
}