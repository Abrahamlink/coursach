#include <stdio.h>
#include <iostream>
using namespace std;


struct person_data
{
    char login[20];
    int password;
};


int lenOfWord(char *str) // calculate len of word
{
    int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    return i;
}


void connection(char *str, char *stp) // chars concatenate function
{
    int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    int j = 0;
    while (stp[j] != '\0')
    {
        str[i + j] = stp[j];
        j ++;
    }
    str[i + j] = '\0';
}

int file_size(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    cout << ftell(fp) << endl;
    int length = ftell(fp) / sizeof(person_data);
    return length;
}


int Hash(char *key, size_t len) // Hash function
{
    long long int hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % 100000;
}


void archieve(struct person_data b) // Write user data in DB
{
    setlocale(LC_ALL, "ru");
    FILE *fp;
    char *path = "/home/berkut/Documents/database/db.txt";

    fp = fopen(path, "wb");
    if (fp == NULL)
    {
        printf("File not opened! Error!");
    }
    else
    {
        printf("File opened!\n");
    }

    fseek(fp, 0, SEEK_END);
    fwrite((char *)&b, sizeof b, 2, fp);
    fclose(fp);
}

void unarchieve(struct person_data PersonData)
{
    person_data b;
	FILE *fp;
	char *path = "/home/berkut/Documents/database/db.txt";


	fp = fopen(path, "rb");
	if (fp == NULL)
	{
		cout << "file not opened, met an error\n";
		exit(1);
	}
	else
	{
		cout << "unarchiving...\n";
	}

    int length = file_size(fp);
    cout << length << endl;
    size_t elements;
    
    for (int i = 0; i < length; i++) {
        fseek(fp, i*sizeof(person_data), SEEK_SET);
        elements = fread((char *)&b, sizeof(struct person_data), 2, fp);
        cout << b.login << b.password << '\n';
    }

    fclose(fp);
}


void registration(char *login, int password_hash) // registration
{
    struct person_data personality;
    connection(personality.login, login);
    personality.password = password_hash;
    
    printf("%s %d\n", personality.login, personality.password);
    
    archieve(personality);
    unarchieve(personality);
}


void start_function()
{
    char login[30];
    char password_str[30];
    
    printf("Enter login: ");
    scanf("%s", login);
    
    printf("Enter password: ");
    scanf("%s", password_str);
    
    int lenOfPassword = lenOfWord(password_str);
    int password_hash = Hash(password_str, lenOfPassword);
    
    registration(login, password_hash);
}


int main()
{
//    char *password = "f6f7fdfg8ds";
//    int len = lenOfWord(password);
//
//    printf("%d\n", Hash(password, len));
    start_function();
    return 0;
}
