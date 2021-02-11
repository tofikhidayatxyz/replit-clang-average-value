#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *in;
	FILE *out;
	char line[200];
	char outFile[200] = {};
	// read file
	if (!(in = fopen("./data.txt", "r"))) {
		printf("Canot read the file \n");
	} else {
		while (!feof(in)) {
			fgets(line, sizeof(line), in);
			char *lineData = strtok(line, " ");
			int loopIndex = 0;
			char *lineArray[3];
			while (lineData != NULL) {
				if (lineData != NULL) {
					lineArray[loopIndex] = lineData;
					loopIndex++;
				}
				lineData = strtok(NULL, " ");
			}
			float sumData = (atof(lineArray[1]) * 40 / 100) + (atof(lineArray[2]) * 60 / 100);
      sprintf(outFile, "%s %s %.2f\n", (outFile[0] ? outFile : ""), lineArray[0], sumData);
		}
	}
	fclose(in);
	// write file
	if (!(out = fopen("out.txt", "w"))) {
		printf("Canot write the file\n");
	} else {
		fprintf(out, "%s", outFile);
	}
	fclose(out);
	printf("Process has done :)");
	return 0;
}