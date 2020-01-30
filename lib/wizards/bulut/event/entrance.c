inherit "room/room";

int i;
object clock;

reset(arg) {

  short_desc = "Waiting room";
  long_desc = "This is the waiting room.\n";


  set_not_out(1);               /* Optional, explained previously */
  set_light(3);                 /* Optional, explained previously */


  property = allocate(4);   

  property[0] = "no_kill";
  property[1] = "no_summon";
  property[2] = "no_skill";
  property[3] = "no_spell";

}
init() {
  ::init();

}
