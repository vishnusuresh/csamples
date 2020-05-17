//#include <stdio.h>

void hexdump(void *data, unsigned int len)
{
	unsigned int i;
	char *ptr = (char *)data;

	for (i = 0; i < len; i++) { 
			printk("%02x ", ptr[i]);
			if (!((i + 1)%6))
				printk("\n");
	}

	return;
}

int main(int argc, char *argv[])
{
	register char *ptr asm("r1");
	char arr[] = {0x04, 0x50, 'a', 'b', 'A', 'C', '0', '9'};

	printk("\n Sizeof Arr is: %d\n",sizeof(arr));
	hexdump(arr, sizeof(arr));

	printk("Stack is:\n");
	hexdump(ptr, 10);
	printk("\n");

	return 0;
}

