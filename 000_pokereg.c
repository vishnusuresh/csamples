/* Poke a single register, given an offset into CCSRBAR space. */

/* Kernel includes: */
#include <linux/module.h>

extern int printk(const char *fmt, ...);
extern void *ioremap(uint32_t addr, uint32_t numbytes);
extern void iounmap(void *addr);

#ifndef CCSRBAR
#define CCSRBAR ((uint32_t) 0xe0000000)
#endif

//MODULE_PARM (offset, "i");
//MODULE_PARM (value, "i");
int offset = 0;
module_param(offset, int, 0);
MODULE_PARM_DESC(offset, "Offset from CCSRBAR to access.  Use 0x prefix for hex if you wish");

int value = 0;
module_param(value, int, 0);
MODULE_PARM_DESC(value, "Value to poke into the specified region.  Use 0x prefix for hex if you wish");

int printk_level = 1;
module_param(printk_level, int, 0);
MODULE_PARM_DESC(printk_level, "printk() level to use.  Default is 1, which goes to console as well.");

int init_module(void) {
   volatile uint32_t *regs;

   regs = ioremap(CCSRBAR + offset, 0x4);
   *regs = value;
   if (regs != NULL) iounmap ((void*)regs);
   printk("<%d>Offset %#x written with %#x\n", printk_level, offset, value);
   return -1;
}
