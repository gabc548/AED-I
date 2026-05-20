// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

void PopSandwiches(int* sandwiches, int* sandwichesSize){
    for(int i = 0; i < *sandwichesSize - 1; i++){
        sandwiches[i] = sandwiches[i + 1];
    }

    (*sandwichesSize)--;

    return;
}

void PopStudents(int* students, int* studentsSize){
    for(int i = 0; i < *studentsSize - 1; i++){
        students[i] = students[i + 1];
    }

    (*studentsSize)--;

    return;
}

void MoveStudents(int* students, int* studentsSize){
    int tmp = students[0];

    for(int i = 0; i < *studentsSize - 1; i++){
        students[i] = students[i + 1];
    }

    students[*studentsSize - 1] = tmp;

    return;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    for(int i = 0; i < studentsSize; i++){
        if(sandwiches[0] == students[0]){
            PopStudents(students, &studentsSize);
            PopSandwiches(sandwiches, &sandwichesSize);
            i = -1;
        } else{
            MoveStudents(students, &studentsSize);
        }
    }

    return studentsSize;
}