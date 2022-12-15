#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
enum Magazin { Kopiyka, ATB, Blizenko };
string STRmagazin[] = { "Копійка", "АТБ", "Близенько" };
struct Tovari
{
    string nazva;
    Magazin magazin;
    int vartist;
    double kilk;
    string odvim;
};

void Create(Tovari* s, int N)
{
    int magazin;
    for (int i = 0; i < N; i++)
    {
        cout << "Товар № " << i + 1 << ":" << endl;
        cout << " Товар: "; cin >> s[i].nazva;
        cout << " Магазин (0 - Копійка, 1 - АТБ, 2 - Близенько): ";
        cin >> magazin;
        cout << " Вартість (грн): "; cin >> s[i].vartist;
        cout << " Кількість (шт.): "; cin >> s[i].kilk;
        cout << " Одиниці вимірювання: "; cin >> s[i].odvim;
        s[i].magazin = (Magazin)magazin;
    }
}

void Print(Tovari* s, int N)
{
    cout << "====================================================================================="
        << endl;
    cout << "| № | Товар |    Магазин    |   Вартість   |   Кількість   |   Одиниці вимірювання  |"
        << endl;
    cout << "-------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N ; i++)
    {
        cout << "| " << setw(2) << i + 1;
        cout << "| " << setw(8) << s[i].nazva;
        cout << "| " << setw(15) << STRmagazin[s[i].magazin];
        cout << "| " << setw(11) << s[i].vartist << " грн";
        cout << "| " << setw(11) << s[i].kilk << " шт";
        cout << "| " << setw(11) << s[i].odvim <<  " |";
        cout << endl;
    }
    cout << "====================================================================================="
        << endl;
    cout << endl;

}

Tovari* Add(Tovari* s, int N)
{
    Tovari* t = new Tovari[N + 1];
    for (int i = 0; i < N; i++) {
        t[i] = s[i];
    }
    int magazin;
    cout << "Товар № " << N + 1 << ":" << endl;
        cout << " Товар: "; cin >> t[N].nazva;
        cout << " Магазин (0 - Копійка, 1 - АТБ, 2 - Близенько): ";
        cin >> magazin;
        cout << " Вартість(грн): "; cin >> t[N].vartist;
        cout << " Кількість(шт) : "; cin >> t[N].kilk;
        cout << " Одиниці вимірювання : "; cin >> t[N].odvim;
        t[N].magazin = (Magazin)magazin;
    return t;
}

Tovari* Del(Tovari* s, int* N, int pos)
{
    Tovari* t = new Tovari[*N - 1];
    for (int i = 0, j = 0; i < *N; i++, j++) {
        if (i != pos)
            t[j] = s[i];
        else
            j--;
    }

    return t;
}

void Edit(Tovari* s, int N)
{
    int magazin;
    int strk;
    cout << "Введіть строчку: "; cin >> strk;
    for (int i = 0; i < N; i++)
    {
        if (i == strk) {
             cout << "Товар № " << i + 1 << ":" << endl;
        cout << " Товар: "; cin >> s[i].nazva;
        cout << " Магазин (0 - Копійка, 1 - АТБ, 2 - Близенько): ";
        cin >> magazin;
        cout << " Вартість(грн): "; cin >> s[i].vartist;
        cout << " Кількість(шт) : "; cin >> s[i].kilk;
        cout << " Одиниці вимірювання : "; cin >> s[i].odvim;
        s[i].magazin = (Magazin)magazin;
        }
    }
}

