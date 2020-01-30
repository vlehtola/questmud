inherit "room/room";
int door_tried = 0, i, h;
object monster01, spec;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area06c");
  short_desc = "At the guarding post";
  long_desc = "Guarding post and the watch tower entrance.\n" + 
              "The room is dimly lit, but there's a small fire burning in one\n" + 
              "corner, which gives some luminance to that part of the room.\n" + 
              "In whole, the room is in bad condition and the signs of a fierce\n" + 
              "battle are easily seen. The guards who were on duty that dramatic\n" + 
              "night have been slayed on their spots. Also two strange demonic\n" + 
              "corpses are laying by the eastern wall.\n" + 
              "On southern wall, just beyond some wreckage and human body parts,\n" + 
              "can be seen a small-sized door, probably leading to the watch tower.\n";
  set_not_out(2);

  i = random(5);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }

/*  if(!spec) {
      spec = clone_object("/wizards/ahma/castle/mob/spec01");
      move_object(spec, this_object());
  }*/
}

init() {
  ::init();
  add_action("open", "open");
  add_action("hep", "say");
}

open(str) {
  if(str == "door") {
  if(door_tried == 0) {
  write("You try to open the door but you quickly notice that it's locked.\n" + 
        "You sigh in frustration and kick the door. After a while you hear\n" + 
        "a quiet whisper through the door: 'give me the password.'\n" + 
        "It must be one of the guards of the castle.\n");
  say(this_player()->query_name() + " tries to open the door, but notices that it is locked.\n" +
                                    "After a while you hear someone whispering behind the door:\n" +
                                    "'give me the password'. It must be one of the guards.\n");
  door_tried = 1;
  return 1;
  }
  }
}

hep(str) {
  if(!h) {
  if(str) {
    door_tried = 1;
    add_exit("south", "/wizards/ahma/castle/rooms/area08");
    tell_room(this_object(), "You hear the guard whispering: 'Ah, at last. I was sure those things would\n" +
        "come and slay me just like they did to the others. Wait, I'll open the\n" +
        "the door for you.'\n" +
        "You hear a key turning in a lock and soon the door opens with a loud\n" +
        "creaking sound.\n");
    h = 1;
    return 1;
  }
  else {
    return;
  }
  }
  else {
    return;
  }
}
