#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a = 0, b = 0;
struct premiu {
    int joc;
    int banda;
    premiu (int _joc, int _banda) : joc(_joc), banda(_banda) {}
};

bool comparare(premiu p1, premiu p2) {
    double a, b;
    a = p1.joc + p1.banda;
    b = p2.joc + p2.banda;
    if (a == b) {return (p1.joc > p2.joc);}
    return (a > b);
}

class Task {
public:
    void rez() {
        citeste();
        rezolva();
        afiseaza();
    }
private:
    int n;
    vector<premiu> pr;
    void citeste() {
        ifstream fin("frati.in");
        fin >> n;
        for (int i = 0, joc, banda; i < n; i++) {
            fin >> joc >> banda;
            pr.push_back(premiu(joc, banda));
        }
    }
    void rezolva() {
        sort(pr.begin(), pr.end(), comparare);
        for (int i = 0; i < n; i++) {  
            if ((i != n-1) && ((pr[i].joc + pr[i].banda) == (pr[i+1].joc + pr[i+1].banda))) {
                int j=i;
                while ((pr[j].joc + pr[j].banda) == (pr[j+1].joc + pr[j+1].banda)) {
                    j++;
                }
                int j1; 
                if (((j-i) % 2) == 0) {
                    j1 = (j + i ) / 2 - 1;
                } else {
                    j1 = (j + i) / 2;
                }
                for (int k=i; k<=j1; k++) {
                    a = a + pr[k].joc;
                    b = b + pr[j-(k-i)].banda; 
                }
                if ((j-i + 1) % 2 != 0) { 
                    int k1 = i + (j-i)/2;
                    if (i % 2 == 0) {
                        a = a + pr[k1].joc; 
                    }
                    else {
                        b = b + pr[k1].banda;
                    }
                }
                i = j;
           } else {
                if (i % 2 == 0) {
                    a = a + pr[i].joc;
                }
                else {
                    b = b + pr[i].banda;
                }
            }
            
        }
    }
    void afiseaza() {
        ofstream fout("frati.out");
        fout << a << " " << b;
        fout.close();
    }
};
int main() {
    Task task;
    task.rez();
    return 0;
}
