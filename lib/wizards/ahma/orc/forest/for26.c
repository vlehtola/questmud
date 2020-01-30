inherit "room/room";
int picked, moved, h, alive;
object mob;

reset(arg) {
  add_exit("north", "YouCannotGoHere");
  add_exit("southeast", "/wizards/ahma/orc/forest/for25");
  short_desc = "In a thin canyon";
  long_desc = "This thin canyon seems to have been formed inside the cliff long time ago.\n" + 
              "Most of the existing canyons were shaped to their present forms during the\n" +
              "last Ice Age, which probably was also this canyon's era of birth. The canyon\n" +
              "has very steep hills in it, making advancing to the north almost impossible.\n" + 
              "Many shades and shadows dwell in this part of the canyon, making the seeing\n" +
              "much harder than outside the canyon. On the ground can be seen some small\n" + 
              "piles of rock. A dark figure of a bush is growing near the hill in the north.\n";

  items = allocate(10);
  items[0] = "hill";
  items[1] = "It is impossible to climb up this hill without proper tools. The hill\n" + 
             "is very steep and there does not seem to be good places to take grip from\n" + 
             "the side of it";
  items[2] = "rock";
  items[3] = "Try looking at 'rocks'";
  items[4] = "rocks";
  items[5] = "At least half a dozen small piles of rock have been piled up on purpose\n" + 
             "in this part of the canyon. You do not know what they are for, maybe they\n" + 
             "are gravestones or perhaps some other religious or superstitious markings.\n" + 
             "The most of the piles are near the center of the thin canyon, but few are\n" + 
             "also near the canyon walls. One of the piles, a bit smaller than the others,\n" + 
             "has been piled up against the eastern wall. The piles have been made from\n" + 
             "ordinary stones found all around the cliff";
  items[6] = "bush";
  items[7] = "A single, stunted bush is growing in very hard and non-fertile soil near\n" + 
             "the hill located in north. There seems to be very little light and water\n" + 
             "in the canyon, but the bush still keeps flourishing. The bush is even\n" + 
             "producing some kind of flowers in spite of the surroundings in which it\n" + 
             "is growing. No apparent reason for its existence can be seen";
  items[8] = "flowers";
  items[9] = "Quite big flowers, which the bush is producing, are coloured in either\n" + 
             "dark blue or black. You are not certain of their variety, but they might\n" + 
             "be the legendary and very rare night-bells. The flowers seem to reach\n" + 
             "quite far away from the bush, which makes them look almost as separate\n" + 
             "plants. The greenish stalks of the flowers are almost one third foot long";
  picked = 0;
  set_light(1);
  h = random(5);
  if(!mob) { 
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear02"), this_object()); alive = 1; }
    if(h==1 || h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/lonewolf"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/wolf01"), this_object()); }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/lynx"), this_object()); alive = 1; }
  }
  }
}

init() {
  ::init();
  add_action("hep", "pick");
  add_action("hap", "move");
  add_action("north", "north");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

north() {
  write("Due to the steepness of the hill, you cannot continue northwards without\n" +
        "proper tools.\n");
  return 1;
}


hep(str) {
  if(str == "flowers" || str == "flower" || str == "night-bell") {
  if(picked != 2) {
    write("You pick a strange black and dark blue flower from the bush.\n");
    say(this_player()->query_name() + " seems to pick something from the dark figure of a bush.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/nightbell"), this_player());
    picked++;
    return 1;
  }
  else {
    write("Someone has already picked some of the night-bells away from the bush.\n" + 
          "You do not want to ruin the whole bush by picking the last flowers away,\n" + 
          "you will have to wait for some new flowers to grow up.\n");
    return 1;
  }
  }
  else {
    write("Pick what?\n");
    return 1;
  }
}

hap(str) {
  if(str == "rocks" || str == "rock") {
  if(!moved) {
    write("You remove a pile of rocks by the canyon wall and reveal a dark hole\n" + 
          "underneath them.\n");
    say(this_player()->query_name() + " removes a pile of rocks by the canyon wall, discovering a hole under them.\n");
    add_exit("hole", "/wizards/ahma/orc/forest/sub06");
    call_other("/wizards/ahma/orc/forest/sub06", "add_exit", "up", "/wizards/ahma/orc/forest/for26");
    call_other("/wizards/ahma/orc/forest/sub06", "exit_open");
    tell_room("/wizards/ahma/orc/forest/sub06", "Someone removed the rocks blocking the hole leading up.\n");
    moved = 1;
    return 1;
  }
  else {
    write("You load the pile of rocks back to their original place by the canyon wall.\n" + 
          "The hole is hidden again.\n");
    say(this_player()->query_name() + " piles the rocks back to their original place.\n");
    remove_exit("hole");
    call_other("/wizards/ahma/orc/forest/sub06", "remove_exit", "up");
    call_other("/wizards/ahma/orc/forest/sub06", "exit_closed");
    tell_room("/wizards/ahma/orc/forest/sub06", "Someone blocked the hole leading up with a pile of rocks.\n");
    moved = 0;
    return 1;
  }
  }
  else {
    return;
  }
}

mobdead() {
  alive = 0;
}
