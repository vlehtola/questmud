inherit "room/room";

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/for12");
  add_exit("west", "/wizards/ahma/orc/forest/for15");
  add_exit("southwest", "/wizards/ahma/orc/forest/for14");
  short_desc = "On a small opening";
  long_desc = "The green, grassy opening is full of life. Animals wander near the\n" + 
              "edges of the opening, looking for food and ready to run into the forest\n" + 
              "if something would threaten them. The flowers sway a bit in the gentle\n" + 
              "breezes of wind, resonating the life force within them. Birds sing their\n" + 
              "songs on the brances of trees on the edge of the meadow. A small wooden\n" + 
              "cottage can be seen behind a short distance to west.\n";

  items = allocate(4);
  items[0] = "flowers";
  items[1] = "Commonly seen flowers like dandelions are growing here. You do not\n" + 
             "want to examine them more than a glance because you really do see\n" + 
             "them everywhere when moving around";
  items[2] = "animals";
  items[3] = "Few wild forest animals are wandering around the opening. Maybe they\n" + 
             "are looking something to eat. The animals are aware of your presence\n" + 
             "so it would be a waste of time trying to catch or kill them";

}

init() {
  ::init();
  add_action("hep", "pick");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "flowers" || str == "dandelions") {
    write("You do not want to pick that common flowers like dandelions right now.\n");
    return 1;
  }
  else {
    return;
  }
}

