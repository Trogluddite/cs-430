# Networks
* using IPv4
* suppose we want to block traffice for something -- use DNS server that blocks specific lookups
* for this assignment, track the source IP of each request
# Netmon demo
* netmon.c 
* not sure if AF_INET is a kernel header or something in userspace?
  * socket.h 
  * ip.h, struct iphdr
  * iphdr struct defines __LITTL & __BIG endian
  * compare this struct to the TCP-frame diagram
  * struct sk_buff  sk_buff.h
  * skb_network_header -- sk_buff.h
  * %pi4 flag for printf prints IPv4 address
* failing to de-register the hook will cause the OS to crash when the module is removed
* write to redblack tree
  * rbtree_kbd.c
