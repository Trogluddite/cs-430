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
	{ 0xa916b694, "strnlen" },
	{ 0x9166fada, "strncpy" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x754d539c, "strlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x96554810, "register_keyboard_notifier" },
	{ 0x12583408, "proc_create" },
	{ 0x9ed554b3, "unregister_keyboard_notifier" },
	{ 0x353ac975, "remove_proc_entry" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x69acdf38, "memcpy" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x3eb584cc, "module_layout" },
};

MODULE_INFO(depends, "");

