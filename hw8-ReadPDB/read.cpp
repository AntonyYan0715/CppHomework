#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//        Atom_No.  Atom_name  Residue_name    Residue_No.         Position                      Atom_class
// ATOM      1         N           MET      I     20       -10.466  35.714   7.911  0.50 34.27       N
// ATOM      2        CA           MET      I     20       -10.571  34.318   8.221  0.50 33.85       C

void preProcess() {
    ifstream fr("1COA.pdb");
    ofstream fw("pre.dat");
    string line;

    while (getline(fr, line)) {
        string Atom, Atom_name, Residue_name, I, Atom_class;
        double x, y, z, a, b;
        int Atom_No, Residue_No;

        istringstream is(line);
        is >> Atom >> Atom_No >> Atom_name >> Residue_name >> I >> Residue_No >> x >> y >> z >> a >> b >> Atom_class;
        if (Atom == "ATOM") {
            fw << Atom_name << "\t" << Residue_name << "\t" << Residue_No << "\t"\
            << x << "\t" << y << "\t" << z << "\t" << Atom_class << endl;
        }
    }
}

void getResidue() {
    ofstream fw("result.dat");
    string line;

    // Residue No. from 20 to 83
    for (int i=20; i<84; ++i) {
        ifstream fr("pre.dat");
        string name;
        double X, Y, Z;
        int ID, mass=0;
        while (getline(fr, line)) {
            string Atom_name, Residue_name, Atom_class;
            double x, y, z;
            int Residue_No;

            istringstream is(line);
            is >> Atom_name >> Residue_name >> Residue_No >> x >> y >> z >> Atom_class;
            if (Residue_No == i) {
                name = Residue_name;
                ID = i;

                if (Atom_name == "CA") {
                    X = x;
                    Y = y;
                    Z = z;
                }

                if (Atom_class == "C")
                mass += 12;
                else if (Atom_class == "N")
                mass += 14;
                else if (Atom_class == "O")
                mass += 16;
                else if (Atom_class == "S")
                mass += 32;
            }
        }
        fw << "ATOM" << "\t" << name << "\t" << ID << "\t" << mass << "\t" << X << "\t" << Y << "\t" << Z << endl;
        fr.close();
    }
}

void harmonic() {
    ofstream fw("har.dat");
    string line;

    for (int i=20; i<83; ++i) {
        ifstream fr("result.dat");
        int ID1, ID2;
        double d, x1, y1, z1, x2, y2, z2;
        while (getline(fr, line)) {
            string Atom, name;
            int ID, mass;
            double x, y, z;

            istringstream is(line);
            is >> Atom >> name >> ID >> mass >> x >> y >> z;
            if (ID == i) {
                x1 = x;
                y1 = y;
                z1 = z;
                ID1 = ID;
            }

            if (ID == i+1) {
                x2 = x;
                y2 = y;
                z2 = z;
                ID2 = ID;
            } 
        }
        d = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) + (z2-z1) * (z2-z1));
        fw << "HAR" << "\t" << ID1 << "\t" << ID2 << "\t" << 100 << "\t" << d << endl;
    }
}

int main() {
    preProcess();  // Get rid of unnecessary information -> pre.dat
    getResidue();  // Get all residues -> result.dat
    harmonic();    // Harmonic potential -> har.dat
    return 0;
}