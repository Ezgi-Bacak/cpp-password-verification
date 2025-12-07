#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

string hashSifre(const string& sifre) {
    unsigned long hash = 5381;
    for (char c : sifre) {
        hash = ((hash << 5) + hash) + c;
    }
    return to_string(hash);
}

bool sifreDogruMu(const string& girilen, const string& dogruHash) {
    return hashSifre(girilen) == dogruHash;
}

string sifreGiris() {
    string s;
    cout << "Sifreyi giriniz: ";
    cin >> s;
    return s;
}

int main() {
    const string DOGRU_SIFRE_HASH = hashSifre("GucluSifre123!");
    const int MAKS_DENEME = 3;

    for (int deneme = 1; deneme <= MAKS_DENEME; deneme++) {
        string girilen = sifreGiris();

        if (sifreDogruMu(girilen, DOGRU_SIFRE_HASH)) {
            cout << "Giris basarili. Hos geldiniz!" << endl;
            return 0;
        }

        cout << "Hatali sifre. Kalan deneme: "
            << (MAKS_DENEME - deneme) << endl;

        this_thread::sleep_for(chrono::milliseconds(800));
    }

    cout << "Cok fazla hatali deneme. Hesap gecici olarak kilitlendi." << endl;
    return 0;
}
