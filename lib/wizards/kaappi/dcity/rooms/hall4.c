inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/clerk.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("north", "hall7.c");
  add_exit("south", "hall1.c");
  add_exit("east", "hall5.c");
  
  short_desc = "The city hall";
  long_desc = "This is a huge and spacious place. The hallway leads to north,south and east.\n"+
              "There are busy looking dwarves running everywhere. Some of them are \n"+
              "carrying papers in their hands. A great and gorgeously decorated pillars\n"+
              "are rising on right side of you. The floor is made from beautiful marble.\n";

  set_light(3);
}
}
