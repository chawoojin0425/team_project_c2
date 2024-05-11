#include<stdio.h>
#include<string.h>
typedef struct a { //이름, 학번, 점수1, 점수2를 구조체로 묶어서 정의
   char name[50];
   int id;
   int score1;
   int score2;
}student;
int main() {
    a student[3] = { //구조체 배열에 순서대로 정보 입력
    { "김철수",20240001,95,90 },
    { "김영희",20240002,85,80 },
    { "홍길동",20240003,35,50 },
    };
    FILE* fp = fopen("sj.txt", "wb"); //이진 쓰기 모드로 파일 열기
    if (fp == NULL) {
        printf("파일 열기 실패!");
        return 1;
    }//for문,fprintf를 사용하여 학생 각각의 정보 4가지를 구조체에 가져와서 출력
    for (int n = 0; n < 3; n++) {  
        fprintf(fp, "%s %d %d %d\n", student[n].name, student[n].id, student[n].score1, student[n].score2);
    }
    fclose(fp); //파일 닫기

    fp = fopen("sj.txt", "r"); //파일 읽기 모드
    if (fp == NULL) {
        printf("파일 열기 실패!\n");
        return 1;
    }

    // 과목별, 개인별 평균 변수 정의
    int total_score1 = 0, total_score2 = 0;
    float avg_score1, avg_score2;

    // 파일에서 데이터 읽어오기 및 처리
    printf("\n개인별 평균:\n");
    for (int i = 0; i < 3; i++) {// 구조체 배열에서 불러오기
        fscanf(fp, "%s %d %d %d", &student[i].name, &student[i].id, &student[i].score1, &student[i].score2); //개인별 정보 불러오기
        printf("%s의 개인별 평균: %.2f\n", student[i].name, (float)(student[i].score1 + student[i].score2) / 2); //개인별 평균 계산
        total_score1 += student[i].score1;
        total_score2 += student[i].score2;//각 과목의 점수 대입->과목별 3명의 점수 합
    }

    // 파일 닫기
    fclose(fp);

    // 과목별 평균 계산
    avg_score1 = (float)total_score1 / 3;
    avg_score2 = (float)total_score2 / 3;
    printf("\n과목 1의 평균: %.2f\n", avg_score1);
    printf("과목 2의 평균: %.2f\n", avg_score2);
}
