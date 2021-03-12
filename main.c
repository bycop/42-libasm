#include "libasm.h"
#include <fcntl.h>
#include <stdlib.h>

void call_write(void)
{
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. Simple\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %zd\n", write(1, "this is a simple phrase.", 24));
	dprintf(1, "\nFake : %zd\n", ft_write(1, "this is a simple phrase.", 24));
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. Simple with \\n\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %zd\n", write(1, "this is a simple phrase.\n", 25));
	dprintf(1, "\nFake : %zd\n", ft_write(1, "this is a simple phrase.\n", 25));
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

void call_read(void)
{
	char buf[50];
	char buf2[532];
	int fd;
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. 50 characters\n");
	dprintf(1, "---------------------------\n");
	fd = open("example.file", O_RDONLY);
	dprintf(1, "\nReal : %zd\n", read(fd, buf, 50));
	dprintf(1, "%s\n", buf);
	close(fd);
	fd = open("example.file", O_RDONLY);
	dprintf(1, "\nFake : %zd\n", ft_read(fd, buf, 50));
	dprintf(1, "%s\n", buf);
	close(fd);
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. All the file \\n\n");
	dprintf(1, "---------------------------\n");
	fd = open("example.file", O_RDONLY);
	dprintf(1, "\nReal : %zd\n", read(fd, buf2, 532));
	dprintf(1, "%s\n", buf2);
	close(fd);
	fd = open("example.file", O_RDONLY);
	dprintf(1, "\nFake : %zd\n", ft_read(fd, buf2, 532));
	dprintf(1, "%s\n", buf2);
	close(fd);
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

void call_strlen(void)
{
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. Simple\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "Real : %zd\n", strlen("this is a simple phrase."));
	dprintf(1, "Fake : %zd\n", ft_strlen("this is a simple phrase."));
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. Simple with \\n\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "Real : %zd\n", strlen("this is a simple phrase.\n"));
	dprintf(1, "Fake : %zd\n", ft_strlen("this is a simple phrase.\n"));
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

void call_strcmp(void)
{
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. Simple\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %d\n", strcmp("this is a simple phrase.", "this is a simple phrase"));
	dprintf(1, "\nFake : %d\n", ft_strcmp("this is a simple phrase.", "this is a simple phrase"));
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. Simple same\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %d\n", strcmp("Same Phrase", "Same Phrase"));
	dprintf(1, "\nFake : %d\n", ft_strcmp("Same Phrase", "Same Phrase"));
	dprintf(1, "---------------------------\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

void call_strcpy(void)
{
	char dest[50];
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. Simple\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %s\n", strcpy(dest, "this is a simple phrase."));
	dprintf(1, "\nFake : %s\n", ft_strcpy(dest, "this is a simple phrase."));
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. Simple same\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %s\n", strcpy(dest, "Phrase with \t tab."));
	dprintf(1, "\nFake : %s\n", ft_strcpy(dest, "Phrase with \t tab."));
	dprintf(1, "---------------------------\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

void call_strdup(void)
{
	char *dest;
	dprintf(1, "---------------------------\n");
	dprintf(1, "1. Simple\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %s\n", dest = strdup("this is a simple phrase."));
	dprintf(1, "\nFake : %s\n", dest = ft_strdup("this is a simple phrase."));
	dprintf(1, "---------------------------\n");
	dprintf(1, "2. Simple same\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "\nReal : %s\n", dest = strdup("Phrase with \t tab."));
	dprintf(1, "\nFake : %s\n", dest = ft_strdup("Phrase with \t tab."));
	dprintf(1, "---------------------------\n");
	dprintf(1, "---------------------------\n");
	dprintf(1, "END TEST\n");
	dprintf(1, "---------------------------\n");
}

int main()
{
	int choice;
	while (1)
	{
		printf("1. ft_write\n2. ft_read\n3. ft_strlen\n4. ft_strcmp\n5. ft_strcpy\n6. ft_strdup\n");
		scanf("%d", &choice);
		system("clear");
		switch (choice)
		{
		case 1:
			call_write();
			break;
		case 2:
			call_read();
			break;
		case 3:
			call_strlen();
			break;
		case 4:
			call_strcmp();
			break;
		case 5:
			call_strcpy();
			break;
		case 6:
			call_strdup();
			break;
		default:
			printf("\nBad Expression.\n");
			break;
		}
	}
}