inherit "room/room";
object ninja1, ninja2, ninja3, monster01;
int wall_broken;

reset(arg) {
  if(arg) return;
    if (!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob22"); 
      move_object(monster01, this_object());
    }
  add_exit("up", "/wizards/ahma/castle/rooms/area50");
  add_exit("down", "/wizards/ahma/castle/rooms/area48");
  short_desc = "Fourth floor of the tower";
  long_desc =  "On the fourth floor of the Demon Tower.\n" + 
               "The room is dark and very silent. The glowing stones which illuminated\n" + 
               "the previous floors are gone. Only one part of the room makes an exception:\n" + 
               "From inside the wall in the northern part seems to pulsate a soft bluish-\n" + 
               "violet glow which differs from all previous reddish glows. The floor feels\n" + 
               "furry, and when moving, no footsteps can be heard. Geysirs' hissing voices\n" + 
               "do not reach this height, but complete silence is broken by a weak humming\n" + 
               "sound coming from somewhere very close. The stairs leading to upper floor\n" + 
               "are situated in south, and the ladders leading down are in north.\n";

  if(!wall_broken) {
  items = allocate(4);
  items[0] = "wall";
  items[1] = "When taking a closer look at that mysterious light, you notice that there\n" + 
             "really is something bigger behind the wall where the glow comes. Stones\n" + 
             "don't look too firmly attached, maybe you could break your way through the\n" + 
             "pulsating wall";
  }
  
  set_not_out(1);  

  if(!ninja1) {
    ninja1 = clone_object("/wizards/ahma/castle/mob/mob06b");
    move_object(ninja1, this_object());
  }
  if(!ninja2) {
    ninja2 = clone_object("/wizards/ahma/castle/mob/mob06b");
    move_object(ninja2, this_object());
  }
  if(!ninja3) {
    ninja3 = clone_object("/wizards/ahma/castle/mob/mob06b");
    move_object(ninja3, this_object());
  }
  set_blocker("alucard", "up");
}

init() {
  ::init();
  add_action("action", "break");
}

action(str) {
  if(str == "wall") {
  if(!wall_broken) {
  write("You hit the stones as hard as you dare. The wall rumbles down more easily\n" + 
        "than you had thought it would be. As the wall disappears from blocking\n" + 
        "the source of the strange light, the room is filled with the calming violet\n" + 
        "glow. A new exit to the north is open.\n");
  say(this_player()->query_name() + " breaks the wall to the north. As the wall crumbles down, a calming\n" + 
                                    "violet light fills the room. A new exit to the north is open.\n");
  items[1] = "You see nothing special";
  wall_broken = 1;
  add_exit("north", "/wizards/ahma/castle/rooms/area49b");
  return 1;
  }
  else {
  write("The wall has already been broken.\n");
  return 1;
  }
  }
  { write("Break what?\n"); return 1; }
}

props() {
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});
  return;
}