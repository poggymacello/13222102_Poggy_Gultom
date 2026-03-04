#include <iostream>
#include <string>

// Mendefinisikan Class sesuai spesifikasi tugas
class RekeningBank {
private:
    // Atribut diset private agar saldo tidak bisa diubah langsung dari luar (Enkapsulasi)
    double saldo;

public:
    // Constructor: Otomatis jalan pas objek dibuat buat isi saldo awal
    RekeningBank(double saldoAwal) {
        if (saldoAwal < 0) {
            saldo = 0; // Proteksi kalau input awal minus
        } else {
            saldo = saldoAwal;
        }
        std::cout << "[Sistem] Akun dibuat. Saldo awal: " << saldo << std::endl;
    }

    // Method untuk menambah saldo
    void setor(double jumlah) {
        if (jumlah > 0) {
            saldo += jumlah;
            std::cout << "Setor tunai: " << jumlah << " | Total saldo: " << saldo << std::endl;
        } else {
            std::cout << "Jumlah setor tidak valid!" << std::endl;
        }
    }

    // Method untuk menarik saldo dengan logika pengecekan
    void tarik(double jumlah) {
        std::cout << "Mencoba tarik: " << jumlah << "..." << std::endl;
        
        // Logika kondisi if-else sesuai perintah tugas
        if (jumlah > saldo) {
            std::cout << ">> Penarikan Gagal! Saldo tidak mencukupi." << std::endl;
        } else if (jumlah <= 0) {
            std::cout << ">> Penarikan Gagal! Nominal tidak valid." << std::endl;
        } else {
            saldo -= jumlah;
            std::cout << ">> Berhasil! Sisa saldo saat ini: " << saldo << std::endl;
        }
    }

    // Method tambahan buat cek saldo terakhir
    void cekSaldo() {
        std::cout << "Saldo saat ini: " << saldo << std::endl;
    }
};

int main() {
    // 1. Inisialisasi objek dengan saldo awal 500.0
    RekeningBank tabunganku(500.0);

    // 2. Coba setor uang
    tabunganku.setor(200.0);

    // 3. Tes logika penarikan yang melebihi saldo (Harus gagal)
    tabunganku.tarik(1000.0);

    // 4. Tes penarikan yang valid
    tabunganku.tarik(300.5);

    // 5. Cek hasil akhir
    std::cout << "\n--- Laporan Akhir ---" << std::endl;
    tabunganku.cekSaldo();

    return 0;
}
