// Implement your part 1 solution here
// gcc vfork.c -o vfork
//debug on going that no paint out yet...

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int colors[64][64 * 3];
int workID = 0;// Modify your paint function here

void paint() {
	printf("Artist %d is painting\n", workID);
}

int main(int argc, char** argv) {

	int numberOfArtists = 64 ; // How many child processes do we want?

	pid_t pid;
	// main loop where we fork new threads
	for (int i = 0; i < numberOfArtists; i++) {
		// (1) Perform a fork
		pid = fork();

			// (2) Make only the child do some work (i.e. paint) and then terminate.
			if (pid == 0 ) {
				colors[workID][i] = workID; // Try doing something more interesting with the colors!// TODO: make child paint
				return 0;// TODO: Then terminate/exit child
			}
	}

	printf("parent is exiting(last artist out!)\n");

	return 0;
}
