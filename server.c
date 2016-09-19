/*   #include <arpa/inet.h>
       #include <netinet/in.h>
       #include <stdio.h>
       #include <sys/types.h>
       #include <sys/socket.h>
       #include <unistd.h>
     
       #define BUFLEN 512
       #define NPACK 10
      #define PORT 1025
    
      void diep(char *s)
      {
        perror(s);
        exit(1);
      }
    
      int main(void)
      {
        struct sockaddr_in si_me, si_other;
        int s, i, slen=sizeof(si_other);
        char buf[BUFLEN];
    
        if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
          diep("socket");
    
        memset((char *) &si_me, 0, sizeof(si_me));
        si_me.sin_family = AF_INET;
        si_me.sin_port = htons(PORT);
        si_me.sin_addr.s_addr = htonl(INADDR_ANY);
        if (bind(s, &si_me, sizeof(si_me))==-1)
            diep("bind");
    
        for (i=0; i<NPACK; i++) {
          if (recvfrom(s, buf, BUFLEN, 0, &si_other, &slen)==-1)
         diep("recvfrom()");
      printf("Received packet from %s:%d\nData: %s\n\n", 
            inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
   }

close(s);
return 0;
}*/

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int soc, len;
	struct sockaddr_in sockAddr, s_other;
	char buf[10];
	
	if((soc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		printf("Socket failed\n");
	}
	
	len = sizeof(s_other);
	
	memset(&sockAddr, 0, sizeof(struct sockaddr));

	sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(1025);
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(soc, (const struct sockaddr *) &sockAddr, sizeof(sockAddr));
    
    recvfrom(soc, buf, 10, 0, (struct sockaddr *) &s_other, (socklen_t *) &len);
    
    printf("Server recieved: %s\n", buf);
    
    sendto(soc, buf, 10, 0, (const struct sockaddr *) &s_other, sizeof(struct sockaddr_in));
    
    close(soc);
    
    return 0;
}
































