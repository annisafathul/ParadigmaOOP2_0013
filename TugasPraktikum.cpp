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

};