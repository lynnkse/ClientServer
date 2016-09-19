#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
    sockAddr.sin_port = htons(53);
    sockAddr.s_addr = htonl(INADDR_ANY);
    
    bind(soc, &sockAddr, sizeof(sockAddr));
    
    recvfrom(soc, buf, 10, 0, &s_other, &len);
    
    printf("Recieved: %s\n", buf);
    
    close(soc);
}
































