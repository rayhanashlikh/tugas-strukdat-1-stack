#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;

struct Paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

Paket kirim[100];

void bersihlayar()
{
    for (int a = 0; a < 80; a++)
    {
        for (int b = 0; b <= 24; b++)
        {
            gotoxy(a, b);
            cout << " ";
        }
    }
}

void tambahdata(int x)
{
    int max = 10;

    if (x <= max)
    {
        gotoxy(20, 14);
        cout << "Data Ke-" << x << endl;
        gotoxy(20, 15);
        cout << "Masukkan Jenis Barang  :";
        cin >> kirim[x].jenis_brg;
        gotoxy(20, 16);
        cout << "Masukkan Berat Barang  :";
        cin >> kirim[x].berat;
        gotoxy(20, 17);
        cout << "Masukkan Kota Tujuan   :";
        cin >> kirim[x].kota;
        x++;
    }
    else
    {
        gotoxy(40, 14);
        cout << "Sorry stack is Full!!" << endl;
        gotoxy(40, 16);
        cout << "Press Any Key To Continue...";
        getch();
    }
}

void tampildata(int x)
{
    if (x > 1)
    {
        gotoxy(40, 10);
        cout << "DAFTAR CONTOH PUSH PADA STACK" << endl;
        for (int a = 1; a < x; a++)
        {
            gotoxy(40, 19 - a);
            cout << a << ". ";
            cout << kirim[a].jenis_brg << " ";
            cout << kirim[a].berat << " ";
            cout << kirim[a].kota << endl;
        }
        gotoxy(40, 20);
        cout << "Press Any Key...";
        getch();
    }
    else
    {
        gotoxy(40, 10);
        cout << "Sorry stack is Empty!!" << endl;
        gotoxy(40, 12);
        cout << "Press Any Key To Continue...";
        getch();
    }
}

void hapusdata(int x)
{
    if (x > 1)
    {
        gotoxy(40, 12);
        cout << "DATA YANG BERHASIL DI POP ADALAH" << endl;
        gotoxy(40, 13);
        cout << kirim[x - 1].jenis_brg << "\t" << kirim[x - 1].berat << "\t" << kirim[x - 1].kota;
        gotoxy(40, 15);
        cout << "Press Any Key To Continue...";
        getch();
    }
    else
    {
        gotoxy(40, 12);
        cout << "Sorry stack is Empty!!" << endl;
        gotoxy(40, 14);
        cout << "Press Any Key To Continue...";
        getch();
    }
}

int main()
{
    // Paket paket[100];

    int pilih;
    int datake = 1; // Index Awal daya yang akan dimasukkan

    do
    {
        bersihlayar();
        gotoxy(1, 1);
        cout << "MENU UTAMA";
        gotoxy(1, 2);
        cout << "1. Push Data";
        gotoxy(1, 3);
        cout << "2. Pop Data";
        gotoxy(1, 4);
        cout << "3. Tampil Data";
        gotoxy(1, 5);
        cout << "9. Keluar";
        gotoxy(1, 7);
        cout << "Pilihan Anda [1-9] : ";
        cin >> pilih;

        if (pilih == 1)
        {
            tambahdata(datake); // Menambah data baru di posisi datake
            datake++;           // Index Data bertambah 1
        }
        else if (pilih == 2)
        {
            hapusdata(datake);
            datake--;
        }
        else if (pilih == 3)
        {
            tampildata(datake);
        }

    } while (pilih != 9);

    return 0;
}
