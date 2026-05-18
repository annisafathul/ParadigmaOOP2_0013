#include <iostream>
#include <string>
using namespace std;

class RekeningBank 
{
    protected:
    string namaNasabah;
    double saldo;

    public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo        : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

class RekeningSyariah : public RekeningBank 
{
    public:
    RekeningSyariah(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override 
    {
        cout << "Rekening Syariah tidak dikenakan biaya admin." << endl;
    }

};

class RekeningKonvensional : public RekeningBank 
{
    public:
    RekeningKonvensional(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override 
    {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};

class RekeningPremium : public RekeningBank 
{
    public:
    RekeningPremium(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override 
    {
        if (saldo > 10000000) 
        {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } 
        else 
        {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};

int main() 
{

    RekeningBank* rekening1 = new RekeningSyariah("Annisa", 5000000);
    RekeningBank* rekening2 = new RekeningKonvensional("Gibran", 7000000);
    RekeningBank* rekening3 = new RekeningPremium("Alya", 9000000);
    RekeningBank* rekening4 = new RekeningPremium("Rizky", 15000000);

    cout << "=== Rekening Syariah ===" << endl;
    rekening1->potongAdmin();
    rekening1->tampilkanInfo();

    cout << endl;

    cout << "=== Rekening Konvensional ===" << endl;
    rekening2->potongAdmin();
    rekening2->tampilkanInfo();

    cout << endl;

    cout << "=== Rekening Premium 1 ===" << endl;
    rekening3->potongAdmin();
    rekening3->tampilkanInfo();

    cout << endl;

    cout << "=== Rekening Premium 2 ===" << endl;
    rekening4->potongAdmin();
    rekening4->tampilkanInfo();

    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}