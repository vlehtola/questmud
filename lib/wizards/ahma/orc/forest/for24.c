inherit "room/room";

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/for22");
  add_exit("west", "/wizards/ahma/orc/forest/for25");
  add_exit("east", "/wizards/ahma/orc/forest/for23");
  short_desc = "At the base of a high cliff";
  long_desc = "The stony subterranean bedrock makes the ground much harder and more\n" + 
              "uncomfortable to walk on. A high cliff rises reaching the sky in north.\n" + 
              "The cliff seems to be a common one with its few promontories, loose\n" + 
              "rocks and stunted little trees. Thick forest is surrounding this area\n" + 
              "and it seems that some trees have been cut down from the base of the\n" + 
              "cliff. In east can be seen a small shack and in west an entrance to\n" + 
              "a thin canyon. Behind a short distance to south begins the path leading\n" +
              "into the forest.\n";
  
  items = allocate(2);
  items[0] = "cliff";
  items[1] = "A high cliff reaches towards the sky behind in north. It looks like a\n" + 
             "common cliff with its few promontories, loose rocks and stunted trees\n" + 
             "growing in it. Though the cliff could look like a boring and every way\n" + 
             "dead place, it is full of life. Many birds and few sheep-like animals\n" + 
             "live in its bluffs all around the year";
}

init() {
  ::init();
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}
