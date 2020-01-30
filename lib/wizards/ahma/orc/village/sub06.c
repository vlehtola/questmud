inherit "room/room";
int turn, open, i;
object monster;

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/village/sub05");
  add_exit("northwest", "/wizards/ahma/orc/village/sub07");
  short_desc = "In a dark sewage tunnel";
  long_desc = "Some torches attached to the tunnel walls are lighting up the way. The\n" +
              "water runs slowly along the bottom of the tunnel. The water level is quite\n" + 
              "low, reaching only to your ankles. The walls of the tunnel are covered\n" + 
              "with green slime-like mould and the stench floating in the room is quite\n" + 
              "pungent. Small pipes are piercing the tunnel walls here and there.\n" + 
              "Miscellaneous trash is floating in the brownish water. In the northern\n" +
              "wall is located a metallic door. The water is running down through the\n" +
              "small space under the door.\n";

  items = allocate(12);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";
  items[2] = "pipes";
  items[3] = "Some stony pipes reach the tunnel through its walls. The brownish water\n" + 
             "is flowing into the tunnel from these pipes. The pipes are too small for\n" + 
             "you to fit in them";
  items[4] = "water";
  items[5] = "In the brownish water floats various items and substances. You do not even\n" + 
             "want to think about what causes water's brown colour. The water is running\n" +
             "deeper into the tunnel-system from the connecting tunnel in the northern wall";
  items[6] = "stairs";
  items[7] = "You see nothing special";
  items[8] = "door";
  items[9] = "A huge metallic door is located in the northern wall. The door has been\n" + 
             "made of stainless metal and looks really sturdy. The door shimmers weakly\n" + 
             "in the dim light. A rusty-looking wheel is attached on the wall next to\n" + 
             "the door";
 items[10] = "wheel";
 items[11] = "Very rusty wheel is attached on the tunnel wall next to the huge door.\n" + 
             "The wheel seems to be ready to break into pieces, so it must be handled\n" + 
             "with great care if handled at all";

  if(!open) { stairs_deactive(); } else { stairs_active(); }
  set_water(2);
  set_not_out(1);
  
  if(!monster) {
  i = random(6);
  if(i==0) { move_object(monster = clone_object("/wizards/ahma/orc/mob/alligator"), this_object()); }
  if(i==1) { move_object(monster = clone_object("/wizards/ahma/orc/mob/leech"), this_object()); }
  if(i==2) { move_object(monster = clone_object("/wizards/ahma/orc/mob/sewerrat"), this_object()); }
  if(i==3) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant01"), this_object()); }
  if(i==4) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant02"), this_object()); }
  if(i==5) { move_object(monster = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  }
}

init() {
  ::init();
  add_action("hep", "turn");
  add_action("hap", "open");
  add_action("pep", "close");
  add_action("pap", "pull");
  add_action("pap", "move");
}

hep(str) {
  if(str == "wheel") {
  if(!open) {
  if(!turn) {
    write("You turn the rusty wheel on the huge metallic door. The door seems to unlock.\n");
    say(this_player()->query_name() + " turns a rusty wheel on the door. The door seems to unlock.\n");
    turn = 1;
    return 1;
  }
  else {
    write("You turn the rusty wheel on the huge metallic door. The door seems to lock up.\n");
    say(this_player()->query_name() + " turns a rusty wheel on the door. The door seems to lock up.\n");
    turn = 0;
    return 1;
  }
  }
  else {
    write("The door is open and you cannot operate the wheel.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

hap(str) { 
  if(str == "door") {
  if(!open) {
  if(turn) {
    write("You huge metallic door opens with a loud creaking sound. A stairs leading\n" + 
          "down are revealed behind the door.\n");
    say(this_player()->query_name() + " opens the huge metallic door, revealing stairs leading down.\n");
    add_exit("stairs", "/wizards/ahma/orc/village/sub11");
    call_other("/wizards/ahma/orc/village/sub11", "add_exit", "stairs", "/wizards/ahma/orc/village/sub06");
    call_other("/wizards/ahma/orc/village/sub11", "opened");
    tell_room("/wizards/ahma/orc/village/sub11", "A huge metallic door opens in the end of the stairs leading up.\n");
    stairs_active();
    open = 1;
    turn = 1;
    return 1;
  }
  else {
    write("The huge door seems to be locked.\n");
    say(this_player()->query_name() + " tries to open the huge door, but it seems to be locked.\n");
    return 1;
  }
  }
  else {
    write("The door is already open.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

pep(str) {
  if(str == "door") {
  if(open) {
    write("You close the huge metallic door with a loud bang.\n");
    say(this_player()->query_name() + " closes the huge metallic door with a loud bank.\n");
    remove_exit("stairs");
    call_other("/wizards/ahma/orc/village/sub11", "remove_exit", "stairs");
    call_other("/wizards/ahma/orc/village/sub11", "closed");
    tell_room("/wizards/ahma/orc/village/sub11", "A huge metallic door closes in the end of the stairs, closing the exit to upper floors.\n");
    stairs_deactive();
    open = 0;
    return 1;
  }
  else {
    write("The huge door is already closed.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

pap(str) {
  if(str == "door" || str == "wheel") {
    write("You cannot do that.\n");
  }
  else { return; }
}



stairs_active() {
  items[7] = "The stairs made of brick are leading to lower parts of the tunnel system";
  return 1;
}

stairs_deactive() {
  items[7] = "You see nothing special";
  return 1;
}

opened() {
  open = 1;
}

closed() {
  open = 0;
}

check() {
  return turn;
}
