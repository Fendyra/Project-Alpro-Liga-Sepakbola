#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <algorithm>
#include <iomanip>
using namespace std;

struct LigaSepakbola {
    int Nomor_Tanding, Total_Menang;
    char Nama_Klub[200], Stadion[200];
}; 
LigaSepakbola liga[100];  // Inisialisasi array dengan maksimal 100 data
string FileName; // Deklarasi variabel FileName secara global

void InputData(int TotalData) {
    system("CLS");
    cout << "+===============================================+" << endl;
    cout << "|---------= INPUT DATA LIGA SEPAKBOLA =---------|" << endl;
    cout << "+===============================================+" << endl;
    cout << "hint : (nama file dengan ekstensi 'FileName.txt')" << endl;
    cout << "Masukkan nama file  yang akan dibaca untuk menyimpan data : ";
    cin >> FileName;
    FileName += ".txt";

    cout << "Input data Liga Sepakbola yang diperlukan : ";
    cin >> TotalData;
    cout << "================================================" << endl << endl;
    

    fstream SaveFile(FileName.c_str(), ios::out);
    for (int i = 0; i < TotalData; i++) {
        cout << "----------= DATA LIGA SEPAKBOLA KE-" << i + 1 << " =----------" << endl;
        cout << "Masukkan Nomor Tanding     : ";
        cin >> liga[i].Nomor_Tanding;
        cout << "Masukkan Nama Klub         : ";
        cin.ignore();
        cin.getline(liga[i].Nama_Klub, 200);
        cout << "Masukkan Nama Stadion      : ";
        cin.getline(liga[i].Stadion, 200);
        cout << "Masukkan Total Menang      : ";
        cin >> liga[i].Total_Menang;

        SaveFile << "Nomor Tanding     : " << liga[i].Nomor_Tanding << endl;
        SaveFile << "Nama Klub         : " << liga[i].Nama_Klub << endl;
        SaveFile << "Nama Stadion      : " << liga[i].Stadion << endl;
        SaveFile << "Total Menang      : " << liga[i].Total_Menang << endl;
        cout << endl;
    }
    SaveFile.close();
    cout << "DATA LIGA SEPAKBOLA TELAH BERHASIL TERBUAT DAN TERSIMPAN DALAM FILE '" << FileName << "'";
    getch();
    system("CLS");
}

void AddData(int TotalData) {
    cout << "+================================================+" << endl;
    cout << "|---------= TAMBAH DATA LIGA SEPAKBOLA =---------|" << endl;
    cout << "+================================================+" << endl << endl;
    cout << "hint : (nama file dengan ekstensi 'FileName.txt')" << endl; 
    cout << "Masukkan nama file yang telah dibuat : ";
    cin >> FileName;
    FileName += ".txt";
    cout << "Input tambahan data Liga Sepakbola yang diinginkan : ";
    cin >> TotalData;
    cout << "=================================================" << endl << endl;

    ofstream AppendData(FileName.c_str(), ios::app);
    for (int i = TotalData; i < TotalData + TotalData; i++) {
        cout << "----------= DATA LIGA SEPAKBOLA KE-" << i + 1 << " =----------" << endl;
        cout << "Masukkan Nomor Tanding     : ";
        cin >> liga[i].Nomor_Tanding;
        cout << "Masukkan Nama Klub         : ";
        cin.ignore(); 
        cin.getline(liga[i].Nama_Klub, 200);
        cout << "Masukkan Nama Stadion      : ";
        cin.getline(liga[i].Stadion, 200);
        cout << "Masukkan Total Menang      : ";
        cin >> liga[i].Total_Menang;
        cout << endl;

        AppendData << "Nomor Tanding     : " << liga[i].Nomor_Tanding << endl;
        AppendData << "Nama Klub         : " << liga[i].Nama_Klub << endl;
        AppendData << "Nama Stadion      : " << liga[i].Stadion << endl;
        AppendData << "Total Menang      : " << liga[i].Total_Menang << endl;
        cout << endl;

    }
    AppendData.close();
    TotalData += TotalData;
    cout << "Input tambahan data berhasil tersimpan!";
    getch();
    system("CLS");
}

void ViewData(int TotalData) {
    cout << "+================================================+" << endl;
    cout << "|---------= TAMPIL DATA LIGA SEPAKBOLA =---------|" << endl;
    cout << "+================================================+" << endl << endl;
    cout << "hint : (nama file dengan ekstensi 'FileName.txt)" << endl;
    cout << "Masukkan nama file yang sudah tersedia : ";
    cin >> FileName;
    FileName += ".txt";
    cout << endl;
    
    ifstream View(FileName.c_str(), ios::in);
    if (View.is_open()) {
        cout << "=====> Data dari file " << FileName << " <=====" << endl << endl;
        string line;
        while (getline(View, line)) {
            cout << line << endl;
        }
        View.close();
    } else {
        cout << "File tidak ditemukan atau terjadi kesalahan membuka file." << endl;
    }
    for (int i = 0; i < TotalData; ++i) {
        cout << "----------= DATA LIGA SEPAKBOLA " << "["<< i << "]" << " =----------" << endl;
        cout << "Nomor Tanding      : " << liga[i].Nomor_Tanding << endl;
        cout << "Nama Klub          : " << liga[i].Nama_Klub << endl;
        cout << "Nama Stadion       : " << liga[i].Stadion << endl;
        cout << "Total Menang       : " << liga[i].Total_Menang << endl << endl;
        }
    cout << "Tekan apapun untuk melanjutkan program ini..";
    getch();
    system("CLS");
}

