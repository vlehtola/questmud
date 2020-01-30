inherit "room/room";
object mob01, mob02, mob03;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil06");
  add_exit("south", "/wizards/ahma/orc/village/vil02");
  short_desc = "In a long, simply built house";
  long_desc = "This long hut connects Galor and Orgam streets. The northern exit leads\n" + 
              "to Galor street and the southern exit to Orgam street. The house seems\n" + 
              "quite spacious, maybe because not so much furniture is seen. A dining\n" + 
              "table stands by the western wall and three chairs are placed around it.\n" + 
              "Some paintings are hanging on the eastern wall. A greenish carpet covers\n" + 
              "the floor, making the walking inside the house more comfortable.\n";
  items = allocate(6);
  items[0] = "table";
  items[1] = "An ordinary wooden dining table is standing by the western vall.\n" +
             "Some dishes are set on the table, but no food is placed on them\n" +
             "yet. Though the table is made of wood, it looks sturdy enough for\n" + 
             "lasting at least half a century in use";
  items[2] = "paintings";
  items[3] = "Some paintings of family members are hanging on the eastern wall\n" +
             "of this long house. There seems to be seven paintings portraiting\n" + 
             "the each member. Some of them look old enough to live on their own\n" +
             "and they might already have moved out from this household";
  items[4] = "carpet";
  items[5] = "The green, furry carpet reminds you a bit from grass. The whole village\n" + 
             "seems to be somehow very nature-friendly, and this carpet might re-\n" + 
             "present the nature in this house. The soft carpet feels comfortable\n" +
             "under your feet";

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); }
  if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/woman02"), this_object()); }
  if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/man02"), this_object()); }
}