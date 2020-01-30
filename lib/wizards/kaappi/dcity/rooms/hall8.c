inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/clerk.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("north", "throne.c");
  add_exit("east", "hall9.c");
  add_exit("south", "hall5.c");
  add_exit("west", "hall7.c");
  
  short_desc = "The city hall";
  long_desc = "This is a huge and spacious place. The hallway leads to north, west,\n"+ 
              "south and east. There are busy looking dwarves running everywhere.\n"+ 
              "Some of them are carrying papers in their hands. A great and gorgeously\n"+
              "decorated pillars are rising on both sides of you. The floor is made from\n"+
              "beautiful marble. In north you can see the throne of king.\n";

  set_light(3);
}
}
