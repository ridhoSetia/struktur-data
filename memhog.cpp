#include <cstdio>
#include <cstdlib>
#include <unistd.h>
int main(int argc, char** argv) {
	size_t mb = (argc > 1) ? atol(argv[1]) : 250;
	size_t n = mb * 1024 * 1024;
	volatile char* p = (volatile char*)malloc(n);
	if (!p) { perror("malloc"); return 1; }
	for (size_t i = 0; i < n; i += 4096) p[i] = 1;  // tulis
	printf("PID %d: %zu MB terisi.\n", getpid(), mb);
	for (int r = 1; r <= 5; r++) {  // baca ulang
    	sleep(3);
    	long s = 0;
    	for (size_t i = 0; i < n; i += 4096) s += p[i];
    	printf("Putaran %d selesai (%ld)\n", r, s);
	}
	return 0;
}