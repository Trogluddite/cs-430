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
	{ 0x74d1230b, "input_event" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xa3a4cda7, "input_allocate_device" },
	{ 0xaf296a12, "input_register_device" },
	{ 0x96554810, "register_keyboard_notifier" },
	{ 0xce77b302, "input_unregister_device" },
	{ 0x9ed554b3, "unregister_keyboard_notifier" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3eb584cc, "module_layout" },
};

MODULE_INFO(depends, "");

