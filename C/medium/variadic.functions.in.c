int sum(int count, ...)

{
    va_list args;
    va_start(args, count);
    int s = 0;
    for (int i = 0; i < count; i++)
        s += va_arg(args, int);
    va_end(args);
    
    return s;
}


int min(int count, ...)

{
    va_list args;
    va_start(args, count);
    int m = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < m) m = val;
    }
    va_end(args);
    
    return m;
}

int max(int count, ...)

{
    va_list args;
    va_start(args, count);
    int M = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val > M) M = val;
    }
    va_end(args);
    
    return M;
}