#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int block;
	int pos;
	int c;
	int offset;
	int address;
	int blockSize = 11;
	
	struct ram_Buffer{
		char page[11];
	}*ram;
	
	ram = malloc(sizeof(struct ram_Buffer));
	
	FILE *fp;
	const char filename[] = "ram_file";
	fp = fopen(filename, "r+");
	
	printf("enter an address from 0 to 99\n");
	scanf("%i", &address);
	printf("address is %i\n", address);//debug
	block = (address/10)+1;
	printf("block is %i\n", block);//debug
	offset = address % 10; 
	printf("offset is %i\n", offset);//debug
	fseek(fp, (blockSize*(block-1)), SEEK_SET);
	fgets(ram->page, blockSize,fp);
	
	printf("enter a character to insert into ram\n");
	scanf("%s", &c);
	printf("%c\n", c);
	printf("%s\n", ram->page);
	ram->page[offset] = c;
	printf("%s\n", ram->page);
	printf("%c\n", ram->page[offset]);
	fseek(fp, (blockSize*(block-1)), SEEK_SET);
	fputs(ram->page, fp);
	fclose(fp);
	free(ram);
	
	return (0);
}
