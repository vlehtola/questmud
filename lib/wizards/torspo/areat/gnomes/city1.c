inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/gnomes/city3.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/city2.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "This is the southwestern part of the city. Road continues its way to north\n"+
              "and east. Boring looking houses are standing on the both sides of the road.\n"+
              "There is a sign standing on the ground.\n";
  items = allocate(2);
  items[0] = "sign";
  items[1] = "------------ \n"+
             "| Town hall > \n"+
             "------------ \n"+
             "| \n"+
             "| \n"+
             "| \n";

}
