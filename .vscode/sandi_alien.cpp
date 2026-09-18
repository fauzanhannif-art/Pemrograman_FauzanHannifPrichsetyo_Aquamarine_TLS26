#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Mengubah huruf menjadi nilai posisinya (A=1, ..., Z=26)
int nilaiHuruf(char huruf) {
    return toupper(huruf) - 'A' + 1;
}

// Mengubah nilai posisi menjadi huruf (1=A, ..., 26=Z)
char hurufDariNilai(int nilai) {
    return 'A' + (nilai - 1);
}

// Fungsi untuk menyandikan pesan (bahasa manusia -> sandi alien)
string sandikanPesan(const string &pesanAsli) {
    string hasil = pesanAsli;

    // Ubah semua ke huruf besar dulu supaya perhitungan konsisten
    for (char &c : hasil) c = toupper(c);

    // Huruf pertama tidak berubah (indeks 0 dilewati)
    for (size_t i = 1; i < hasil.size(); i++) {
        int nilaiSebelumnya = nilaiHuruf(hasil[i - 1]);
        int nilaiSekarang   = nilaiHuruf(pesanAsli[i]); // pakai huruf ASLI, bukan hasil sandi
        int nilaiBaru = ((nilaiSekarang - 1 + nilaiSebelumnya) % 26) + 1;
        hasil[i] = hurufDariNilai(nilaiBaru);
    }

    return hasil;
}

// Fungsi untuk membalikkan sandi (sandi alien -> bahasa manusia)
string urungkanSandi(const string &pesanSandi) {
    string asli = pesanSandi;

    // Ubah semua ke huruf besar dulu supaya perhitungan konsisten
    for (char &c : asli) c = toupper(c);

    // Huruf pertama tidak berubah (sama seperti saat menyandikan)
    for (size_t i = 1; i < asli.size(); i++) {
        int nilaiSebelumnyaAsli = nilaiHuruf(asli[i - 1]);      // huruf ASLI sebelumnya (sudah terpecahkan)
        int nilaiSandiSekarang  = nilaiHuruf(pesanSandi[i]);    // huruf sandi saat ini

        // Membalik rumus: nilaiSandi = ((nilaiAsli - 1 + nilaiSebelumnyaAsli) % 26) + 1
        int selisih = (nilaiSandiSekarang - 1 - nilaiSebelumnyaAsli) % 26;
        if (selisih < 0) selisih += 26; // supaya hasil modulo tetap positif di C++
        int nilaiAsli = selisih + 1;

        asli[i] = hurufDariNilai(nilaiAsli);
    }

    return asli;
}

int main() {
    string pesan;
    int pilihan;

    cout << "=== PROGRAM SANDI ALIEN ===" << endl;
    cout << "1. Sandikan pesan (bahasa manusia -> sandi alien)" << endl;
    cout << "2. Urungkan sandi (sandi alien -> bahasa manusia)" << endl;
    cout << "Pilih menu (1/2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "Masukkan pesan asli (huruf saja, tanpa spasi): ";
        cin >> pesan;

        string pesanTersandi = sandikanPesan(pesan);

        cout << "\nPesan asli    : " << pesan << endl;
        cout << "Pesan tersandi: " << pesanTersandi << endl;

    } else if (pilihan == 2) {
        cout << "Masukkan pesan tersandi (huruf saja, tanpa spasi): ";
        cin >> pesan;

        string pesanAsli = urungkanSandi(pesan);

        cout << "\nPesan tersandi: " << pesan << endl;
        cout << "Pesan asli    : " << pesanAsli << endl;

    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}