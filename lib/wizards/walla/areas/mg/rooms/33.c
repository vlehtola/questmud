inherit "room/room";

object rotta;

reset(arg) {
  if(!rotta) {
    rotta = clone_object("/wizards/walla/areas/mg/mobs/scavenger");
    move_object(rotta, this_object());
  }
  if(arg) return;
  add_exit("west","32");
  add_exit("east","34");
  add_exit("north","23");
  add_exit("south","43");
  add_exit("northeast","24");
  add_exit("northwest","22");
  add_exit("southeast","44");
  add_exit("southwest","42");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. Right in front of you,\n" +
"stands a grave that looks as it has been visited heartwarmingly often.\n"+
"There are numerous fresh flowers strewn over the gravestone.\n";

  items = allocate(2);
  items[0] = "grave";
  items[1] = "The grave of a person of importance.";


}
