char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)

{
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m)

{ 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k)

{
    return document[k-1];
}

char**** get_document(char* text)

{
    int para_count = 1;
    for (int i = 0; text[i]; i++)
    
    {
        if (text[i] == '\n') para_count++;
    }
    
    char**** document = (char****)malloc(para_count * sizeof(char***));
    
    int para_idx = 0;
    char* para_start = text;
    
    for (int i = 0; ; i++)
    
    {
        if (text[i] == '\n' || text[i] == '\0')
        
        {
            int para_len = &text[i] - para_start;
            char* paragraph = (char*)malloc((para_len + 1) * sizeof(char));
            strncpy(paragraph, para_start, para_len);
            paragraph[para_len] = '\0';
            
            int sent_count = 0;
            for (int j = 0; paragraph[j]; j++)
            
            {
                if (paragraph[j] == '.') sent_count++;
            }
            
            document[para_idx] = (char***)malloc(sent_count * sizeof(char**));
            
            int sent_idx = 0;
            char* sent_start = paragraph;
            
            for (int j = 0; ; j++)
            
            {
                if (paragraph[j] == '.' || paragraph[j] == '\0')
                
                {
                    int sent_len = &paragraph[j] - sent_start;
                    char* sentence = (char*)malloc((sent_len + 1) * sizeof(char));
                    strncpy(sentence, sent_start, sent_len);
                    sentence[sent_len] = '\0';
                    
                    int word_count = 0;
                    int in_word = 0;
                    for (int k = 0; sentence[k]; k++)
                    
                    {
                        if (sentence[k] == ' ')
                        
                        {
                            in_word = 0;
                        } 
                        
                        else if (!in_word) 
                        
                        {
                            in_word = 1;
                            word_count++;
                        }
                    }
                    
                    document[para_idx][sent_idx] = (char**)malloc(word_count * sizeof(char*));
                    
                    int word_idx = 0;
                    char* word_start = NULL;
                    
                    for (int k = 0; k <= sent_len; k++) {
                        if (k == sent_len || sentence[k] == ' ')
                        
                        {
                            if (word_start != NULL) {
                                int word_len = &sentence[k] - word_start;
                                document[para_idx][sent_idx][word_idx] = (char*)malloc((word_len + 1) * sizeof(char));
                                strncpy(document[para_idx][sent_idx][word_idx], word_start, word_len);
                                document[para_idx][sent_idx][word_idx][word_len] = '\0';
                                word_idx++;
                                word_start = NULL;
                            }
                            
                        } 
                        
                        else if (word_start == NULL)
                        
                        {
                            word_start = &sentence[k];
                        }
                    }
                    
                    sent_idx++;
                    
                    if (paragraph[j] == '\0') break;
                    sent_start = &paragraph[j + 1];
                }
            }
            
            para_idx++;
            
            if (text[i] == '\0') break;
            para_start = &text[i + 1];
        }
    }
    
    return document;
}