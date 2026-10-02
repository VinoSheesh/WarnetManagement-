#include <iostream>
using namespace std;

struct customer
{
    string name;
    bool isRent;
    int pcId;
};

int main()
{
    int pilihan;
    string back;

    // list nama pc
    string namePc[4] = {"PC-01", "PC-02", "PC-03", "PC-04"};

    // ketika true artinya pc tersedia
    bool statusPc[4] = {true, false, true, false};
    do
    {
        cout << endl;
        cout << "==== MENU MANAJEMEN WARNET ====" << endl;
        cout << "== 1. Cek Daftar PC Tersedia ==" << endl;
        cout << "===============================" << endl;

        cout << "pilih menu (1-5) = ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1)
        {
            for (int i = 0; i < 4; i++)
            {

                cout << namePc[i];
                cout << " - ";
                for (int j = 0; j < 1; j++)
                {
                    if (statusPc[i] == true)
                    {
                        cout << "tersedia";
                    }
                    else
                    {
                        cout << "tidak tersedia";
                    }
                }
                cout << endl;
            }
            cout << endl;
            cout << "lanjut? (Y) = ";
            cin >> back;
        }
        else
        {
            cout << "pilihan tidak tersedia !" << endl;
            cout << "ingin kembali ke menu awal? (Y/N) = ";
            cin >> back;
        }
    } while (back == "Y" || back == "y");
    cout << "terimakasih telah menggunakan layanan kami!";
    return 0;

    // customer cst1;

    // cst1.name = "Zidan";
    // cst1.isRent = true;
    // cst1.pcId = 1;

    // cout << cst1.name << "\n";
    // cout << cst1.isRent << "\n";
    // cout << cst1.pcId << "\n";
    return 0;
}