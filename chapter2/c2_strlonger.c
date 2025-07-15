#include <stdio.h>
#include <string.h>
//
// Created by yongqi wang on 14/7/2025.
//
// This function is buggy
int strlonger(char *s, char *t) {
	//return strlen(s) - strlen(t) > 0;
	//correct version
	 return strlen(s) > strlen(t);
}

int main(void) {
	char *a = "abc";
	char *b = "abcd";

	int res = strlonger(a, b);
	printf("%d\n", res);
}
