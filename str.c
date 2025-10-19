#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

static char *dup_slice(const char *start, size_t len) {
    char *s = malloc((len + 1) * sizeof(char));
    memcpy(s, start, len);
    s[len] = '\0';
    return s;
}

struct document get_document(char* text) {
    struct word *text_word = malloc(1000 * sizeof(struct word));
    struct sentence *text_senc = malloc(100 * sizeof(struct sentence));
    struct paragraph *text_paragraph = malloc(10 * sizeof(struct paragraph));
    int idx = 0, senc_idx = 0, para_idx = 0;
    char* tok_start = text;
    int len = strlen(text);
    int in_word = 0;
    for (int i = 0; i <= len; ++i) {
        char c = text[i];
        int delim = (c == '.' || c == '\n' || c == ' ' || c == '\0');
        if (!in_word && !delim) {
            tok_start = &text[i];
            in_word = 1;
        }
        
        if (in_word && delim) {
            // printf("%s\n", dup_slice(tok_start, &text[i] - tok_start));
            text_word[idx++].data = dup_slice(tok_start, &text[i] - tok_start);
            in_word = 0;
        }
        
        if (c == '.' || c == '\n' || c == '\0') {
            // for (int z = 0; z < idx; ++z) printf("%s ", text_word[z]);
            // printf("\n");
            text_senc[senc_idx].data = text_word;
            text_senc[senc_idx++].word_count = idx;
            idx = 0;
            text_word = malloc(1000 * sizeof(struct word));
        }
        
        if (c == '\n' || c == '\0') {
            text_paragraph[para_idx].data = text_senc;
            text_paragraph[para_idx++].sentence_count = senc_idx;
            senc_idx = 0;
            text_senc = malloc(100 * sizeof(struct sentence));
        }
    }
    struct document Doc;
    Doc.data = text_paragraph;
    Doc.paragraph_count = para_idx;
    return Doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s ", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}