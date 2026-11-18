
#ifndef STUDENT_H
#define STUDENT_H

void StudentPortal(void);

int AssessmentCompleted(const char *userName);

int SaveAssessmentResult(
    const char *username,
    const char *topic,
    int correct,
    int total,
    float percentage,
    const char *level
);

void InitialAssessment(const char *userName);
// void StudySystem();
// void PracticeSystem();
// void AdaptiveEngine();
// void Examination();
//void ProgressReport();
// 
void studentDashboard(const char * userName);


#endif
