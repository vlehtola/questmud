#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "clover"; s_desc = "A four leaf clover"; l_desc = "A four leaf clover\n"; }
	if(i == 2) { name = "oak"; s_desc = "A tiny branch of oak"; l_desc = "A tiny branch of oak\n"; }
}