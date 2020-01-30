inherit "room/room";
object eukko;

reset(arg) {

if(!eukko) {
  eukko = clone_object("/wizards/kaappi/dcity/mobs/eukko.c");
  move_object(eukko, this_object()); }

  if(arg) return;

  add_exit("south", "katu2.c");

  short_desc = "Thrmo Street1";
  long_desc = "A small and nicely furnished house.\n"+
              "There is only one window on the western wall.\n"+
              "Some small beautiful stones are placed on the\n"+
              "window board. A bed with many pillows is placed\n"+
              "on the northern corner.\n";
  set_light(3);
}
