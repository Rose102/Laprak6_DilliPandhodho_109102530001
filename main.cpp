
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P, Prec, Hapus, Cari;
    char ulang;

    CreateList(L);

    // Input data kendaraan
    do {
        cout << "Masukkan nomor polisi : ";
        cin >> x.nopol;

        // Memeriksa nomor polisi yang sudah terdaftar
        Cari = findElm(L, x);

        if (Cari != nullptr) {
            cout << "Nomor polisi sudah terdaftar!" << endl;
        } else {
            cout << "Masukkan warna kendaraan : ";
            cin >> x.warna;

            cout << "Masukkan tahun kendaraan : ";
            cin >> x.thnBuat;

            P = alokasi(x);
            insertLast(L, P);
        }

        cout << "\nTambah data lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    // Menampilkan seluruh data
    printInfo(L);

    // Mencari kendaraan berdasarkan nomor polisi
    cout << "\nMasukkan nomor polisi yang dicari : ";
    cin >> x.nopol;

    Cari = findElm(L, x);

    if (Cari != nullptr) {
        cout << "\nData kendaraan ditemukan." << endl;
        cout << "Nomor Polisi : " << Cari->info.nopol << endl;
        cout << "Warna        : " << Cari->info.warna << endl;
        cout << "Tahun        : " << Cari->info.thnBuat << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    // Menghapus kendaraan berdasarkan nomor polisi
    cout << "\nMasukkan nomor polisi yang akan dihapus : ";
    cin >> x.nopol;

    Cari = findElm(L, x);

    if (Cari == nullptr) {
        cout << "Data kendaraan tidak ditemukan." << endl;
    } else {
        if (Cari == L.First) {
            deleteFirst(L, Hapus);
        } else if (Cari == L.Last) {
            deleteLast(L, Hapus);
        } else {
            Prec = Cari->prev;
            deleteAfter(L, Prec, Hapus);
        }

        dealokasi(Hapus);
        cout << "Data dengan nomor polisi "
             << x.nopol << " berhasil dihapus." << endl;
    }

    // Menampilkan data setelah penghapusan
    printInfo(L);

    // Menghapus semua sisa elemen agar memori dibebaskan
    while (L.First != nullptr) {
        deleteFirst(L, Hapus);
        dealokasi(Hapus);
    }

    return 0;
}
