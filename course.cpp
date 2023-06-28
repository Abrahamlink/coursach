#include <iostream>
#include <string>

char second[200];

using namespace std;

int step(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    for (int i = 1; i < y; i++)
    {
        x = x * x;
    }
    return x;
}

char proverka(int x)
{
        if (x == 10) { return 'A';}
        if (x == 11) { return 'B';}
        if (x == 12) { return 'C';}
        if (x == 13) { return 'D';}
        if (x == 14) { return 'E';}
        if (x == 15) { return 'F';}
}

void dvoch(int numder)
{
    int temp;
    int i = 0;
    for (temp = 256; temp > 0; temp = temp / 2)
    {
        if (temp & numder)
        {
            second[i] = '1';
            i++;
        }
        else
        {
            second[i] = '0';
            i++;
        }
    }
    while (second[0] != '1')
    {
        for (int j = 0; j < i + 1; j++)
        {
            second[j] = second[j + 1];
        }
    }
}

class Strika
{
protected:
    char content[200];
    int len;
public:

    Strika(void)
    {
        content[0] = '\0';
        len = 0;
    }
    Strika(char x)
    {
        content[0] = x;
        content[1] = '\0';
        len = 1;
    }
    Strika(char* x)
    {
        int i = 0;
        while (x[i] != '\0')
        {
            content[i] = x[i];
            i++;
        }
        content[i] = '\0';
        len = i;
    }
    void Stroka(char* x)
    {
        int i = 0;
        while (x[i] != '\0')
        {
            content[i] = x[i];
            i++;
        }
        content[i] = '\0';
        len = i;
    }
    void sdvigVP(int x)
    {
        for (int i = 0; i < x; i++)
        {
            del_last();
        }
    }
    void sdvigVL(int x)
    {
        for (int i = 0; i < x; i++)
        {
            del_first();
        }
        content[strlen(content)] = '0';
        content[strlen(content)] = '\0';
    }
    void show(void)
    {
        cout << "content:" << content << " ,len:" << len << endl;
        cout << endl;
    }
    void del_last(void)
    {
        if (len != 0)
        {
            content[--len] = '\0';
        }
    }
    void del_first(void)
    {
        int i = 0;
        while (content[i] != '\0')
        {
            content[i] = content[i + 1];
            i++;
        }
        content[i] = '\0';
        len = i - 1;
    }
    void add_end(char x)
    {
        content[len] = x;
        content[len + 1] = '\0';
        len++;
    }
    void add_begin(char x)
    {
        for (int i = 0; i <= len; i++)
        {
            content[len - i + 1] = content[len - i];
        }
        content[0] = x;
        len++;
    }
};

class bin : public Strika
{
protected:
    int des;
public:
    bin() :Strika() { des = 0; }
    bin(char* x)
    {
        int i = 0;
        int i2 = 0;
        while (x[i] != '\0')
        {
            if (x[i] == '1' || x[i] == '0')
            {
                content[i2] = x[i];
                i2++;
            }
            i++;
        }
        content[i2] = '\0';
        len = i2;
    }
    void sdvigVpravo(int x)
    {
        int i = len + 1;
        while (i != 0)
        {
            content[i + x] = content[i];
            i--;
        }
        while (i != x)
        {
            content[i] = '0';
            i++;
        }
        len = len + x;
    }
    void sdvigVlevo(int x)
    {
        len = len - x;

        for (int i = 0; i < len; i++)
        {
            content[i] = content[i + x];
        }
        content[len + 1] = '\0';
    }
    int bitovoeIchar(char* x)
    {
        int a = chislo(x) & chislo(content);
        return a;
    }
    int bitovoeIchislo(int x)
    {
        int a = chislo(content) & x;
        return a;
    }
    int bitovoeILIchar(char* x)
    {
        int a = chislo(x) | chislo(content);
        return a;
    }
    int bitovoeILIchislo(int x)
    {
        int a = chislo(content) | x;
        return a;
    }
    int bitovoeISILIchar(char* x)
    {
        int a = chislo(x) ^ chislo(content);
        return a;
    }
    int bitovoeISILIchislo(int x)
    {
        int a = chislo(content) ^ x;
        return a;
    }
    int bitovoeISKL(void)
    {
        int a = ~chislo(content);
        return a;
    }
    char binvyvod(void)
    {
        return content[0];
    }
    int chislo(char* x)
    {
        int Chislo = 0;
        int j = 1;
        for (int i = 0; i < strlen(x); i++)
        {
            Chislo *= 2;
            Chislo += x[i] - '0';
        }
        return Chislo;
    }
};

