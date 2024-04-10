//this is busted

#include <linux/module.h>
#include <linux/input.h>

MODULE_LICENSE("GPL")

int module_init(void){
  struct input_dev *jerry = input_allocate_device();
  // we're passing a pointer to the string here?
  jerry->name = "Mouse move demo"; //this is fine as long as the module is in the kernel

  //leaving out bus-type, vendor, version etc
  //
  set_bit(EV_REL, jerry->evbit);
  set bit(REL_X, jerry-relbit);

  input_register_device(jerry);

  //report where we moved
  // report releative x motion on jerry
  input_report_rel(jerry, REL_X, 100);
  input_sync(jerry);

  return 0;
}

void module_cleanup(){
  input_unregister_device(jerry);
}
