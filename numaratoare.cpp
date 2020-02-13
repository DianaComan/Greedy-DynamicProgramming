// Copyright 2018 Coman Diana
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
        get_result();
		print_output();
	}

 private:
	int n, k, nr, verif;
    int v[70]; int s, rys,  tr;
    // Citirea Datelor
	void read_input() {
		ifstream fin("numaratoare.in");
		fin >> n >> k >> nr;
		fin.close();
	}
	// Functie care verifica daca vectorul are elemente valide: suma lor e n
    bool valid(int k1) {
        int i, s = 0;
        for (i = 1; i <= k; i++) {s = s+v[i];}
        return (s == n);
    }
    // Functie ce calculeaza rezultatul
    void get_result() {
        int j; verif = 0; int i = k; int k1 = -1;
        // primul element ia valoarea maxima posibila
        v[1] = n - k + 1; v[1] = n - k + 1;
        // rys e folosita pentru a determina maximul celui de-al 2 lea element
        rys = 1;
        for (j = 2; j <= k; j++) {
            if (rys > 1) {
                v[j] = rys; rys--;
            } else {
                v[j] = 1;
            }
        }
        tr = tr + 1;
        i = k;
        int k2 = 1;
        // genererea variantelor posibile
        while (v[1] > 1) {
            // in cazul in care vectorul s-a epuizat
            // se genereaza altul cu primele 2 valori "maxime" posibile
            if (i == 1) {
                v[1] = n - k + 1 - tr;
                rys = 1 + tr;
                for (j = 2; j <= k; j++) {
                    if (rys > 1) {
                        v[j] = rys;   rys--;
                    } else {
                        v[j] = 1;
                    }
                }
                tr++;
                i = k;
            }
            // verifica daca e o optiune valida
            if (valid(k1)) {
                k1++;
                if (k1 == nr) {verif = 1; break;}
            }
            // descreste ultima valoroare diferita de 1
            if (v[i] > 1) {
                v[i]--;
            } else  {
                int okk = 1;
                i--;
                while (v[i] == 1) {
                    i--;
                    if (i == 0) {okk == 0;}
                }
                if (okk == 1) {
                    v[i]--;
                    for (j = i+1; j <= k; j++) {
                        v[j] = v[i];
                    }
                    i = k;
                }
            }
            k2++;
        }
    }
    // functie de printare in fisier
    void print_output() {
	    int j;
		ofstream fout("numaratoare.out");
		if (verif == 0) {
		    fout << "-\n";
		} else {
		    fout << n << '=';
		    for (j = 1; j < k; j++) {
		       fout << v[j] << "+";
		    }
		    fout << v[k];
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
