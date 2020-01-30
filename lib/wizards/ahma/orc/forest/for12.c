inherit "room/room";
int picked, h, alive;
object mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for13");
  add_exit("south", "/wizards/ahma/orc/forest/for09");
  add_exit("west", "/wizards/ahma/orc/forest/for14");
  add_exit("northwest", "/wizards/ahma/orc/forest/for15");
  short_desc = "Entrance to a small opening";
  long_desc = "The forest ends in a grassy meadow. The opening is surrounded by\n" + 
              "thick forest but no trees are growing in the middle of it. Some\n" + 
              "flowers are growing near the entrance to the forest in south. Behind\n" + 
              "a short distance to northwest can be seen a small wooden cottage. Few\n" + 
              "wild animals can be seen wandering behind the wooden barrier of tree\n" +
              "trunks by the edges of the meadow.\n";
  
  items = allocate(4);
  items[0] = "flowers";
  items[1] = "A beautiful bunch of white lilies are growing on the ground near\n" + 
             "the forest entrance to south";
  items[2] = "animals";
  items[3] = "Few wild forest animals are wandering behind the trees. Maybe they are\n" + 
             "looking for something to eat. The animals are aware of your presence\n" + 
             "and ready to flee if something threatening should happen";
  picked = 0;
  
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
  if(str == "flowers" || str == "flower" || str == "lily") {
  if(picked != 2) {
    write("You pick a beautiful white lily from the ground.\n");
    say(this_player()->query_name() + " picks a flower from the ground.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/lily"), this_player());
    picked++;
    return 1;
  }
  else {
    write("Someone has already picked some flowers from the ground. You do not\n" + 
          "want to ruin the whole bunch by picking the rest of the lilies away.\n" + 
          "You will have to wait for a moment that some new lilies grow up.\n");
    return 1;
  }
  }
  else {
    write("Pick what?\n");
    return 1;
  }
}

mobdead() {
  alive = 0;
}