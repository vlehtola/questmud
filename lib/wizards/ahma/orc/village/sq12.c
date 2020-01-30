inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/sq09");
  add_exit("west", "/wizards/ahma/orc/village/sq11");
  add_exit("enter", "/wizards/ahma/orc/village/tent01");
  short_desc = "In southeastern corner of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc") + 
              "A red and white striped tent is standing near the moat. A sign is\n" + 
              "hanging from a side of the tent.\n";

  items = allocate(4);
  items[0] = "tent";
  items[1] = "A common type of tent seen in almost all marketplaces. It is kind of\n" + 
             "tattered from the upper part, and the lower part is cylinder-shaped.\n" + 
             "The tent is coloured with red and white stripes. A sign is hanging\n" + 
             "near the doorway";
  items[2] = "sign";
  items[3] = "On the wooden sign is carved:\n" + 
             "Welcome to the Gran'h's carpet shop. We got all kinds of carpets\n" + 
             "for everyone's tastes. Also special requests can be handled";

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/salesman02"), this_object()); }
  if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
  if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
}