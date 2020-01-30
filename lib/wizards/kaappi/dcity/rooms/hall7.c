inherit "room/room";
object mob,mob2;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/clerk.c");
  move_object(mob, this_object()); }

  if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob2, this_object()); }
{
  if(arg) return;

  add_exit("south", "hall4.c");
  add_exit("east", "hall8.c");
  
  short_desc = "The city hall";
  long_desc = "This is a huge and spacious place. The hallway leads to south and east.\n"+
              "There are busy looking dwarves running everywhere. Some of them are \n"+
              "carrying papers in their hands. A great and gorgeously decorated pillar\n"+
              "is rising on right side of you. The floor is made from beautiful marble.\n";

  set_light(3);
}
}
