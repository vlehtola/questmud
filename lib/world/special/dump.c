/* this room is used for moving mobs / stuff here and desting it so that 
   stuff that might drop is unavailable to players */

inherit "room/room";

reset(mixed arg) {
  if(arg) return;
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}

short() { return "dump"; }

long() {
    write("The dump room. If you find yourself here," +
	" please report to a wizard.\n");
}

