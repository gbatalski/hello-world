//#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#ifndef DOCKER_IMAGE
	#define DOCKER_IMAGE "hello-world"
#endif

#ifndef DOCKER_GREETING
	#define DOCKER_GREETING "Hello from Docker!"
#endif

const char message[] =
	"\n"
	DOCKER_GREETING "\n"
	"This message shows that your installation appears to be working correctly.\n"
	"\n"
	"To generate this message, Docker took the following steps:\n"
	" 1. The Docker client contacted the Docker daemon.\n"
	" 2. The Docker daemon pulled the \"" DOCKER_IMAGE "\" image from the Docker Hub.\n"
	" 3. The Docker daemon created a new container from that image which runs the\n"
	"    executable that produces the output you are currently reading.\n"
	" 4. The Docker daemon streamed that output to the Docker client, which sent it\n"
	"    to your terminal.\n"
	"\n"
	"To try something more ambitious, you can run an Ubuntu container with:\n"
	" $ docker run -it ubuntu bash\n"
	"\n"
	"Share images, automate workflows, and more with a free Docker Hub account:\n"
	" https://hub.docker.com\n"
	"\n"
	"For more examples and ideas, visit:\n"
	" https://docs.docker.com/engine/userguide/\n"
	"\n";

const struct timespec t[] = {{0, 500000000L}};

int main(int argc, char** argv) {
	//write(1, message, sizeof(message) - 1);
	syscall(SYS_write, 1, message, sizeof(message) - 1);
	if (argc > 1 && argv[1] != NULL){
	while (1){
	 syscall(SYS_nanosleep,t,NULL);
		}
	}
	//_exit(0);
	syscall(SYS_exit, 0);
}
