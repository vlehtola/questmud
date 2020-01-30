inherit "room/room";
object smithy;
string killer;
reset(arg) {
  if(arg) return;
                  if(!smithy) {
                          smithy = clone_object("/wizards/neophyte/city/monst/smithy");
                          move_object(smithy, this_object());
                  }
  short_desc = "The pirates weapon shop";
  long_desc = "At the pirates weapon shop. There are lots of different kind of weapons\n"+
              "and shields hanging on the walls. The walls are paint in blue, representing\n"+
              "the sea. On the ground is huge fireplace and next to it is an anvil, where\n"+
              "the smith does his work. This is the one and only weapon shop in the city,\n"+
              "in the whole island.\n";
  set_not_out(1);
  set_light(3);

  add_exit("south", "/wizards/neophyte/city/amber2");
}

set_killer(string str) {
	killer = str;
}
query_killer() { return killer; }