void BubbleSortProcess(int TotalData) {
    // Sorting data liga
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < TotalData - 1; i++) {
            if (liga[i].Nomor_Tanding > liga[i + 1].Nomor_Tanding) {
                swap(liga[i], liga[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void SavetoFile(int TotalData) {    
    cout << "Masukkan nama file untuk menyimpan data (dengan ekstensi .txt): ";
    cin >> FileName;
    FileName += ".txt"; // Menambahkan ekstensi .txt
    
    ofstream SaveFile(FileName.c_str(), ios::out); // Membuka file dengan nama yang dimasukkan pengguna

    if(SaveFile.is_open()) {
        for(int i = 0; i < TotalData; i++) {
            SaveFile << liga[i].Nomor_Tanding << endl;
            SaveFile << liga[i].Nama_Klub << endl;
            SaveFile << liga[i].Stadion << endl;
            SaveFile << liga[i].Total_Menang << endl;
        }
        SaveFile.close();
        cout << "DATA LIGA SEPAKBOLA TELAH BERHASIL TERBUAT DAN TERSIMPAN DALAM FILE '" << FileName << "'"; 
    } else {
        cout << "DATA LIGA SEPAKBOLA GAGAL DIBUKA DAN TERSIMPAN DALAM FILE!";
    }
    cout << endl;
    cout << "Tekan apapun untuk kembali ke sub menu dan melanjutkan program..";
    cin.ignore();
    cin.get();
    system("CLS");
}

void OutputFile(int TotalData) {
    cout << "hint : (nama file dengan ekstensi 'FileName.txt)" << endl;
    cout << "Masukkan nama file yang sudah tersedia : ";
    cin >> FileName;
    FileName += ".txt";
    cout << endl;
    
    ifstream Output(FileName.c_str(), ios::in);
    if (Output.is_open()) {
        cout << "=====> Output atau isi dari data Liga Sepakbola yang tersimpan dalam file " << FileName << " <=====" << endl << endl;
        cout << "+===============================================================+" << endl;
        cout << "|-----------=   OUTPUT FILE DATA Liga SepakBola     =-----------|" << endl;
        cout << "+===============================================================+" << endl;
        cout << "| No. | Nomor Tanding |  Nama Klub  |  Stadion |  Total Menang  |" << endl;
        cout << "+-----+---------------------------------------------------------+" << endl;
        int i = 0;
        while (Output >> liga[i].Nomor_Tanding && i < TotalData) {
            cout << "| " << left << setw(3) << i + 1 << " | " << left << setw(14) << liga[i].Nomor_Tanding << " |" << left << setw(14) << liga[i].Nama_Klub << " |" << left << setw(14) << liga[i].Stadion << " |" << left << setw(14) << liga[i].Total_Menang<< endl;
            i++;
        }
        cout << "+==============================+" << endl;
        Output.close();
    } else {
        cout << "File tidak ditemukan atau terjadi kesalahan membuka file." << endl;
    }
    cout << endl;
    cout << "Tekan apapun untuk melanjutkan program ini..";
    getch();
    system("CLS");
}

void DisplayMenu(int TotalData, int ChoiceMenu) { 
    do {
        system("CLS");
        cout << "--------= APLIKASI DATA LIGA SEPAKBOLA =-------" << endl;
        cout << "+=========================================+" << endl;
        cout << "|               MENU PROGRAM              |" << endl;
        cout << "+=========================================+" << endl;
        cout << "|1. Input Data Liga Sepakbola             |" << endl;
        cout << "|2. Tambah Data Liga Sepakbola            |" << endl;
        cout << "|3. Tampil Data Liga Sepakbola            |" << endl;
        cout << "|4. Sorting Data Liga Sepakbola           |" << endl;
        cout << "|5. Exit Program                          |" << endl;
        cout << "+=========================================+" << endl;
        cout << "Pilih Menu : "; cin >> ChoiceMenu;

        switch (ChoiceMenu) {
            case 1:
                system("CLS");
                InputData(TotalData);
                break;

            case 2:
                system("CLS");
                AddData(TotalData);
                break;

            case 3:
                system("CLS");
                ViewData(TotalData);
                break;

            case 4:
                system("CLS");
                BubbleSortProcess(TotalData);
                OutputFile(TotalData); // Menampilkan data setelah diurutkan
                break;

            case 5:
                system("CLS");
                cout << "Terimakasih telah menggunakan Program";
                getch();
                system("CLS");
                break;
        }
    } while (ChoiceMenu != 5);
}

int main() {
    int ChoiceMenu;
    int TotalData = 0;

    DisplayMenu(TotalData, ChoiceMenu);
    return 0;
}
