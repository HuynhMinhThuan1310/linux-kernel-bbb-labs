// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/utsname.h>
#include <linux/ktime.h>        
static char *who = "Master";
module_param(who, charp, 0644);
MODULE_PARM_DESC(who, "Person to greet");

static time64_t start_time;     

static int __init hello_init(void)
{
	start_time = ktime_get_seconds();
	pr_info("Hello %s. You are currently using Linux %s.\n",
		who, utsname()->release);
	return 0;
}

static void __exit hello_exit(void)
{
	time64_t lived = ktime_get_seconds() - start_time;

	pr_info("Goodbye %s! Module lived for %lld seconds.\n",
		who, lived);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thuan");
MODULE_DESCRIPTION("Bootlin Lab 1: Hello Version Module");