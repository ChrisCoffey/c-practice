#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char** splitOn(char* text, const char divider) {
    int dividers = 0;
    int length = strlen(text);
    for(int i=0; i < length; i++){
        if(*(text+i) == divider) {
            dividers++;
        }
    }


    char** result = malloc(dividers * sizeof(char*));
    int sliceStart = 0;
    int stored = 0;
    for(int i=0; i< length ; i++){
        // printf("sliceStart: %d \tsliceEnd: %d \tdividers: %d \tlength: %d", sliceStart, i, dividers, length);
        if(*(text+i) == divider) {
            char* str = malloc((i - sliceStart) * sizeof(char));
            for(int n=0; n<length - sliceStart; n++){
                str[n] = text[sliceStart + n];
            }
            //memcpy(str, text + sliceStart, i - sliceStart);
            result[stored++] = str;
        }
        sliceStart= i+1;
    }

    return result;
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[k -1 ][m -1][n -1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return *(*(document + (k -1)) + (m -1));
}

char*** kth_paragraph(char**** document, int k) {
    return *(document + (k -1));
}

char**** get_document(char* text) {
    char** raw_paragraphs = splitOn(text, '\n');
    int num_paragraphs = sizeof(raw_paragraphs) / sizeof(char**);
    char**** result = malloc(num_paragraphs * sizeof(char****));

    // split the paragraphs into sentences
    for(int i = 0; i< num_paragraphs; i++){
        char** raw_sentences = splitOn(raw_paragraphs[i], '.');
        int num_sentences = sizeof(raw_sentences) / sizeof(char**);
        char*** p = malloc(num_sentences * sizeof(char***));

        // split each sentence into its constituent words
        for(int z = 0; z < num_sentences; z++){
            p[z] = splitOn(raw_sentences[i], ' ');
        }

        result[i] = p;
    }

    printf("number of paragraphs %d", num_paragraphs);
    printf("%s", result[1][1][1]);
    return result;
}


char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}
