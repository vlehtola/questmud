inherit "room/room";

reset(mixed arg) {
  if(arg) return;
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}

init() {
  if(this_player()->query_npc())
   destruct(this_player());
  ::init();
}

long() {
    write("The ld room. If you find yourself here," +
	" please report to a wizard.\n");
}

