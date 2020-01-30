#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "pine"; s_desc = "A lump of pine needles"; l_desc = "A lump of pine needles\n"; }
	if(i == 2) { name = "dogwood"; s_desc = "A dogwood"; l_desc = "A dogwood\n"; }
}