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

  add_exit("south", "hall2.c");
  add_exit("north", "hall8.c");
  add_exit("east", "hall6.c");
  add_exit("west", "hall4.c");
  
  short_desc = "The city hall";
  long_desc = "You are standing in the middle of the city hall. There are busy looking\n"+ 
              "dwarves running everywhere. Some of them are carrying papers in their\n"+
              "hands. A great and gorgeously decorated pillars are rising on both\n"+
              "sides of you. The floor is made from beautiful marble. There is some\n"+
              "pictures of dwarves made on the floor and pillars. The pictures are\n"+
              "beautifully decorated.\n";

  set_light(3);
}
}
