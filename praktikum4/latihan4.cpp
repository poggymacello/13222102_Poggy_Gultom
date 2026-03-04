#include <iostream>
#include <vector>   // Wajib untuk array dinamis
#include <fstream>  // Wajib untuk akses file (I/O)

int main() {
    // 1. Inisialisasi Struktur Data
    // Membuat vector kosong bertipe double sesuai perintah
    std::vector<double> sensor;

    // 2. Pengisian Data Awal
    // Memasukkan tiga nilai awal menggunakan push_back
    sensor.push_back(100.5);
    sensor.push_back(200.0);
    sensor.push_back(150.5);

    std::cout << "[Sistem] Data awal berhasil dimasukkan ke vector." << std::endl;

    // 3. Proses Kalibrasi (Batch Processing)
    // Menggunakan loop untuk akses dan kalibrasi (naik 10%)
    for (int i = 0; i < sensor.size(); i++) {
        // Setiap elemen dikali 1.1 (sama dengan tambah 10%)
        sensor[i] = sensor[i] * 1.1;
    }
    
    std::cout << "[Sistem] Proses kalibrasi data selesai." << std::endl;

    // 4. Penyimpanan ke File Eksternal
    // Membuat objek ofstream untuk menulis file
    std::ofstream fileOutput("hasil_kalibrasi.txt");

    // Pastikan file berhasil dibuka sebelum lanjut
    if (fileOutput.is_open()) {
        
        // 5. Menulis Hasil ke File
        // Menulis setiap elemen vector ke file per baris
        for (int i = 0; i < sensor.size(); i++) {
            fileOutput << sensor[i] << "\n";
        }

        // 6. Tutup file setelah selesai (Wajib!)
        fileOutput.close();
        
        std::cout << "=> Berhasil! Data kalibrasi disimpan di 'hasil_kalibrasi.txt'" << std::endl;
    } else {
        // Pesan error jika gagal membuat file
        std::cout << "Error: File gagal dibuka atau dibuat!" << std::endl;
    }

    return 0;
}
