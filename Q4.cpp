#include <iostream>
#include <cstring>
using namespace std;

class StringOps {
public:
    void concat(char s1[], char s2[]) {
        strcat(s1, s2);
        cout << "Concatenated: " << s1 << "\n";
    }

    void reverse(char s[]) {
        int n = strlen(s);
        for (int i = 0; i < n / 2; i++) {
            char t = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = t;
        }
        cout << "Reversed: " << s << "\n";
    }

    void removeVowels(char s[]) {
        char res[100]; int j = 0;
        for (int i = 0; s[i]; i++) {
            if (!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
                  s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'))
                res[j++] = s[i];
        }
        res[j] = '\0';
        cout << "Without vowels: " << res << "\n";
    }

    void sortStrings(char arr[][50], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (strcmp(arr[i], arr[j]) > 0) {
                    char temp[50];
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
        cout << "Sorted strings:\n";
        for (int i = 0; i < n; i++) cout << arr[i] << "\n";
    }

    void toLower(char s[]) {
        for (int i = 0; s[i]; i++)
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        cout << "Lowercase: " << s << "\n";
    }
};

int main() {
    StringOps obj;
    int ch;
    do {
        cout << "\n1.Concat 2.Reverse 3.DeleteVowels 4.SortStrings 5.ToLower 6.Exit\n";
        cin >> ch;
        if (ch == 1) {
            char s1[100], s2[100];
            cin >> s1 >> s2;
            obj.concat(s1, s2);
        } else if (ch == 2) {
            char s[100]; cin >> s; obj.reverse(s);
        } else if (ch == 3) {
            char s[100]; cin >> s; obj.removeVowels(s);
        } else if (ch == 4) {
            int n; cin >> n; char arr[10][50];
            for (int i = 0; i < n; i++) cin >> arr[i];
            obj.sortStrings(arr, n);
        } else if (ch == 5) {
            char s[100]; cin >> s; obj.toLower(s);
        }
    } while (ch != 6);
    return 0;
}
