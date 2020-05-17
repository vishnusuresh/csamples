/* Peek a single register, given an offset into CCSRBAR space. */

/* Kernel includes: */
#include <linux/module.h>
#include <linux/version.h>


extern int printk(const char *fmt, ...);
extern void *ioremap(uint32_t addr, uint32_t numbytes);
extern void iounmap(void * addr);

#ifndef CCSRBAR
#define CCSRBAR ((uint32_t) 0xe0000000)
#endif

int offset = 0;
//MODULE_PARM (offset, "i");
module_param(offset, int, 0);
MODULE_PARM_DESC(offset, "Offset from CCSRBAR to access.  Use 0x prefix for hex if you wish");
int printk_level = 1;
module_param(printk_level, int, 0);
MODULE_PARM_DESC(printk_level, "printk() level to use.  Default is 1, which goes to console as well.");

int init_peekreg(void) {
   volatile uint32_t *regs;
   int temp = 0xdeadbeef /* to signify error */, i;
   uint32_t mask;

   regs = ioremap(CCSRBAR + offset, 0x4);
   if (regs != NULL) {
      temp = *regs;
      iounmap ((void*)regs);
   }
   printk("<%d>Offset %#x holds %0#10x 0b", printk_level, offset, temp);
   // Also print it in binary, with underscores.
   mask=0x80000000;
   for (i=0; i<32; i++) {
      printk("%c", (mask & temp) ? '1':'0');
      if (i < 31 && ((i & 3) == 3)) printk("_");
      if (i == 15) printk("_");
      mask = mask >> 1;
   }
   printk("\n");
   return -1;
}

module_init(init_peekreg);