class hexstring : public bin
{
private:
    int ch16;
public:
    hexstring() :bin() {}
    hexstring(char* x)
    {
        int i = 0;
        int i2 = 0;
        while (x[i] != '\0')
        {
            if (x[i] > 47 && x[i] < 58)
            {
                content[i2] = x[i];
                i2++;
                content[i2] = '\0';
            }
            if (x[i] > 64 && x[i] < 71)
            {
                content[i2] = x[i];
                i2++;
                content[i2] = '\0';
            }
            if (x[i] > 96 && x[i] < 103)
            {
                content[i2] = x[i]-32;
                i2++;
                content[i2] = '\0';
            }
            i++;
        }
        content[i2] = '\0';
        des = perevod(x);
    }
    void hexshow(void)
    {
        cout << content << endl;
    }
    void sdvigP(int x)
    {
        des = des >> x;
        perevoddes(des);
    }
    void sdvigL(int x)
    {
        des = des << x;
        perevoddes(des);
    }
    int perevod(char* x)
    {
        int summ = 0;
        int i2 = 0;
        for (int i = strlen(x) - 1; i > -1; i--)
        {
            if (x[i] > 64)
            {
                if (x[i] == 65)
                {
                    summ = summ + 10 * step(16, i2);
                }
                if (x[i] == 66)
                {
                    summ = summ + 11 * step(16, i2);
                }
                if (x[i] == 67)
                {
                    summ = summ + 12 * step(16, i2);
                }
                if (x[i] == 68)
                {
                    summ = summ + 13 * step(16, i2);
                }
                if (x[i] == 69)
                {
                    summ = summ + 14 * step(16, i2);
                }
                if (x[i] == 70)
                {
                    summ = summ + 15 * step(16, i2);
                }
            }
            else
            {
                summ = summ + (x[i] - 48) * step(16, i2);
            }
            i2++;
        }
        return summ;
    }
    void perevoddes(int x)
    {
        char g[200];
        int i = 0;
        while (x > 0)
        {
            if ((x % 16) < 10)
            {
                g[i] = x % 16 + 48;
                i++;
                g[i] = '\0';
            }

            else
            {
                g[i] = proverka(x % 16);
                i++;
                g[i] = '\0';
            }
            x = x / 16;
        }
        int k = 0;
        for (int j = strlen(g) - 1; j >= 0; j--)
        {
            content[k] = g[j];
            k++;
        }
        content[strlen(g)] = '\0';
    }
    int hexdes(void) { return des; }
};


void strokamenu(char* x)
{
    Strika s(x);

    int choice;
    do
    {
        cout << "************************************" << endl;
        cout << "press 1 to show" << endl;
        cout << "press 2 to delete last" << endl;
        cout << "press 3 to delete first" << endl;
        cout << "press 4 to add to the end" << endl;
        cout << "press 5 to add to the beginning" << endl;
        cout << "press 6 to exit" << endl;
        cout << "************************************" << endl;
        do
        {
            cin >> choice;
            if (choice < 1 || choice > 6)
            {
                cout << "incorect" << endl;
            }
        } while (choice < 1 || choice > 6);
        if (choice == 1) { s.show(); }
        if (choice == 2) { s.del_last(); s.show(); }
        if (choice == 3) { s.del_first(); s.show(); }
        if (choice == 4) { cout << "enter:"; char X; cin >> X; s.add_end(X); s.show(); }
        if (choice == 5) { cout << "enter:"; char X; cin >> X; s.add_begin(X); s.show(); }
    } while (choice != 6);
    system("cls");
}

