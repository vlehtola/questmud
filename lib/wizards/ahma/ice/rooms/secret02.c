inherit "room/room";
int moved;

reset(arg) {
  if(!present("king")) move_object(clone_object("/wizards/ahma/ice/mob/bking"), this_object());
  if(arg) return;
  
  add_exit("up", "secret01");
  short_desc = "The bottom floor in the polar bears' nest";
  long_desc = "It seems this opening in the bottom of the bears' nest would consist of\n" +
              "pure blood and guts. There is red, massacred jelly everywhere in this room:\n" +
              "the walls, floor and ceiling are all covered in bloody layer of Death's\n" +
              "fingerpaint. The stench of guts fills your nose and almost makes your eyes\n" +
              "bleed. Numerous corpses cover the floor in this room. A narrow tunnel in\n" +
              "the northern wall leads up.\n";
  items = allocate(2);
  items[0] = "corpses";
  items[1] = "Bloody, mostly-eaten animal corpses cover the most of this room's floor.\n" +
             "The corpses emit a randic stench all around of their surroundings. The\n" +
             "one who was meant to devour these corpses must have one hell of a kind\n" +
             "of an apetite";
}

destcorpse() {
  call_other("destcorpse2", 2);
  return 1;
}

destcorpse2() {
  if(present("corpse", this_object())) destruct(present("corpse", this_object()));
  return 1;
}
