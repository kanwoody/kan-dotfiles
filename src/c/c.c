#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CHARACTER_POOL_SIZE 62
#define DESIRED_PASSWORD_LENGTH 20
#define PASSWORD_BUFFER_SIZE (DESIRED_PASSWORD_LENGTH + 1)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char *generate_password(char *buffer, size_t buffer_size) {
	static const char character_pool[CHARACTER_POOL_SIZE] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
		'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
	};
	if (buffer == NULL) {
		fprintf(stderr, ANSI_COLOR_RED "Err: buffer is NULL" ANSI_COLOR_RESET "\n");
		return NULL;
	}
	if (buffer_size != PASSWORD_BUFFER_SIZE) {
		fprintf(stderr, ANSI_COLOR_RED "Err: incorrect password buffer size." ANSI_COLOR_RESET "\n");
		printf(ANSI_COLOR_CYAN "Expected %d but got %zu" ANSI_COLOR_RESET "\n", PASSWORD_BUFFER_SIZE, buffer_size);
		return NULL;
	}
	for (int x = 0; x < DESIRED_PASSWORD_LENGTH; x++) {
		int index = rand() % CHARACTER_POOL_SIZE;
		buffer[x] = character_pool[index];
	}
	buffer[DESIRED_PASSWORD_LENGTH] = '\0';
	return buffer;

}

int main(void) {
	srand((unsigned int)time(NULL));
	char password_buffer[PASSWORD_BUFFER_SIZE];
	char *generated_password = generate_password(password_buffer, sizeof(password_buffer));
	if (generated_password == NULL) {
		fprintf(stderr, ANSI_COLOR_RED "Err: generated_password is NULL" ANSI_COLOR_RESET "\n");
		return EXIT_FAILURE;
	}
	printf("Generated password: %s\n", generated_password);
	
	return EXIT_SUCCESS;
}
