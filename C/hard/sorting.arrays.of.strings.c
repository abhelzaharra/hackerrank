int lexicographic_sort(const char* a, const char* b)

{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b)

{
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b)

{
    int count_a[256] = {0}, count_b[256] = {0};
    int distinct_a = 0, distinct_b = 0;
    for (int i = 0; a[i]; i++) if (!count_a[(unsigned char)a[i]]++) distinct_a++;
    for (int i = 0; b[i]; i++) if (!count_b[(unsigned char)b[i]]++) distinct_b++;
    if (distinct_a != distinct_b) return distinct_a - distinct_b;
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b)

{
    int diff = strlen(a) - strlen(b);
    if (diff != 0) return diff;
    return strcmp(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b))

{
    for (int i = 0; i < len - 1; i++)
    
    {
        for (int j = i + 1; j < len; j++)
        
        {
            if (cmp_func(arr[i], arr[j]) > 0)
            
            {
                char* t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}