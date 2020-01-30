inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/forest/for24");
  add_exit("northwest", "/wizards/ahma/orc/forest/for26");
  short_desc = "Beginning of a thin canyon";
  long_desc = "The stony subterranean bedrock makes the ground much harder and more\n" + 
              "uncomfortable to walk on. A high cliff rises reaching the sky in north.\n" +
              "In the bluff of the cliff begins a thin canyon to the northwest. The\n" + 
              "forest surrounds this area in south and it seems that some trees have\n" + 
              "been cut off from the canyon entrance. In east you can see the\n" + 
              "intersection which leads to the forest and much further to the east.\n";
              
  items = allocate(2);
  items[0] = "cliff";
  items[1] = "A high cliff reaches towards the sky behind in north. It looks like a\n" + 
             "common cliff with its few promontories, loose rocks and stunted trees\n" + 
             "growing in it. Though the cliff could look like a boring and every way\n" + 
             "dead place, it is full of life. Many birds and few sheep-like animals\n" + 
             "live in its bluffs all around the year";

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
