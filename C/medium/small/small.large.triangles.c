void sort_by_area(triangle* tr, int n)

{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double s1 = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            
            double area1 = sqrt(s1 * (s1 - tr[j].a) * (s1 - tr[j].b) * (s1 - tr[j].c));

            double s2 = (tr[j + 1].a + tr[j + 1].b + tr[j + 1].c) / 2.0;
            
            double area2 = sqrt(s2 * (s2 - tr[j + 1].a) * (s2 - tr[j + 1].b) * (s2 - tr[j + 1].c));

            if (area1 > area2)
            {
                triangle tmp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = tmp;
            }
        }
    }
}