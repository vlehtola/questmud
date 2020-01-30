inherit "room/room";
object rotta,rotta2;

reset(arg) {

if(!rotta) {
  rotta = clone_object("/wizards/kaappi/dcity/mobs/rat2.c");
  move_object(rotta, this_object()); }

if(!rotta2) {
  rotta2 = clone_object("/wizards/kaappi/dcity/mobs/rat2.c");
  move_object(rotta2, this_object()); }
  if(arg) return;

  add_exit("east", "katu38.c");

  short_desc = "A house";
  long_desc = "This house is in very bad shape.\n"+
              "There are many cracks on the walls and \n"+
              "the dust covers the floor and furnitures.\n"+
              "The ceiling looks like it could collapse\n"+
              "at any time. Some footprints can be seen\n"+
              "on the floor but still it looks like no one\n"+
              "has visited here for a long time.\n";

  set_light(1);
}
