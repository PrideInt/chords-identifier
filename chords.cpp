#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> getMinorChords();
map<string, string> getMajorChords();

bool isMajor(char key);
bool isMinor(char key);

struct minor;
struct major;

int main() {
    cout << "Enter a key: ";

    string key;

    cin >> key;

    if (isMajor(key[0])) {
        map<string, string> majorChords = getMajorChords();

        cout << majorChords[key] << endl;
    } else if (isMinor(key[0])) {
        map<string, string> minorChords = getMinorChords();

        cout << minorChords[key] << endl;
    } else {
        cout << "Invalid key" << endl;
    }
    return 0;
}

map<string, string> getMinorChords() {
    map<string, string> minorChords;
    minorChords["a"] = "Am Bdim C Dm Em F G";
    minorChords["e"] = "Em F#dim G Am Bm C D";
    minorChords["b"] = "Bm C#dim D Em F#m G A";
    minorChords["f#"] = "F#m G#dim A Bm C#m D E";
    minorChords["c#"] = "C#m D#dim E F#m G#m A B";
    minorChords["g#"] = "G#m A#dim B C#m D#m E F#";
    minorChords["d#"] = "D#m E#dim F# G#m A#m B C#";
    minorChords["a#"] = "A#m B#dim C# D#m E#m F# G#";
    minorChords["d"] = "Dm Edim F Gm Am Bb C";
    minorChords["g"] = "Gm Adim A Cm Dm Eb F";
    minorChords["c"] = "Cm Ddim Eb Fm Gm Ab Bb";
    minorChords["f"] = "Fm Gdim Ab Bbm Cm Db Eb";
    minorChords["bb"] = "Bbm Cdim Db Ebm Fm Gb Ab";
    minorChords["eb"] = "Ebm Fdim Gb Abm Bbm Cb Db";
    minorChords["ab"] = "Abm Bbdim Cb Dbm Ebm Fb Gb";

    return minorChords;
}

map<string, string> getMajorChords() {
    map<string, string> majorChords;
    majorChords["C"] = "C Dm Em F G Am B";
    majorChords["G"] = "G Am Bm C D Em F#";
    majorChords["D"] = "D Em F#m G A Bm C#";
    majorChords["A"] = "A Bm C#m D E F#m G#";
    majorChords["E"] = "E F#m G#m A B C#m D#";
    majorChords["B"] = "B C#m D#m E F# G#m A#";
    majorChords["F#"] = "F# G#m A#m B C# D#m E#";
    majorChords["C#"] = "C# D#m E#m F# G# A#m B#";
    majorChords["F"] = "F Gm Am Bb C Dm E";
    majorChords["Bb"] = "Bb Cm Dm Eb F Gm A";
    majorChords["Eb"] = "Eb Fm Gm Ab Bb Cm D";
    majorChords["Ab"] = "Ab Bbm Cm Db Eb Fm G";
    majorChords["Db"] = "Db Ebm Fm Gb Ab Bbm C";
    majorChords["Gb"] = "Gb Abm Bbm Cb Db Ebm F";
    majorChords["Cb"] = "Cb Dbm Ebm Fb Gb Abm Bb";

    return majorChords;
}

bool isMajor(char key) {
    return key == 'C' || key == 'D' || key == 'E' || key == 'F' || key == 'G' || key == 'A' || key == 'B';
}

bool isMinor(char key) {
    return key == 'a' || key == 'b' || key == 'c' || key == 'd' || key == 'e' || key == 'f' || key == 'g';
}

struct minor {
    string key;
    string i;
    string ii;
    string III;
    string iv;
    string v;
    string VI;
    string VII;

    minor(string key, string i, string ii, string III, string iv, string v, string VI, string VII) {
        this->key = key;
        this->i = i;
        this->ii = ii + "dim";
        this->III = III;
        this->iv = iv;
        this->v = v;
        this->VI = VI;
        this->VII = VII;
    }
};

struct major {
    string key;
    string I;
    string ii;
    string iii;
    string IV;
    string V;
    string vi;
    string vii;

    major(string key, string I, string ii, string iii, string IV, string V, string vi, string vii) {
        this->key = key;
        this->I = I;
        this->ii = ii;
        this->iii = iii;
        this->IV = IV;
        this->V = V;
        this->vi = vi;
        this->vii = vii + "dim";
    }
};