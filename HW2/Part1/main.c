#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	const char str[] = "I want to learn PE file format!";
	char buf[sizeof(str) + 1] = {0};
	
	FILE *file = fopen("PE-1.txt", "r+");
	if (!file) {
		file = fopen("PE-1.txt", "w+");
		fwrite(str, sizeof(char), strlen(str), file);
	} else {
		fgets(buf, sizeof(str), file);
		if (strcmp(buf, str) == 0) {
			printf("%s", buf);
		} else {
			fwrite(str, sizeof(char), strlen(str), file);
		}
	}
	fclose(file);
}
