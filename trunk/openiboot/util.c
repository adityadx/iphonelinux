#include "openiboot.h"
#include "uart.h"

void* memset(void* x, int fill, uint32_t size) {
	uint32_t i;
	for(i = 0; i < size; i++) {
		((uint8_t*)x)[i] = (uint8_t) fill;
	}
	return x;
}

void* memcpy(void* dest, const void* src, uint32_t size) {
	uint32_t i;
	for(i = 0; i < size; i++) {
		((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
	}
	return dest;
}

int strlen(const char* str) {
	int ret = 0;
	while(*str != '\0') {
		++str;
		++ret;
	}
	return ret;
}

int putchar(int c) {
	char ch = (char) c;
	if(uart_write(0, &ch, 1) == 0)
		return c;
	else
		return -1;
}

int puts(const char *str) {
	uart_write(0, str, strlen(str));
	return 0;
}

