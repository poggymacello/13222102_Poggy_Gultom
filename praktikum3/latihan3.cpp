#include <iostream>
#include <iomanip>

class RekeningBank {
private:
    double saldo;

public:
    // Constructor tetap ada untuk inisialisasi awal
    RekeningBank(double saldoAwal) {
        if (saldoAwal < 0) {
            saldo = 0;
        } else {
            saldo = saldoAwal;
        }
        std::cout << "[Sistem] Rekening berhasil diproses." << std::endl;
    }

    void setor(double jumlah) {
        if (jumlah > 0) {
            saldo += jumlah;
            std::cout << ">> Setor Tunai Berhasil. Saldo sekarang: " << saldo << std::endl;
        } else {
            std::cout << ">> Jumlah tidak valid!" << std::endl;
        }
    }

    void tarik(double jumlah) {
        std::cout << "Memproses penarikan: " << jumlah << "..." << std::endl;
        
        // Logika if-else sesuai perintah tugas
        if (jumlah > saldo) {
            std::cout << ">> Penarikan Gagal! Saldo tidak mencukupi." << std::endl;
        } else {
            saldo -= jumlah;
            std::cout << ">> Berhasil! Sisa saldo saat ini: " << saldo << std::endl;
        }
    }

    void cekSaldo() {
        std::cout << "\n=== STATUS REKENING ===" << std::endl;
        std::cout << "Total Saldo Akhir: " << saldo << std::endl;
        std::cout << "=======================" << std::endl;
    }
};

int main() {
    double awal, nSetor, nTarik;

    std::cout << "--- Aplikasi Bank Mini ---" << std::endl;
    
    // Input saldo awal untuk dikirim ke Constructor
    std::cout << "Masukkan saldo awal: ";
    std::cin >> awal;
    RekeningBank tabunganku(awal);

    // Input untuk method setor
    std::cout << "\nMasukkan jumlah setoran: ";
    std::cin >> nSetor;
    tabunganku.setor(nSetor);

    // Input untuk method tarik
    std::cout << "Masukkan jumlah penarikan: ";
    std::cin >> nTarik;
    tabunganku.tarik(nTarik);

    // Tampilkan hasil akhir
    tabunganku.cekSaldo();

    return 0;
}
