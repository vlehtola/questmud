#include <ansi.h>

object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
   tell_object(liv, "Entering the shadows...\n");
}
self_destruct() {
destruct(this_object());
}

idle() {
  return 60*6+6;
}

show_age() {
  write("Age: -2s.\n");
}