void Sort(Tovari* s, int N)
{
    Tovari tmp;
    int num;
    cout << "Сортування за (1 - назвою товару, 2 - назвою магазину): ";
    cin >> num;
    if (num == 1)
    {
        for (int i0 = 0; i0 < N - 1; i0++)
            for (int i1 = 0; i1 < N - i0 - 1; i1++)
                if (s[i1].nazva > s[i1 + 1].nazva)
                {
                    tmp = s[i1];
                    s[i1] = s[i1 + 1];
                    s[i1 + 1] = tmp;
                }
    }
    else if (num == 2)
    {
        for (int i0 = 0; i0 < N - 1; i0++)
            for (int i1 = 0; i1 < N - i0 - 1; i1++)
                if (s[i1].magazin > s[i1 + 1].magazin)
                {
                    tmp = s[i1];
                    s[i1] = s[i1 + 1];
                    s[i1 + 1] = tmp;
                }
                else
                    return;
    }
}
    
    
void Search(Tovari* s, int N)
    {
    string nazva;
        cout << "Введіть назву товару: "; cin >> nazva;
        for (int i = 0; i < N; i++)
        {
            if (s[i].nazva == nazva) {
                cout << "=========================================================================="
                    << endl;
                cout << "| № | Товар |    Магазин    | Вартість | Кількість | Одиниці вимірювання |"
                    << endl;
                cout << "--------------------------------------------------------------------------"
                    << endl;
                cout << "| " << setw(2) << i + 1;
                cout << "| " << setw(9) << s[i].nazva;
                cout << "| " << setw(20) << STRmagazin[s[i].magazin];
                cout << "| " << setw(11) << s[i].vartist;
                cout << "| " << setw(11) << s[i].kilk;
                cout << "| " << setw(11) << s[i].odvim<< "|";
                cout << endl;
                cout << "=========================================================================";
            }
            else
                return;
        }
    }
void Search2(Tovari* s, int N)
    {
    int magazin;
    cout << " Магазин (0 - Копійка, 1 - АТБ, 2 - Близенько): ";
    cin >> magazin;
        for (int i = 0; i < N; i++)
        {
            if (s[i].magazin == magazin) {
//                cout << "======================================================="
//                    << endl;
//                cout << "| № | Товар |    Магазин    | Вартість | Кількість |"
//                    << endl;
//                cout << "-------------------------------------------------------"
//                    << endl;
                cout << "назва товару - " << setw(2) << s[i].nazva;
                cout << "; номер товару в списку - " << setw(2) << i + 1;
               // cout << "| магазин " << setw(20) << STRmagazin[s[i].magazin];
                cout << "; вартість - " << setw(2) << s[i].vartist << " грн";;
                cout << "; кількість - " << setw(2) << s[i].kilk << " шт.";
                cout << "; одиниці вимірювання - " << setw(2) << s[i].odvim;
                cout << endl;
                //cout << "=======================================================";
            }
        }
    }
void SaveToFile(Tovari* s, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary);
    fout.write((char*)&N, sizeof(N));
    for (int i = 0; i < N; i++)
        fout.write((char*)&s[i], sizeof(Tovari));
    fout.close();
}

void LoadFromFile(Tovari*& s, int& N, const char* filename)
{
    delete[] s;
    ifstream fin(filename, ios::binary);
    fin.read((char*)&N, sizeof(N));
    s = new Tovari[N];
    for (int i = 0; i < N; i++)
        fin.read((char*)&s[i], sizeof(Tovari));
    fin.close();
}

int main()
{

    int N;
    cout << "Введіть кількість товару: "; cin >> N;

   // Magazin magazin;
    Tovari* s = new Tovari[N];
    char filename[100];

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних" << endl;
        cout << " [2] - виведення даних" << endl;
        cout << " [3] - корегування даних" << endl;
        cout << " [4] - сортування даних" << endl;
        cout << " [5] - інформація про товар" << endl;
        cout << " [6] - інформація про магазин" << endl;
        cout << " [7] - запис даних у файл" << endl;
        cout << " [8] - зчитування даних із файлу" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            int num;
            cout << "Корегування (1 - добавлення, 2 - вилучення, 3 - редагування інформації): ";
            cin >> num;
            if (num == 1) {
                s = Add(s, N);
                N++;
                Print(s, N);
            }
            if (num == 2) {
                s = Del(s, &N, 2);
                N--;
                Print(s, N);
            }
            if (num == 3) {
                Edit(s, N);
                Print(s, N);
            }
            break;
        case 4:
            Sort(s, N);
            break;
        case 5:
            Search(s, N);
            break;
        case 6:
            Search2(s,N);
            break;
        case 7:
            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(s, N, filename);
            break;
        case 8:
            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(s, N, filename);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);
    return 0;
}
