inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cg2.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("east", "g4b.c");
  add_exit("north", "g2b.c");

short_desc = "The guard barracks";
long_desc = "There is a simple looking bed in the corner.\n"+
            "A small chest is placed in the front of the\n"+
            "bed. A wooden closet is leaning against the wall.\n";
            
items = allocate(4);
    items[0] = "chest";
    items[1] = "A wooden iron reinforced chest which is locked.\n";
    items[2] = "closet";
    items[3] = "A wooden locked closet.\n";

  set_light(3);
}
}