void binmenu(char* x)
{
    bin b(x);

    int choice, choiceI, choiceILI, choiceISILI;
    do
    {
        cout << "************************************" << endl;
        cout << "press 1 to show" << endl;
        cout << "press 2 to sdvig V pravo" << endl;
        cout << "press 3 to sdvig V levo" << endl;
        cout << "press 4 to bitovoe i" << endl;
        cout << "press 5 to bitovoe ili" << endl;
        cout << "press 6 to bitovoe iskluch. ili" << endl;
        cout << "press 7 to bitovoe otricanie" << endl;
        cout << "press 8 to delete last" << endl;
        cout << "press 9 to delete first" << endl;
        cout << "press 10 to add to the end" << endl;
        cout << "press 11 to add to the beginning" << endl;
        cout << "press 12 to exit" << endl;
        cout << "************************************" << endl;
        do
        {
            cin >> choice;
            if (choice < 1 || choice > 12)
            {
                cout << "incorect" << endl;
            }
        } while (choice < 1 || choice > 12);
        if (choice == 1) { b.show(); }
        if (choice == 2)
        {
            int l;
            cout << "Vvedite ns skolko: ";
            cin >> l;
            cout << "Otvet: " << endl;
            b.sdvigVpravo(l);
            b.show();

        }
        if (choice == 3)
        {
            int l;
            cout << "Vvedite ns skolko: ";
            cin >> l;
            cout << "Otvet: " << endl;
            b.sdvigVlevo(l);
            b.show();
        }
        if (choice == 4)
        {
            cout << "Vvedite char ili chislo: " << endl;
            cout << "1. char" << endl;
            cout << "2. chislo" << endl;
            do
            {
                cin >> choiceI;
                if (choiceI < 1 || choiceI > 2)
                {
                    cout << "incorect" << endl;
                }
            } while (choiceI < 1 || choiceI > 2);
            if (choiceI == 1)
            {
                char arr2[200];
                cout << "Vvedite char: " << endl;
                cin >> arr2;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeIchar(arr2));
                cout << second << endl;
                second[0] = '\0';

            }
            if (choiceI == 2)
            {
                int arr3;
                cout << "Vvedite chislo: " << endl;
                cin >> arr3;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeIchislo(arr3));
                cout << second << endl;
                second[0] = '\0';
            }
        }
        if (choice == 5)
        {
            cout << "Vvedite char ili chislo: " << endl;
            cout << "1. char" << endl;
            cout << "2. chislo" << endl;
            do
            {
                cin >> choiceILI;
                if (choiceILI < 1 || choiceILI > 2)
                {
                    cout << "incorect" << endl;
                }
            } while (choiceILI < 1 || choiceILI > 2);
            if (choiceILI == 1)
            {
                char arr2[200];
                cout << "Vvedite char: " << endl;
                cin >> arr2;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeILIchar(arr2));
                cout << second << endl;
                second[0] = '\0';

            }
            if (choiceILI == 2)
            {
                int arr3;
                cout << "Vvedite chislo: " << endl;
                cin >> arr3;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeILIchislo(arr3));
                cout << second << endl;
                second[0] = '\0';
            }
        }
        if (choice == 6)
        {
            cout << "Vvedite char ili chislo: " << endl;
            cout << "1. char" << endl;
            cout << "2. chislo" << endl;
            do
            {
                cin >> choiceISILI;
                if (choiceISILI < 1 || choiceISILI > 2)
                {
                    cout << "incorect" << endl;
                }
            } while (choiceISILI < 1 || choiceISILI > 2);
            if (choiceISILI == 1)
            {
                char arr2[200];
                cout << "Vvedite char: " << endl;
                cin >> arr2;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeISILIchar(arr2));
                cout << second << endl;
                second[0] = '\0';

            }
            if (choiceISILI == 2)
            {
                int arr3;
                cout << "Vvedite chislo: " << endl;
                cin >> arr3;
                cout << "Otvet: " << endl;
                dvoch(b.bitovoeISILIchislo(arr3));
                cout << second << endl;
                second[0] = '\0';
            }
        }
        if (choice == 7)
        {
            cout << "Otvet: " << endl;
            dvoch(b.bitovoeISKL());
            cout << second << endl;
            second[0] = '\0';
        }
        if (choice == 8)
        {
            b.del_last();
            b.show();

        }
        if (choice == 9)
        {
            b.del_first();
            while (b.binvyvod() != 1)
            {
                b.del_first();
            }
            b.show();
        }
        if (choice == 10)
        {
            cout << "enter: "; char X; cin >> X; b.add_end(X);
            b.show();
        }
        if (choice == 11)
        {
            cout << "enter: "; char X; cin >> X; b.add_begin(X);
            b.show();
        }
    } while (choice != 12);
    system("cls");
}

