#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void callInfo() {
	printf("\033\[1;36mPower Preference Set As: \033[0m");
	fflush(stdout);
	system("powerprofilesctl get");
}

int main(int argc, char *argv[]) {

	if (argc > 1) {
		if (strcmp(argv[1], "high") == 0) {
			system("powerprofilesctl set performance");
			callInfo();
		} else if (strcmp(argv[1], "low") == 0) {
			system("powerprofilesctl set balanced");
			callInfo();
		} else if (strcmp(argv[1], "--version") == 0) {
			printf("eneset v0.1\nFree software. Fast power profile management.\n");
		}
	} else {
		fprintf(stderr, "\033\[1;31mRequires Argument:\033[0m high, low\n");
		callInfo();
	}
	return 0;
}
