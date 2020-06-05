#include <stdio.h>

// ---- Lê input do stdin ----
char * read_input( void );

// ---- Parsing ----
char ** parse_lines( char * commands );

// ---- Manda pra fila ----
int send_to_queue( char ** job_list );