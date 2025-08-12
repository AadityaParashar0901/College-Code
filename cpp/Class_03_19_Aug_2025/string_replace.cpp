#include <iostream>
using namespace std;

int main() {
	char string[256], findString[256], replaceString[256];
	char outputString[256];
	int i, o = 0, j, k, foundCount;
	for (i = 0; i < 256; i++) string[i] = 0;
	cout << "Enter a string: "; cin.getline(string, 256);
	cout << "Enter string to find: "; cin.getline(findString, 256);
	cout << "Enter string to replace with: "; cin.getline(replaceString, 256);
	for (i = 0; string[i] != 0; i++) {
		bool foundString = true;
		for (k = 0; findString[k] != 0; k++) {
			if (string[i + k] != findString[k]) {
				foundString = false;
				break;
			}
		}
		if (foundString) {
			foundCount++;
			for (j = 0; replaceString[j] != 0; j++) outputString[o++] = replaceString[j];
			i += --k;
		} else outputString[o++] = string[i];
	}
	outputString[o] = 0;
	cout << "Final string is: " << outputString << endl;
	if (foundCount == 0) cout << "No matches found!\n"; else cout << foundCount << " matches found!\n";
	return 0;
}
