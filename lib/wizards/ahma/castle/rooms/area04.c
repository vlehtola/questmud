inherit "room/room";
int i;
object monster01, spec;

reset(arg) {
  add_exit("east", "/wizards/ahma/castle/rooms/area03");
  short_desc = "A dead end";
  long_desc = "The beginning of the corridor.\n" + 
              "The hallway turns here into a corridor. Some small fires are lit on\n" + 
              "the emblems hanging on the walls and on the red carpet on the floor.\n" + 
              "The corridor ahead is full of rumble and wreckage due to the failed\n" + 
              "ceiling.\n";
  
/*  if(!spec) {
    spec = clone_object("/wizards/ahma/castle/mob/spec05");
    move_object(spec, this_object());
  }*/
  
  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
  }  

  if(i == 3) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
  }
}

init() {
  ::init();
  add_action("west", "west");
}

west() {
  write("You cannot continue further due to the collapsed ceiling.\n");
  return 1;
}
