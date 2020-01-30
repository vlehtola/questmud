inherit "room/room";
int open, i;
object monster;

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/village/sub12");
  add_exit("northwest", "/wizards/ahma/orc/village/sub16");
  add_exit("stairs", "/wizards/ahma/orc/village/sub06");
  short_desc = "Deeper in an underground sewer-system";
  long_desc = "The air pressure can be felt in the ears when being this deep under ground-\n" + 
              "level. The torches are lighting the way in this small circular tunnel. The\n" + 
              "water is running slowly by your feet, the water-level is reaching up to your\n" + 
              "knees. Water can be heard falling down somewhere very near. The walls of this\n" + 
              "part of the tunnel system are much cleaner than in the upper part. Though\n" + 
              "some slimy substance can be still seen on the walls. The stairs lead up into\n" + 
              "the connecting tunnel, which connects this tunnel to another above this one.\n" + 
              "The water is running into this room via the stairs leading up.\n";
              
  items = allocate(8);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";
  items[2] = "water";
  items[3] = "In the brownish water floats various items and substances. You do not even\n" + 
             "want to think about what causes water's brown colour. The water seems to\n" + 
             "run in counterclockwise in this part of the sewer tunnel";
  items[4] = "stairs";
  items[5] = "The stairs made of brick are leading to upper part of the tunnel system.\n" + 
             "A huge metallic door can be seen in the end of the stairs";
  items[6] = "door";
  items[7] = "A huge metallic door is located in the northern wall. The door has been\n" + 
             "made from stainless material and looks really sturdy. The door shines\n" + 
             "weakly in the dim light. The door seems to be closed";

  if(open) { opened(); } else { closed(); }

  set_water(4);
  set_not_out(1);

  if(!monster) {
  i = random(6);
  if(i==0) { move_object(monster = clone_object("/wizards/ahma/orc/mob/alligator"), this_object()); }
  if(i==1) { move_object(monster = clone_object("/wizards/ahma/orc/mob/leech"), this_object()); }
  if(i==2) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant03"), this_object()); }
  if(i==3) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant01"), this_object()); }
  if(i==4) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant02"), this_object()); }
  if(i==5) { move_object(monster = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  }
}

init() {
  ::init();
  add_action("hep", "open");
  add_action("hap", "close");
}

hep(str) {
  if(str == "door") {
  if(!open) {
  if(call_other("/wizards/ahma/orc/village/sub06", "check")) {
    write("You open the huge metallic door, revealing an exit leading upper in the tunnel system.\n");
    say(this_player()->query_name() + " opens a huge metallic door, revealing an exit leading upper in the tunnel system.\n");
    add_exit("stairs", "/wizards/ahma/orc/village/sub06");
    call_other("/wizards/ahma/orc/village/sub06", "add_exit", "stairs", "/wizards/ahma/orc/village/sub11");
    call_other("/wizards/ahma/orc/village/sub06", "opened");
    tell_room("/wizards/ahma/orc/village/sub06", "The huge metallic door opens, revealing a new exit leading deeper in the tunnel system.\n");
    open = 1;
    return 1;
  }
  else {
    write("The door seems to be locked. You are stranded in the lower levels of the tunnel system.\n");
    say(this_player()->query_name() + " tries to open the door leading to upper levels of tunnel system, but fails.\n");
    return 1;
  }
  }
  else {
    write("The door is already open.");
    return 1;
  }
  }
  else {
    return;
  }
}

hap(str) {
  if(str == "door") {
  if(open) {
    write("You cannot close the door from this side.\n");
    return 1;
  }
  else {
    write("The door is already closed.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

opened() {
  open = 1;
  items[7] = "A huge metallic door is located in the northern wall. The door has been\n" + 
             "made from stainless material and looks really sturdy. The door shines\n" + 
             "weakly in the dim light. The door seems to be open";
}

closed() {
  open = 0;
  items[7] = "A huge metallic door is located in the northern wall. The door has been\n" + 
             "made from stainless material and looks really sturdy. The door shines\n" + 
             "weakly in the dim light. The door seems to be open";
}
