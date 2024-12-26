#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

map<string, string> getMinorChords();
map<string, string> getMajorChords();

vector<string> split(string str, char delimiter);

string getUppercaseNote(string note);

bool isMajor(char key);
bool isMinor(char key);

struct stringbuilder;
struct scale;

struct stringbuilder {
    string str;

    stringbuilder() {
        str = "";
    }

    stringbuilder(string str) {
        this->str = str;
    }

    stringbuilder append(string str) {
        this->str += str;
        return *this;
    }

    stringbuilder append(char c) {
        this->str += c;
        return *this;
    }

    string toString() {
        return str;
    }
};

struct scale {
    bool isMajor;
    string key;
    string i;
    string ii;
    string iii;
    string iv;
    string v;
    string vi;
    string vii;

    scale(string key, string i, string ii, string iii, string iv, string v, string vi, string vii) {
        this->key = key;
        this->i = i;
        this->ii = ii;
        this->iii = iii;
        this->iv = iv;
        this->v = v;
        this->vi = vi;
        this->vii = vii;
    }

    scale isMajorScale(bool isMajor) {
        this->isMajor = isMajor;
        return *this;
    }

    scale init() {
        if (isMajor) {
            return scale(key, getUppercaseNote(i), ii, iii, getUppercaseNote(iv), getUppercaseNote(v), vi, vii + "dim");
        } else {
            return scale(key, i, ii + "dim", getUppercaseNote(iii), iv, v, getUppercaseNote(vi), getUppercaseNote(vii));
        }
        return *this;
    }
};

int main() {
    cout << "\n\n\n\n\n";
    cout << "Enter a key: ";

    string key;

    cin >> key;

    bool isMajorKey = isMajor(key[0]);
    map<string, string> keyChords;

    if (isMajorKey) {
        keyChords = getMajorChords();
    } else {
        keyChords = getMinorChords();
    }
    vector<string> chords = split(keyChords[key], ' ');

    scale s(key, chords[0], chords[1], chords[2], chords[3], chords[4], chords[5], chords[6]);
    s = s.isMajorScale(isMajorKey);
    s = s.init();

    cout << s.i + " " + s.ii + " " + s.iii + " " + s.iv + " " + s.v + " " + s.vi + " " + s.vii + "\n";

    cout << "\n\n\n\n\n";
    return 0;
}

map<string, string> getMinorChords() {
    map<string, string> minorChords;
    minorChords["a"] = "a b c d e f g";
    minorChords["e"] = "e f# g a b c d";
    minorChords["b"] = "b c# d e f# g a";
    minorChords["f#"] = "f# g# a b c# d e";
    minorChords["c#"] = "c# d# e f# g# a b";
    minorChords["g#"] = "g# a# b c# d# e f#";
    minorChords["d#"] = "d# e# f# g# a# b c#";
    minorChords["a#"] = "a# b# c# d# e# f# g#";
    minorChords["d"] = "d e f g a bb c";
    minorChords["g"] = "g a a c d eb f";
    minorChords["c"] = "c d eb f g ab bb";
    minorChords["f"] = "f g ab bb c db eb";
    minorChords["bb"] = "eb c db eb f gb ab";
    minorChords["eb"] = "eb f gb ab bb cb db";
    minorChords["ab"] = "ab bb cb db eb fb gb";

    return minorChords;
}

map<string, string> getMajorChords() {
    map<string, string> majorChords;

    majorChords["A"] = "a b c# d e f# g#";
    majorChords["E"] = "e f# g# a b c# d#";
    majorChords["B"] = "b c# d# e f# g# a#";
    majorChords["F#"] = "f# g# a# b c# d# e#";
    majorChords["C#"] = "c# d# e# f# g# a# b#";
    majorChords["G#"] = "g# a# b# c# d# e# f##";
    majorChords["D#"] = "d# e# f## g# a# b# c##";
    majorChords["A#"] = "a# b# c## d# e# f## g##";
    majorChords["D"] = "d e f# g a b c#";
    majorChords["G"] = "g a b c d e f#";
    majorChords["C"] = "c d e f g a b";
    majorChords["F"] = "f g a bb c d e";
    majorChords["Bb"] = "bb c d eb f g a";
    majorChords["Eb"] = "eb f g ab bb c d";
    majorChords["Ab"] = "ab bb c db eb f g";

    return majorChords;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream stream(str);
    string token;

    while (getline(stream, token, delimiter)) {
        internal.push_back(token);
    }
    return internal;
}

string getUppercaseNote(string note) {
    stringbuilder builder("");
    builder.append(toupper(note[0]));
    builder.append(note.substr(1));

    return builder.toString();
}

bool isMajor(char key) {
    return key == 'C' || key == 'D' || key == 'E' || key == 'F' || key == 'G' || key == 'A' || key == 'B';
}

bool isMinor(char key) {
    return key == 'a' || key == 'b' || key == 'c' || key == 'd' || key == 'e' || key == 'f' || key == 'g';
}