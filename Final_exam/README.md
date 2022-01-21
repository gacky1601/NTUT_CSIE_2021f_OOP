# OOP2021f_exam

### 21 Janurary 2022 08:00 - 12:00

**Before final exam, you shuold remove HW08**

1. In the actual git folder, move files of HW08 to backup folder.

2. In bash, go to your git folder and do the following to remove HW08 from both local and remove repositories.

- git pull
- git rm src/*
- git rm test/*
- git rm makefile
- git commit -am "remove HW08"
- git push

3. Download source code of midterm from this reop and put it in your git folder.

**After above steps, here are the actual content of the final exam**

### Problem:

In the final exam, you need to implement a set of classes by realizing the concepts of inheritance and polymorphism.

Image there is a ```school```, which has numerous members. Members could be either ```student``` or ```teacher```. Members can be added to this school arbitrarily.

```teacher``` have a some students and ```student``` have some scores. Notably, the number of students in school, students for teacher, and scores for student are uncertain.

Members, a.k.a. ```student``` or ```teacher```, shuold be able to be filtered out from the school with certain conditions. These conditions could be `id` in certain ranges or cetrain `department`. 

Members shuold be able to be transfer to other department as they wish. If not sepcified, members are created with department of "Mechanical & Electrical Engineering".

### Caution:

*In shool (resp. teacher/student), members (resp. students/scores) shuold all be kept in the same array/vector.* (lose 10% if not)

*Memory leak shuold be avoided.* (lose 10% if any)

*Don't use pure virtual functions.* (lose 10% if any)

### Soure tree:

You will have the following folder structure.

```
<student_ID>_HW
├── src
│   ├── school.h
│   ├── school_member.h
│   ├── student.h
│   └── teacher.h
├── test
│   ├── ut_school.h
│   ├── ut_student.h
│   ├── ut_teacher.cpp
│   └── ut_main.cpp
└── makefile
```

### Requirements:

***school_member***

- `int id() const`
  - Getter for id
  
- `std::string name() const`
  - Getter for name

- `std::string department() const`
  - Getter for the department

- `void transfer(std::string const & department)`
  - Members shuold be able to be transfer to other department as they wish
  
Hint: Don't forget (virtual) destructor

***teacher***

- `void addStudent(Student const & stu)`
  - Students are added to a teacher without checking deuplication.
  - Throw `domain_error` if student and teacher are not from the same department, Error content -> ERROR: NOT_IN_THE_SAME_DEPARTMENT
  
- `Student getStudentById(int const id) const` 
  - Get a student by student ID
  - Throw `std::range_error` if not found, Error content -> ERROR: STUDENT_NOT_EXIST

***student***

- `void addScore(double const score)`
  - Add score to student.

- `double getScore(int const number_of_test) const`
  - Get a score at certian index
  - Throw `std::range_error` if out of index, Error content -> ERROR: NO_SUCH_NUMBER_OF_TEST
  
- `double scoreAverage() const`
  - Get an average score of student.
  - Throw `std::range_error` if there are no scores, Error content -> ERROR: NO_SCORE

***school***

- `void addSchoolMember(SchoolMember * const member)`
  - Shool members are added to school without checking deuplication.
  
- `std::vector<SchoolMember *> getSchoolMemberWithCondition(Condition cond)`
  - A template function that takes cond as input and return school members that fits the condition.

Hint: Copy consturctor and copy assignment might be requied.

**Resources allowed to use during the exam:**
-  [cplusplus.com](http://www.cplusplus.com/ "cplusplus.com")
-  [Cambridge Dictionary](https://dictionary.cambridge.org/zht/)
- Your own homework commits. (on Gitlab)
- Our class gitlab webpaghe.

**Attention!! You cannot visit any other website, or you will be considered as cheating.**
