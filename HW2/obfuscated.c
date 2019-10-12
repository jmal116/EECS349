#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* f() {
	// Return the string but in a dumb way
	const int codes[] = {73, 32, 119, 97, 110, 116, 32, 116, 111, 32, 108, 101, 97, 114, 110, 32, 80, 69, 32, 102, 105, 108, 101, 32, 102, 111, 114, 109, 97, 116, 33};
	char thing[sizeof(codes) + 1] = {0};
	int i;
	for (i = 0; i < sizeof(codes); i++) {
		thing[i] = (char)(char*)(codes + i);
	}
	return thing;
}

int main() {
	const char* str = f();
	char buf[100] = {0};
	
	FILE *file = fopen("PE-1.txt", "r+");
	if (!file) {
		file = fopen("PE-1.txt", "w+");
		fwrite(str, sizeof(char), strlen(str), file);
	} else {
		fgets(buf, strlen(str), file);
		if (strcmp(buf, str) == 0) {
			printf("%s", buf);
		} else {
			fwrite(str, sizeof(char), strlen(str), file);
		}
	}
	fclose(file);
}
