inherit "room/room";
object rotta;

reset(arg) {

if(!rotta) {
  rotta = clone_object("/wizards/kaappi/dcity/mobs/rat2.c");
  move_object(rotta, this_object()); }

  if(arg) return;

  add_exit("north", "katu46.c");

  short_desc = "A house";
  long_desc = "The ceiling of this house has partially\n"+
              "collapsed. The room smells awful. There are\n"+
              "rotten corpses of rats lying around on the\n"+
              "floor. There is also a badly rotten piece of\n"+
              "meat on the table. You begin to feel sick as\n"+
              "you look at this chaos.\n";

  set_light(1);
}
