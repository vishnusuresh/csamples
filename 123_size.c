/* pg: 123 ECP */

/* Calculating the size of various segments */
/* Optimizing using -O2 will remove almost all uninitialized/unused vars */

void main(int argc, char *argv[]) /* text 5 */
{
	int i;	/* text +3 */
	int j; /* No change */
	int k = 3; /* text +7 */
	int l = 3; /* text +7 */
	int m[100]; /* text +3 */
	int n[100] = {1,}; /* text +42 */
	int o[100] = {1, 2, } ; /* text +42 */
	static int p; /* bss 4 */
	static int q; /* bss +4 */
	static int r = 4; /* data 4 */
	static int s = 4; /* data +4 */
	static int t[100]; /* bss +400 */
	static int u[100] = {1,}; /* data +400 */
}

int g_i; /* No Change */
int g_j = 1; /* data +32 */
int g_k = 1; /* No Change */
