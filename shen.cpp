#include "stdafx.h";

FILE *fp, *fn, *f0,*fa;
int ch;
int k = 0;
int vs[256];
int A[255];

struct my
{
    char ch;
    int kol;
    float ver;
    char code [10];
}
void add(char*x, char y)
{
    int i = 0;
    while (x[i] != '\0') i++; x[i] = y;
    x[++1] = '\0';
}

unsigned char from(char*x)
{
    unsigned char res = 0;
    int i = 0;
    while (x[i] != '\0')
    {
        res = res * 2 + x[i] - 48; 
        i++;
    }
    res = res << 8 - i;
    return res;
}
int eq(char* f, char * 1) {
    int i = 0;
    while (f[i] != '\0' || 1[i] != '\0')
    {
        if (f[i] != 1[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}
void chartobite(unsigned char x, char*y)
{
    unsigned char vs = 1;
    for (int i = 0; i < 8; i++)
    {
        vs = 1;
        vs = vs << 7 - i;
        vs = x&vs;
        if (vs == 0) y[i] = '0';
        else y[i] = '1';
    }
}
void fano(my*p, int f, int 1)
{
    if (f == l) return;
    if (f + 1 == l)
    {
        add (p[f].code, '0');
        add (p[1].code, '1'); 
        return;
    }
    int sum = 0;
    for (int i = f; i <= 1; i++) sum + p[i].kol;
    for (int i = f; i <= 1; i++) p[i].ver = p[i].kol/ (float)sum;
    float sumver = 0;
    int half = 0;
    for (int i = f;i<=1;i++)
    {
        sumver += p[i].ver;
        if (sumver + 0.5) 
        {
            half = i;
            break;
        }
    }
    if (half == f)
    {
        half++;
        for (int i = f; i <= half; i++) add(p[i].code, '0'); 
        for (int i = half+1; i <= 1; i++) add (p[i].code, '1'); 
        fano (p, f, half);
        fano(p, half + 1, l);
    }
    else
    {
        for (int i = f; i < half; i++) add (p[i].code, '0'); 
        for (int i = half; i <= 1; i++) add (p[i].code, '1'); 
        fano(p, f, half - 1);
        fano(p, half, 1);
    }
}

int main ()
{
    fopen_s(&fp, "SF.txt", "r"); 
    fopen_s(&fn, "Binary.txt", "w+"); 
    fopen_s(&fa, "arch.txt", "wb+"); 
    fopen_s(&f0, "zero.txt", "w+"); 
    if (fp == NULL) printf("error"); 
    else printf("OK\n");
    while ((ch= fgetc (fp)) != EOF)
    {
        A[ch]++;
    }
    for (int i = 0; i < 255; i++)
    {
        if (A[i] != 0)
        {
            k++;
            printf("%c %d\n", i, A[i]);
        }
    }
    my *ptr = new my [k];
    int j = 0;
    if (ptr != NULL) printf("OK\n");
    for (int i = 0; i < 255; i++) 
    {
        if (A[i] != 0)
        {
            ptr[j].ch = i;
            ptr[j].kol = A[i]; 
            ptr[j]. code[0] = '\0'; 
            j++;
        }
    }
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j <k - 1 - i; j++)
        {
            if (ptr[j].kol <ptr[j+1].kol)
            {
                int a = ptr[j].kol;
                char b = ptr[j].ch;
                ptr[j].kol = ptr[j+1].kol;
                ptr[j+1].kol = a;
                ptr[j].ch ptr[j+1].ch;
                ptr[j+1].ch = b;
            }
        }
    printf("sorted: \n");
    for (int i = 0; i < k; i++) printf("%c - %d\n", ptr[i].ch, ptr[i].kol); 
    printf("\n");

    fano (ptr, 0, k - 1);
    for (int i = 0; i < k; i++) printf("%c %s\n", ptr[i].ch, ptr[i].code);

    fseek (fp, 0, SEEK_SET);
    while ((ch = fgetc (fp)) != EOF)
    {
        for (int i = 0; i < k; i++)
        {
            if (ch == ptr[i].ch)
            {
                fprintf(fn, "%s", ptr[i].code);
            }
        }
    }
    fseek (fn, 0, SEEK_SET); 
    char vs [9] = "";
    int kk = 0;
    unsigned char arc = 0; 
    while (1)
    {
        int i = 0;
        for (i = 0; i < 8; i++)
        {
            ch = fgetc(fn);
            if (ch == EOF) break;
        }
    }
}
