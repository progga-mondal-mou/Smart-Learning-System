SMART LEARNING SYSTEM (SLS)
Project folder structure only — no C code has been added yet.

This starter folder layout is based on the Smart Learning System scope discussed:
- Student, Teacher and Admin modules
- Adaptive learning and adaptive examination
- Weak-topic detection and personalized recommendations
- Learning progress/history
- Question analytics and difficulty estimation
- File-based data storage

IMPORTANT:
All .c and .h files are intentionally empty placeholders.
No implementation/code is included. You will fill them gradually in VS Code.

Suggested first implementation order:
1. src/main.c
2. Authentication
3. Student / Teacher / Admin menus
4. Question and study-material management
5. Examination and evaluation
6. Learning Engine
7. Analytics and reports

Overall system cycle:
START
  -> Initialize system and data files
  -> Main menu
      -> Student: register/login
          -> Learning dashboard
          -> Read study materials / practice / take adaptive exam
          -> Analyze performance and topic strengths/weaknesses
          -> Recommend notes and practice questions
          -> Update learning history and topic statistics
          -> Return to learning dashboard / logout
      -> Teacher: login
          -> Create/edit/delete MCQs
          -> Publish/manage study materials
          -> Review student performance and question statistics
          -> Logout
      -> Admin: login
          -> Manage student/teacher accounts
          -> Review content
          -> Configure exam settings
          -> View system reports
          -> Backup/restore data
          -> Logout
  -> Exit

Core learning cycle:
LEARN -> PRACTICE/ASSESS -> ANALYZE -> ADAPT -> RECOMMEND -> IMPROVE
