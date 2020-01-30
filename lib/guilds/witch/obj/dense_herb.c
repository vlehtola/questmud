#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "rose"; s_desc = "A red rose"; l_desc = "A red rose\n"; }
	if(i == 2) { name = "blackberry"; s_desc = "A pile of blackberries"; l_desc = "A pile of blackberries\n"; }
}
