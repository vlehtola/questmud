inherit "room/room";
object mob01, mob02;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil13");
  short_desc = "In a small house with a chimney";
  long_desc = "This house seems quite advanced. There is an area suitable for cooking\n" + 
              "and steaking in the southwestern corner. The smoke produced by the\n" + 
              "campfire is directed out from the house through a hollow trunk pierced\n" +
              "through the roof. There seems also be some kind of an excercise bike\n" + 
              "located by the western wall. A dining table is standing by the northern\n" +
              "wall, as well as the window.\n";
              
  items = allocate (6);
  items[0] = "bike";
  items[1] = "The wooden excercise bike looks brilliantly made. These kind of things\n" + 
             "are very uncommon among as unintelligent creatures as Orcs. The bike\n" + 
             "is made of wood and it stands on four quite low pillars which prevent\n" + 
             "its wheels from hitting the ground. The braking force of the bike can\n" + 
             "be tuned with the stone which is rubbing against the rear wheel";
  items[2] = "window";
  items[3] = "The window carved in the northern wall gives out to the backyard of the\n" + 
             "house. There is nothing out of ordinary in the backyard, just grass";
  items[4] = "table";
  items[5] = "An ordinary wooden dining table is standing by the western vall.\n" +
             "Some dishes are set on the table, but no food is placed on them\n" +
             "yet. Though the table is made of wood, it looks sturdy enough for\n" + 
             "lasting at least half a century in use";

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/man02"), this_object()); }
  if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); }
  present("man", this_object())->specname();
}
