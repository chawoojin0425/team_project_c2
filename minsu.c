// 1. 3명의 이름 및 학번 및 2과목 성적을  sj.txt에 저장을 하는코드
#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
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
  for (int i = 0; i < 3; i++) {

    fwrite(&students[i], sizeof(Student), 1, fp);

  }
  fclose(fp);
  printf("학생 정보 저장 완료 (sj.txt)\n");
  return 0;
}
// 2. sj.txt 파일에서 값을 읽어 과목 평균 및 개인별 평균을 구해서 화면에 출력하는 코드를 작성하는코드
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 3
#define MAX_SUBJECTS 2


typedef struct {
    char name[20]; 
    int id;        
    int scores[MAX_SUBJECTS]; 
} Student;


float calculateSubjectAverage(int subject_scores[], int num_students);
float average(int student_scores[], int num_subjects);

int main() {
    
    Student students[MAX_STUDENTS];

  
    FILE *file = fopen("sj.txt", "rb");
   

   
    fread(students, sizeof(Student), MAX_STUDENTS, file);

   
    fclose(file);

   
    printf("과목 평균:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        int subject_scores[MAX_STUDENTS];
        for (int j = 0; j < MAX_STUDENTS; j++) {
            subject_scores[j] = students[j].scores[i];
        }
        float subject_average = calculateSubjectAverage(subject_scores, MAX_STUDENTS);
        printf("과목%d: %.2f\n", i + 1, subject_average);
    }

   
    printf("\n개인별 평균:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        float student_average = average(students[i].scores, MAX_SUBJECTS);
        printf("%s: %.2f\n", students[i].name, student_average);
    }

    return 0;
}


float calculateSubjectAverage(int subject_scores[], int num_students) {
    float total = 0;
    for (int i = 0; i < num_students; i++) {
        total += subject_scores[i];
    }
    return total / num_students;
}


float average(int student_scores[], int num_subjects) {
    float total = 0;
    for (int i = 0; i < num_subjects; i++) {
        total += student_scores[i];
    }
    return total / num_subjects;
}