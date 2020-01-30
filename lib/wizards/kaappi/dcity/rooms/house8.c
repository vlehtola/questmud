inherit "room/room";
object eukko;

reset(arg) {

if(!eukko) {
  eukko = clone_object("/wizards/kaappi/dcity/mobs/eukko.c");
  move_object(eukko, this_object()); }
  if(arg) return;

  add_exit("east", "katu14.c");

  short_desc = "A house";
  long_desc = "This house is entirely made of rock.\n"+
              "The table and chairs are also made of\n"+
              "rock. Here you can see the beauty of \n"+
              "the stonecraft from which the dwarves\n"+
              "are well known.\n";
  set_light(3);
}
