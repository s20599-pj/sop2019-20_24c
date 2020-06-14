#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>

void error(char *message){
    perror(message);
    exit(0);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int file_name_length;
    int file_size;
    char* file_name;
    char* file_buffer;
    char buffer[256];

    if(argc < 3){
        fprintf(stderr, "port %s jest uzyty\n");
        exit(0);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("Blad otwierania gniazda");
    }
    
    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "Nie ma takiego hosta\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Blad polaczenia");
    }
    printf("Podaj nazwe pliku do pobrania: ");
    bzero(buffer, 256);
    scanf("%s", buffer);
    file_name = buffer;
    //fgets(buffer, 255, stdin);
    file_name_length = strlen(buffer);
    //wysylanie dlugosci nazwy pliku
    write(sockfd, &file_name_length, sizeof(int));
    //wysylanie nazwy pliku
    write(sockfd, buffer, file_name_length);

    read(sockfd, &file_size, sizeof(int));
    if(file_size == -1){
        printf("Nie mozna pobrac pliku\n");
        exit(0);
    }
    file_buffer = (char *)malloc(file_size+1);
    read(sockfd, file_buffer, file_size);
    FILE* file = fopen(file_name, "w");
    if(file == NULL){
        fprintf(stderr, "Nie mozna zapisac pliku\n");
        exit(0);
    }
    else{
        fprintf(file, "%s", file_buffer);
    }
    
    printf("Odebrano plik\n");
    return 0;
}