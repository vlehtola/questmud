#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "mud"; s_desc = "A pile of mud"; l_desc = "A pile of mud\n"; }
	if(i == 2) { name = "moss"; s_desc = "A lump of oak moss"; l_desc = "A lump of oak moss\n"; }
}