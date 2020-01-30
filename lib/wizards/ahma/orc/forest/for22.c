inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for24");
  add_exit("south", "/wizards/ahma/orc/forest/for21");
  short_desc = "At the base of a high cliff";
  long_desc = "The stony subterranean bedrock makes the ground much harder and more\n" + 
              "uncomfortable to walk on. A high cliff rises reaching the sky in north.\n" + 
              "The cliff seems to be a common one with its few promontories, loose\n" + 
              "rocks and stunted little trees. Thick forest is surrounding this area\n" + 
              "and it seems that some trees have been cut down from the base of the\n" + 
              "cliff. The entrance into the forest lies to south. The high cliff is\n" + 
              "located couple yards to the north.\n";
  
  items = allocate(2);
  items[0] = "cliff";
  items[1] = "A high cliff reaches towards the sky behind a little distance to north.\n" + 
             "It looks like a common cliff with its few promontories, loose rocks and\n" + 
             "stunted trees growing in it. Though the cliff could look like a boring\n" + 
             "and every way dead place, it is full of life. Many birds and few sheep-\n" + 
             "like animals live in its bluffs all around the year";

  h = random(5);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear02"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/lonewolf"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/hunter"), this_object()); }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/lynx"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/eagle"), this_object()); }
  }
  }
}

init() {
  ::init();
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

mobdead() {
  alive = 0;
}
