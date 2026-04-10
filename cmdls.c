#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void callInfo() {
	printf("\033\[1;36mPower Preference Set As: \033[0m");
	fflush(stdout);
	system("powerprofilesctl get");
}

void errorMissingArg() {
	fprintf(stderr, "\033\[1;37meneset: \033[0m\033\[1;31mRequires Argument:\033[0m Type --help for argument list.\n");
}

void errorInvArg() {
	fprintf(stderr, "\033\[1;37meneset: \033[0m\033\[1;31mInvalid Argument:\033[0m Type --help for argument list.\n");
}

void argList(int argc, char *argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1], "high") == 0) {
			system("powerprofilesctl set performance");
			callInfo();
		} else if (strcmp(argv[1], "low") == 0) {
			system("powerprofilesctl set balanced");
			callInfo();
		} else if ((strcmp(argv[1], "--version") == 0) || (strcmp(argv[1], "-v") == 0)) {
			printf("eneset v0.1\nFree software. Fast power profile management.\n");
		} else if (strcmp(argv[1], "status") == 0) {
			callInfo();
		} else if (strcmp(argv[1], "--help") == 0) {
			printf("\033\[1;37meneset: \033[0m\n\033\[1;32mArgument List:\033[0m\nhigh\nlow\n--version, -v\n--help\n");
		} else {
			errorInvArg();
		}
	} else {
		errorMissingArg();
	}
}
