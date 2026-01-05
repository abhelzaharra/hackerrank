struct document get_document(char* text)

{
    struct document doc;
    doc.paragraph_count = 0;
    doc.data = NULL;

    struct paragraph para = {NULL, 0};
    struct sentence sen = {NULL, 0};
    struct word w;

    int i = 0, start = 0;

    while (1)
    
    {
        char c = text[i];

        if (c == ' ' || c == '.' || c == '\n' || c == '\0')
        
        {
            int len = i - start;
            if (len > 0)
            
            {
                w.data = malloc(len + 1);
                strncpy(w.data, text + start, len);
                w.data[len] = '\0';

                sen.word_count++;
                sen.data = realloc(sen.data, sen.word_count * sizeof(struct word));
                sen.data[sen.word_count - 1] = w;
            }

            start = i + 1;

            if (c == '.')
            
            {
                para.sentence_count++;
                para.data = realloc(para.data, para.sentence_count * sizeof(struct sentence));
                para.data[para.sentence_count - 1] = sen;

                sen.data = NULL;
                sen.word_count = 0;
            }

            if (c == '\n' || c == '\0')
            
            {
                if (para.sentence_count > 0)
                
                {
                    doc.paragraph_count++;
                    doc.data = realloc(doc.data, doc.paragraph_count * sizeof(struct paragraph));
                    doc.data[doc.paragraph_count - 1] = para;

                    para.data = NULL;
                    para.sentence_count = 0;
                }
            }

            if (c == '\0') break;
        }

        i++;
    }

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)

{
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)

{
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k)

{
    return Doc.data[k - 1];
}