int marks_summation(int* marks, int number_of_students, char gender) {
    int s = 0;
    int start = (gender == 'b') ? 0 : 1;

    for (int i = start; i < number_of_students; i += 2)
        s += marks[i];

    return s;
}