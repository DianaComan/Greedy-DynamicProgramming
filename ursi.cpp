// Copyright 2018 Coman Diana
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Task {
 public:
    void rez() {
        citeste();
        rezolva();
        afiseaza();
    }

 private:
    int v[100000]; int verif; int rezultat; int n; string a;
    // functie de citire
    void citeste() {
        verif = 1;
        ifstream fin("ursi.in");
        int i = 0;
        getline(fin, a);
        for (i = 0; i < a.length(); i++) {
            if (a[i] == '^') {
                v[i+1] = 1;
            } else {
                v[i+1] = 0;
            }
        }
        n = a.length();
        if ((v[1] == 0) || (v[n] == 0)) {verif = 0;}
    }
    // rezolvare
    void rezolva() {
        int n1 = 0; int n2 = 0; int poz, i;
        for (i = 1; i <= n; i++) {
            if (v[i] == 1) {
                n1++;
            } else {
                n2++;
                poz = i;
            }
        }
        // cazul in care avem nr impar de ^
        if ((n1 % 2 == 1) || (verif == 0)) {
            rezultat = 0;
        } else {
        if (n1 % 2 == 0) {
            verif = 1;
            // doar ^^
            if (n2 == 0) {
                rezultat = 1;
                for (i = 1; i <= n1; i++) {
                    if (i % 2 == 1) {
                        rezultat = rezultat * i;
                    }
                }
            } else {
            // un singur _
            if (n2 == 1) {
                int a = n - poz;
                int b = poz - 1;
                rezultat = a * b;
                for (i = 1; i <= n1 - 2; i++) {
                    if (i % 2 == 1) {
                        rezultat = rezultat * i;
                    }
                }
            // doua _
            } else {
                int ok = 0, poz1, poz2;
                for (i = 1; i <= n; i++) {
                    if (ok == 0) {
                        if (v[i] == 0) {
                            poz1 = i; ok = 1;
                        }
                    } else {
                        if (v[i] == 0) {
                            poz2 = i;
                        }
                    }
                }
                rezultat = n1;
            }
            }
            }
        }
    }
    // afisare
    void afiseaza() {
        ofstream fout("ursi.out");
        fout << rezultat;
        fout.close();
    }
};
int main() {
    Task task;
    task.rez();
    return 0;
}
