#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int hashf(char*x) {
    int i = 0, sum = 0;
    while (x[i] != '\0')
    {
        sum = sum + x[i];
        i++;
    }
    return sum % 100;
}

int sravn(char* x, char* y) {
    int i = 0;
    while (x[i] != '\0' || y[i] != '\0')
    {
        if (x[i] > y[i]) {return 1;}
        if (x[i] < y[i]) {return -1;}
        i++;
    }
    return 0;
}

struct node
{
    char name[20];
    int res;
    char answ[20];
    int block;
} P1 = {"", 0, ""}, P2;

FILE *fp = fopen("HASHFUNC.txt", "r+");
int ch = 0;
int s;
char pass[200];
int main()
{
    // int l, p = 0;
    fread(&P1, sizeof(P1), 1, fp);
    s = P1.res;
    printf("%d", s);
    do
    {
        printf("\n1 - Sign Up\n2 - Log In\n3 - Forgot Password\n4 - Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            int prov = 0;
            fseek(fp, sizeof(P1), SEEK_SET);
            do
            {
                prov = 0;
                printf("Enter login: ");
                scanf("%20s", P1.name);
                for (int i = 0; i < s; i++) {
                    fread(&P2, sizeof(P1), 1, fp);
                    if (sravn(P1.name, P2.name) == 0) {
                        printf("Login exists ");
                        prov++;
                        break;
                    }
                }
            } while (prov == 1);
            printf("Enter Password: ");
            scanf("%200s", pass);
            P1.res = hashf(pass);
            printf("Secret! What was the name of your first pet or gf?\n");
            scanf("%20s", P1.answ);
            fseek(fp, (1 + s) * sizeof(P1), SEEK_SET);
            fwrite(&P1, sizeof(P1), 1, fp);
            P1.res = s + 1;
            fseek(fp, 0, SEEK_SET);
            fwrite(&P1, sizeof(P1), 1, fp);
        }

        if (ch == 2)
        {
            char login[20];
            char pass[20];
            // char secret[20];
            printf("Enter lohin:\n");
            scanf("%20s", login);
            fseek(fp, 0, SEEK_SET);
            int flag = 0;
            int i;
            for (i = 0; i < s; i++)
            {
                fread(&P1, sizeof(node), 1, fp);
                if (sravn(P1.name, login) == 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == true || P1.block == 0)
            {
                for (i = 0; i < s; i++)
                {
                    if (sravn(P1.name, login) == 0)
                    {
                        flag = true;
                        printf("Enter pass:\n");
                        scanf("%20s", pass);
                        int prov = hashf(pass);
                        if (prov == P1.res)
                        {
                            printf("Success!\n");
                        }
                        else printf("Wrong password!\n");
                    }
                }
                if (flag == 0) printf("Do not founded!\n");
            }

        }

        if (ch == 3)
        {
            char login[20] = "";
            // char pass[20] = "";
            char change[20] = "";
            char secret[20] = "";
            printf("Enter login:\n");
            scanf("%20s", login);
            fseek(fp, 0, SEEK_SET);
            int flag = 0;
            while (fread(&P1, sizeof(node), 1, fp) == 1)
            {
                if (sravn(P1.name, login) == 0)
                {
                    flag = 1;
                    printf("Enter secret word:\n");
                    scanf("%20s", secret);
                    if (sravn(secret, P1.answ) == 0)
                    {
                        printf("Enter new Password:\n");
                        scanf("%20s", change);
                        P1.res = hashf(change);
                        fwrite(&P1.res, sizeof(P1), 1, fp);
                        printf("Password has been changed!\n");
                        break;
                    }
                    else printf("Wrong secret word!\n");
                }
                if (flag == 0) printf("Do not founded!\n");
            }
            
        }

    } while (ch == 4);
    fclose(fp);
}
