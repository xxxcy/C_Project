#include "print_test.h"
#include "multiplexing_test.h"
#include "cjson_test.h"

/* 外部函数定义 */
extern int rbt_main();

int main(int argc, char **argv)
{
	printf("Hello, main\n");

	//(void)print_test();
	(void)cjson_test();
	//(void)multiplexing_test();

	/* 红黑树实现定时器 */
	(void)rbt_main();

	return 0;
}
