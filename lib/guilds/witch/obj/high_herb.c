#include "/guilds/witch/obj/herbs.c"
reset(arg) {
  if(arg) return;
  i = random(2)+1;
  set_desc();
}
set_desc() {
	if(i == 1) { name = "buttercup"; s_desc = "A buttercup"; l_desc = "A buttercup\n"; }
	if(i == 2) { name = "foxglove"; s_desc = "A foxglove"; l_desc = "A foxglove\n"; }
}