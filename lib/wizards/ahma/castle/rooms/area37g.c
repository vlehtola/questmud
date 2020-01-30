inherit "room/room";
int pushed, i;
object monster01;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area37h");
  add_exit("southwest", "/wizards/ahma/castle/rooms/area37f");
  add_exit("west", "/wizards/ahma/castle/rooms/area37e");
  short_desc = "In the second floor of the cavern";
  long_desc = "Walking on the second floor of the cavern.\n" + 
              "This curving cavern is a rare sight due to its many unique stalactites.\n" + 
              "A distant odor of sulphur is floating in the air, which is not unusual\n" + 
              "when being near huge amount of stalactites. One stalactite looks suspicious.\n" + 
              "The reddish steam rising from the holes on the ground is making your eyes\n" + 
              "wet. The temperature is very high, partly due to the hot steam, partly to\n" + 
              "the hot, red light. On the ground, in addon to the holes, can be seen lots\n" + 
              "of footprints in a thin layer of dust, which is falling from the ceiling\n" + 
              "all the time.\n";
  if(!pushed) {
  items = allocate(2);
  items[0] = "stalactite";
  items[1] = "There seems to be something strange about this stalactite. It is coloured\n" + 
             "in a different way than the others and it does not look so sturdy";
  }
  set_not_out(1);

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob11");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob12");
      move_object(monster01, this_object());
    }   
  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob13");
      move_object(monster01, this_object());
    }
  }
}

init() {
  ::init();
  add_action("push", "push");
}
push(str) {
  if(str == "stalactite") {
  if(pushed == 0) {
  write("You start pushing the stalactite and are surprised how easily it starts to\n" + 
        "fall. The bottom part of the stalactite falls down and hits the stone wall,\n" + 
        "breaking it. The upper part of the stalactite crumbles down from the ceiling,\n" + 
        "but you manage to jump aside just in time before the stalactite would have\n" + 
        "squished you under its stony mass. Some smaller rocks still fall on you.\n");
  say(this_player()->query_name() + " starts pushing the strange-looking stalactite and it falls\n" +
                                    "rumbling down and breaks a hole in the wall.\n");
  this_player()->hit_with_spell(500-this_player()->query_dex());
  write("The hole in the wall invites you to enter it.\n");
  long_desc = "Walking on the second floor of the cavern.\n" + 
              "This curving cavern is a rare sight due to its many unique stalactites.\n" + 
              "A distant odor of sulphur is floating in the air, which is not unusual\n" + 
              "when being near huge amount of stalactites. One stalactite has been over-\n" + 
              "turned towards the wall, making a hole into it. The reddish steam rising\n" + 
              "from the holes on the ground is making your eyes wet. The temperature is\n" + 
              "very high, partly due to the hot steam, partly to the hot, red light. On\n" + 
              "the ground, in addon to the holes, can be seen lots of footprints in a thin\n" + 
              "layer of dust, which is falling from the ceiling all the time.\n";
  items[1] = "A weak-looking stalactite has been turned over the wall";
  add_exit("hole", "/wizards/ahma/castle/rooms/area38");
  pushed = 1;
  return 1;
  }
  write("The weak-looking stalactite has already been pushed over.\n");
  return 1;
  }
}
