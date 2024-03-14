#include<stdlib.h>
#include<studio.h>

struct string{
  char *data;
  size_t len;
  size_t space;
};

void add(struct string* s, char *addition){
  size_t space_left = space -len;
  size_t addition_len = strlen(addition);

  if(space_left < addition_len)
    s->data = realloc(data, s->len + addition_len);

  strcpy(s->data + len, addition);
  s->len += addition_len;
}

void reserve(struct string* s, )
// oh no I couldn't keep up
