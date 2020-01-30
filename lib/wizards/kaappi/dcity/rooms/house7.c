inherit "room/room";
object eukko;

reset(arg) {

if(!eukko) {
  eukko = clone_object("/wizards/kaappi/dcity/mobs/eukko.c");
  move_object(eukko, this_object()); }
  if(arg) return;

  add_exit("west", "katu13.c");

  short_desc = "A house";
  long_desc = "Just a normal dwarven house. Small and\n"+
              "nicely decorated with some pieces of art.\n"+
              "A beutiful painting is hanging on the wall\n"+
              "and some candles are burning on the table\n"+
              "in the middle of the room.\n";
  set_light(3);
  
items = allocate(2);
  items[0] = "painting";
  items[1] = "A picture of Thordim Goodsteel, The king of Amaranthgard";
}