void hexmenu(char* x)
{
    hexstring h(x);
    int choice;
    do
    {
        cout << "************************************" << endl;
        cout << "press 1 to show" << endl;
        cout << "press 2 to sdvig V pravo" << endl;
        cout << "press 3 to sdvig V levo" << endl;
        cout << "press 4 to bitovoe i" << endl;
        cout << "press 5 to bitovoe ili" << endl;
        cout << "press 6 to bitovoe iskluch. ili" << endl;
        cout << "press 7 to bitovoe otricanie" << endl;
        cout << "press 8 to exit" << endl;
        cout << "************************************" << endl;
        do
        {
            cin >> choice;
            if (choice < 1 || choice > 6)
            {
                cout << "incorect" << endl;
            }
        } while (choice < 1 || choice > 8);
        if (choice == 1) { h.hexshow(); }
        if (choice == 2)
        {
            int l;
            cout << "Vvedite na skolko: ";
            cin >> l;
            cout << "Otvet: " << endl;
            h.sdvigP(l);
            h.hexshow();
        }
        if (choice == 3)
        {
            int l;
            cout << "Vvedite na skolko: ";
            cin >> l;
            cout << "Otvet: " << endl;
            h.sdvigL(l);
            h.hexshow();
        }
        if (choice == 4)
        {
            int arr3;
            cout << "Vvedite chislo: " << endl;
            cin >> arr3;
            cout << "Otvet: " << endl;
            arr3 = h.hexdes() & arr3;
            cout << arr3 << endl;
        }
        if (choice == 5)
        {
            int arr3;
            cout << "Vvedite chislo: " << endl;
            cin >> arr3;
            cout << "Otvet: " << endl;
            arr3 = h.hexdes() | arr3;
            cout << arr3 << endl;
        }
        if (choice == 6)
        {
            int arr3;
            cout << "Vvedite chislo: " << endl;
            cin >> arr3;
            cout << "Otvet: " << endl;
            arr3 = h.hexdes() ^ arr3;
            cout << arr3 << endl;
        }
        if (choice == 7)
        {
            cout << "Otvet: " << endl;
            cout << ~h.hexdes() << endl;
        }
    } while (choice != 8);
    system("cls");
}


void choosestring()
{
    char arr[200];
    cout << "Vvedite stroky: " << endl;
    cin >> arr;
    int vb;
    do
    {
        cout << "************************************" << endl;
        cout << "press 1 to open base string menu " << endl;
        cout << "press 2 to bin menu" << endl;
        cout << "press 3 to hex menu" << endl;
        cout << "press 4 to change stroky" << endl;
        cout << "press 5 to exit" << endl;
        cout << "************************************" << endl;
        do
        {
            cin >> vb;
            if (vb < 1 || vb > 5)
            {
                cout << "incorect" << endl;
            }
        } while (vb < 1 || vb > 5);
        if (vb == 1)
        {
            system("cls");
            strokamenu(arr);
        }
        if (vb == 2)
        {
            system("cls");
            binmenu(arr);
        }
        if (vb == 3)
        {
            system("cls");
            hexmenu(arr);
        }
        if (vb == 4)
        {
            system("cls");
            cout << "Vvedite stroky: " << endl;
            cin >> arr;
        }
    } while (vb != 5);
}

int main(void)
{
    choosestring();
}
