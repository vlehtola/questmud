#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "chives"; s_desc = "A bundle of chives"; l_desc = "A bundle of chives\n"; }
	if(i == 2) { name = "ginger"; s_desc = "A small root of ginger"; l_desc = "A small root of ginger\n"; }
}