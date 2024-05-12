#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20]; 
    int id;                      
    int score1;                  
    int score2;                 
} Student;

int main() {
   Student students[3] = {
    {"김철수", 20230001, 90, 85},
    {"이영희", 20230002, 85, 92},
    {"박지영", 20230003, 78, 83},
   };
   
   FILE *fp = fopen("sj.txt", "w");
   if (fp == NULL) {
    printf("파일 열기 실패\n");
    return 1;
   }
   
   for (int i = 0; i < 3; i++) {
    fwrite(&students[i], sizeof(Student), 1, fp);
   }
   
   fclose(fp);
   
    fp = fopen("sj.txt", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    
    fread(students, sizeof(Student), 3, fp);
    
   fclose(fp);

    float total1 = 0, total2 = 0;
    for (int i = 0; i < 3; i++) {
        float avg = (students[i].score1 + students[i].score2) / 2.0;
        total1 += students[i].score1;
        total2 += students[i].score2;
        printf("%s (학번: %d): 개인 평균=%.2f\n", students[i].name, students[i].id, avg);
    }

    float avg1 = total1 / 3;
    float avg2 = total2 / 3;

    printf("과목1 평균=%.2f, 과목2 평균=%.2f\n", avg1, avg2);

    return 0;
}
