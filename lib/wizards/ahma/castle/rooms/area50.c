inherit "room/room";
int ladders_down;
object monster01;

reset(arg) {
  if(arg) return;
    if (!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob23"); 
      move_object(monster01, this_object());
    }

  add_exit("down", "/wizards/ahma/castle/rooms/area49");
  short_desc = "Fifth floor of the tower";
  long_desc =  "On the fifth floor of the Demon Tower.\n" + 
               "The room lights up as you step upon the floor. The glowing stones are\n" +
               "somehow tuned to light up when someone moves in the room. They must be\n" + 
               "useful in more tasks than just lighting. A magic unknown to you is probably\n" + 
               "needed for operating the glowing stones. This red room seems to be full of\n" + 
               "of hate and anger. Most parts of the wall are covered with different kinds of\n" + 
               "weapons and armour. Axes, swords, maces, morningstars, whips and various shields\n" + 
               "are decorated with carved runes. The generally used materials of weapons and\n" + 
               "shields are steel and bone. One shield is lying on the floor. The tough-looking\n" + 
               "pieces of armour are hanging on the opposite wall of the room than weapons and\n" + 
               "shields. Scale- and different plate mails are made of steel and decorated with\n" + 
               "grayish-white skulls and bones of some creatures, humans' and demons', un-\n" + 
               "doubtedly. Bracers and gauntlets are hung near the arm plates of the torso-\n" + 
               "protecting mails. Leggings and boots made of steel are found near the leg plates\n" + 
               "of the mails. All equipment is magically attached to walls, and cannot be\n" + 
               "removed, or even touched, without correct, releasing spell.\n";
  items = allocate(4);
  items[0] = "armour";
  items[1] = "The armours float in mid-air, just touching the wall. A strange bluish force\n" + 
             "field seems to surround every one of them. You start examining one of the plate\n" + 
             "mails more closely: The armour is almost perfectly crafted. It is made of\n" + 
             "not-so-shiny steel, but it must be very durable, because seems to be more than\n" + 
             "an inch thick. The surface of the plate mail is unscratched which shows that\n" + 
             "either it has not yet been used in the battle field or its wearer masters the\n" + 
             "defending techniques greatly. There is a skull attached to both of mail's shoulder\n" + 
             "plates and a bone necklace is hanging around the neck plates. When you move to\n" + 
             "admire the steely arm plates you notice something interesting; There is a lever\n" + 
             "hidden behind the left plate";
  items[2] = "armours";
  items[3] = "The armours float in mid-air, just touching the wall. A strange bluish force\n" + 
             "field seems to surround every one of them. You start examining one of the plate\n" + 
             "mails more closely: The armour is almost perfectly crafted. It is made of\n" + 
             "not-so-shiny steel, but it must be very durable, because seems to be more than\n" + 
             "an inch thick. The surface of the plate mail is unscratched which shows that\n" + 
             "either it has not yet been used in the battle field or its wearer masters the\n" + 
             "defending techniques greatly. There is a skull attached to both of mail's shoulder\n" + 
             "plates and a bone necklace is hanging around the neck plates. When you move to\n" + 
             "admire the steely arm plates you notice something interesting; There is a lever\n" + 
             "hidden behind the left plate";

  set_not_out(1);
  set_blocker("rakk", "up");
}

init() {
  ::init();
  add_action("pull", "pull");
  add_action("pull", "move");
}

pull(str) {
  if(str == "lever") {
  if(ladders_down == 0) {
  write("You try to reach the lever with your hand without touching the shimmering\n" + 
        "force field. Finally, you get a grab of the lever and pull. Some kind of\n" + 
        "a mechanism starts operating somewhere above you with a rusty sound. This\n" + 
        "tower must be quite old. At the same time when the mechanism started its\n" +
        "groaning song, the ceiling on the northern part started to descend. Eventually\n" + 
        "the ceiling reachs the ground of this floor. In the descended piece of ceiling\n" + 
        "there seems to be ladders leading to upper floor.\n");
  say(this_player()->query_name() + " pulls the lever on the wall. The northern part of the ceiling descends and\n" +
                                    "the ladders leading to upper floor are revealed.\n");
  add_exit("up", "/wizards/ahma/castle/rooms/area51");
  call_other("/wizards/ahma/castle/rooms/area51", "add_exit", "down", "/wizards/ahma/castle/rooms/area50");
  call_other("/wizards/ahma/castle/rooms/area51", "remove_exit", "up");
  ladders_down = 1;
  return 1;
  }
  if(ladders_down == 1) {
  write("You pull the lever on its original position, the lever cracks and breaks due\n" + 
        "to this action, but the mechanism starts it's groaning again. After a moment\n" + 
        "the piece of floor, which was descended down on to this floor, has returned\n" +
        "to its normal place closing the entrance to upper floor.\n");
  say(this_player()->query_name() + " pulls the lever back to its original position. The lever cracks and breaks,\n" + 
                                    "and the enterance to the upper floor has been disabled.\n");
  remove_exit("up");
  call_other("wizards/ahma/castle/rooms/area51", "add_exit", "up", "/wizards/ahma/castle/rooms/area52");
  call_other("wizards/ahma/castle/rooms/area51", "remove_exit", "down");
  ladders_down = 2;
  return 1;
  }
  if(ladders_down == 2) {
  write("The lever controlling the mechanism is broken and you cannot operate it again.\n");
  return 1;
  }
  }
}

take(str) {
  if(str == "mail" || str == "plate" || str == "weapon" || str == "armour") {
  write("Something invisible seems to prevent you from touching the equipment on walls.\n");
  return 1;
  }
}

props() {
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});
  return;
}
