#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cout << "========================================\n";
    cout << " Selamat datang di Program Eliminasi Astronot!\n";
    cout << " Program ini mengeliminasi astronot berdasarkan\n";
    cout << " nilai K sampai tersisa satu astronot.\n";
    cout << "========================================\n\n";
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    if (N < 1 || K < 2) {
        cout << "Input tidak valid. N harus >= 1 dan K >= 2.\n";
        return 0;
    }

    vector<int> circle(N);
    for (int i = 0; i < N; i++) circle[i] = i + 1;

    vector<int> eliminatedOrder;
    int pos = 0; // index tempat hitungan "1" dimulai (awalnya astronot no.1)

    cout << "\n=== Proses Eliminasi ===\n";
    int round = 1;
    while (circle.size() > 1) {
        int size = circle.size();
        int elimIndex = (pos + K - 1) % size;
        int eliminated = circle[elimIndex];

        eliminatedOrder.push_back(eliminated);
        cout << "Ronde " << round << ": K=" << K
             << " -> Astronot #" << eliminated << " dieliminasi. Sisa: ";

        circle.erase(circle.begin() + elimIndex);

        // Update K sesuai aturan
        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        if (K < 2) K = 2;

        // Tentukan posisi mulai hitungan berikutnya
        if (!circle.empty()) {
            pos = elimIndex % circle.size();
        }

        for (int a : circle) cout << a << " ";
        cout << "(K berikutnya=" << K << ")\n";

        round++;
    }

    cout << "\n=== Hasil ===\n";
    cout << "Urutan astronot yang dieliminasi: ";
    for (int a : eliminatedOrder) cout << a << " ";
    cout << "\n";

    cout << "Astronot yang bertahan (selamat): #" << circle[0] << "\n";

    return 0;
}
