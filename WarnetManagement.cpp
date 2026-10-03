#include <iostream>
using namespace std;

struct Komputer {
    string nama;
    bool digunakan;
    string pelanggan;
    int durasi;
};

// Menampilkan daftar komputer
void daftarKomputer(Komputer pc[], int jumlah) {

    cout << "\n--- DAFTAR KOMPUTER ---\n";

    for (int i = 0; i < jumlah; i++) {

        cout << i + 1 << ". " << pc[i].nama << " - ";

        if (pc[i].digunakan) {
            cout << "Digunakan";
        } else {
            cout << "Tersedia";
        }

        cout << endl;
    }
}

// Memulai penggunaan komputer
void mulai(Komputer pc[], int jumlah) {

    int pilihan;

    daftarKomputer(pc, jumlah);

    cout << "\nPilih PC: ";
    cin >> pilihan;
    pilihan--;

    if (pilihan < 0 || pilihan >= jumlah) {
        cout << "PC tidak tersedia.\n";
        return;
    }

    if (pc[pilihan].digunakan) {
        cout << "PC sedang digunakan.\n";
        return;
    }

    cout << "Nama pelanggan: ";
    cin >> pc[pilihan].pelanggan;

    cout << "Durasi (jam): ";
    cin >> pc[pilihan].durasi;

    pc[pilihan].digunakan = true;

    cout << "\nPenggunaan dimulai.\n";
}

// Mengakhiri penggunaan komputer
int selesai(Komputer pc[], int jumlah) {

    int pilihan;
    int harga = 5000;

    daftarKomputer(pc, jumlah);

    cout << "\nPilih PC: ";
    cin >> pilihan;
    pilihan--;

    if (pilihan < 0 || pilihan >= jumlah) {
        cout << "PC tidak tersedia.\n";
        return 0;
    }

    if (!pc[pilihan].digunakan) {
        cout << "PC tidak sedang digunakan.\n";
        return 0;
    }

    int total = pc[pilihan].durasi * harga;

    cout << "\n--- PEMBAYARAN ---\n";
    cout << "Pelanggan : " << pc[pilihan].pelanggan << endl;
    cout << "Durasi    : " << pc[pilihan].durasi << " jam\n";
    cout << "Total     : Rp" << total << endl;

    pc[pilihan].digunakan = false;

    return total;
}

// Menampilkan pelanggan yang sedang menggunakan PC
void pelanggan(Komputer pc[], int jumlah) {

    cout << "\n--- PELANGGAN AKTIF ---\n";

    bool ada = false;

    for (int i = 0; i < jumlah; i++) {

        if (pc[i].digunakan) {

            int total = pc[i].durasi * 5000;

            cout << pc[i].nama
                 << " | " << pc[i].pelanggan
                 << " | " << pc[i].durasi << " jam"
                 << " | Rp" << total << endl;

            ada = true;
        }
    }

    if (!ada) {
        cout << "Tidak ada pelanggan aktif.\n";
    }
}

int main() {

    const int jumlahPC = 5;

    Komputer pc[jumlahPC] = {
        {"PC-01", false, "", 0},
        {"PC-02", false, "", 0},
        {"PC-03", false, "", 0},
        {"PC-04", false, "", 0},
        {"PC-05", false, "", 0}
    };

    int pilihan;
    int pendapatan = 0;
    char lanjut;

    while (true) {

        cout << "\n===== WARNET =====\n";
        cout << "1. Daftar PC\n";
        cout << "2. Mulai Pakai\n";
        cout << "3. Selesai Pakai\n";
        cout << "4. Pelanggan Aktif\n";
        cout << "5. Pendapatan\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {

            daftarKomputer(pc, jumlahPC);

        }
        else if (pilihan == 2) {

            mulai(pc, jumlahPC);

        }
        else if (pilihan == 3) {

            pendapatan += selesai(pc, jumlahPC);

        }
        else if (pilihan == 4) {

            pelanggan(pc, jumlahPC);

        }
        else if (pilihan == 5) {

            cout << "\nPendapatan: Rp" << pendapatan << endl;

        }
        else if (pilihan == 6) {

            cout << "\nProgram selesai.\n";
            break;

        }
        else {

            cout << "Pilihan tidak tersedia.\n";
        }

        // Pilihan setelah menjalankan menu
        cout << "\nKembali ke menu? (y/n): ";
        cin >> lanjut;

        if (lanjut == 'n' || lanjut == 'N') {
            cout << "Program selesai.\n";
            break;
        }
    }

    return 0;
}