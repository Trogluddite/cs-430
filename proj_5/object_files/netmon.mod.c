#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x186bd349, "kmalloc_caches" },
	{ 0x5751b308, "kmalloc_trace" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xe749128b, "init_net" },
	{ 0x6835c86b, "nf_register_net_hook" },
	{ 0x12583408, "proc_create" },
	{ 0xe675d987, "nf_unregister_net_hook" },
	{ 0x353ac975, "remove_proc_entry" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0x37a0cba, "kfree" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x3eb584cc, "module_layout" },
};

MODULE_INFO(depends, "");

