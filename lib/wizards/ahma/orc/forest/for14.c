inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for15");
  add_exit("east", "/wizards/ahma/orc/forest/for12");
  add_exit("northeast", "/wizards/ahma/orc/forest/for13");
  short_desc = "On a small opening";
  long_desc = "The green, grassy opening is full of life. Animals wander near the\n" + 
              "edges of the opening, looking for food and ready to run into the forest\n" + 
              "if something would threaten them. The flowers sway a bit in the gentle\n" + 
              "breezes of wind, resonating the life force within them. Birds sing their\n" + 
              "songs on the brances of trees on the edge of the meadow. A small wooden\n" +
              "cottage can be seen behind a short distance to north.\n";

  items = allocate(4);
  items[0] = "flowers";
  items[1] = "Commonly seen flowers like dandelions are growing here. You do not\n" + 
             "want to examine them more than a glance because you really do see\n" + 
             "them everywhere when moving around";
  items[2] = "animals";
  items[3] = "Few wild forest animals are wandering around the opening. Maybe they\n" + 
             "are looking something to eat. The animals are aware of your presence\n" + 
             "so it would be a waste of time trying to catch or kill them";
  h = random(7);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear01"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/deer"), this_object()); alive = 1; }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/eagle"), this_object()); }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/fox"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/moose"), this_object()); }
    if(h==5) { move_object(mob = clone_object("/wizards/ahma/orc/mob/hunter"), this_object()); }
  }
  }
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

mobdead() {
  alive = 0;
}
