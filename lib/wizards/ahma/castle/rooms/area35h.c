inherit "room/room";
int rocks_removed = 0, i;
object monster01;

reset(arg) {
  add_exit("east", "/wizards/ahma/castle/rooms/area35g");
  short_desc = "In the first floor of the cavern";
  long_desc = read_file("/wizards/ahma/castle/ffloordesc") +
              "Some rocks are piled up by the eastern wall.\n";
  items = allocate(2);
  items[0] = "rocks";
  items[1] = "The rocks on the eastern wall seem to be quickly piled up.\n" + 
             "You just might be able to move the rocks from their present position\n" +
             "and see what they are piled up there for";

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob11");
      move_object(monster01, this_object());
    }
  }
}

init() {
  ::init();
  add_action("push", "move");
}

push(str) {
  if(str == "rocks") {
  if(rocks_removed == 0) {
  write("You remove rocks one by one from the pile. Behind the rocks you find\n" +
        "a dark hole leading up, probably back to the castle.\n");
  say(this_player()->query_name() + " removes some rocks by the wall revealing a new exit.\n");
  add_exit("hole", "/wizards/ahma/castle/rooms/area35i");
  rocks_removed = 1;
  return 1;
  }
  }
}

