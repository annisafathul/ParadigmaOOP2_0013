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