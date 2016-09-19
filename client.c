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
	
	unsigned char bytes[] = "hahahahaha";
	char buf[10];
	
	/*unsigned char bytes[] = 
	{
		0x5a ,0x76 ,0x01 ,0x00 ,0x00 ,0x01 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x03 ,0x77 ,0x77 ,0x77,
		0x03 ,0x67 ,0x74 ,0x61 ,0x04 ,0x75 ,0x66 ,0x72 ,0x6a ,0x02 ,0x62 ,0x72 ,0x00 ,0x00 ,0x01 ,0x00,
		0x01
	};*/
	
	if((soc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		printf("Socket failed\n");
	}
	
	len = sizeof(s_other);
	
	memset(&sockAddr, 0, sizeof(struct sockaddr));

	sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(1025);
    inet_aton(/*"80.179.52.100"*/"192.168.0.46", &sockAddr.sin_addr);
    	
	sendto(soc, bytes, 10, 0, (const struct sockaddr *) &sockAddr, sizeof(struct sockaddr_in));
	
	recvfrom(soc, buf, 10, 0, (struct sockaddr *) &s_other, (socklen_t *) &len);
	
	printf("Client recieved: %s\n", buf);
	
	close(soc);
	
	return 0;
}


