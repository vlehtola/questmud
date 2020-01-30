inherit "room/room";
int stone_on_pedestal = 0;
object monster01;

reset(arg) {
  if(arg) return;
    if (!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob21"); 
      move_object(monster01, this_object());
    }

  add_exit("down", "/wizards/ahma/castle/rooms/area47");
  short_desc = "Third floor of the tower";
  long_desc =  "On the third floor of the Demon Tower.\n" + 
               "This room stinks really horrific, though it is much cleaner than the previous\n" + 
               "floors. It seems that the room is also better luminated than other ones. In\n" + 
               "the southern side of the room a part of the floor seems to be depressed, like\n" + 
               "it would be a pedestal of some kind. The wall is filled with carvings of\n" + 
               "demon-like creatures, probably with some reputation amongst these creatures\n" + 
               "here, living in this tower. The eastern wall is stuffed with glowing red\n" + 
               "stones, almost like gems, with much more shape than the others encountered\n" + 
               "so far. On the floor, near the gem-like rocks, there is a larger piece of\n" + 
               "stone.\n";
  items = allocate(4);
  items[0] = "stone";
  items[1] = "Ordinary looking grayish stone has been lifted up into this floor. There\n" +
             "seems to be some carvings on the rock, but you are not familiar with the\n" +
             "language";
  items[2] = "pedestal";
  items[3] = "In one particular spot in the southern part of the room, the floor is\n" +
             "depressed a little, and there is crumbled stone around the pedestal-like\n" + 
             "plate";

  set_not_out(1);
  set_blocker("lark", "up");
}

init() {
  ::init();
  add_action("action", "push");
}

action(str) {
  if(str == "pedestal") {
  write("You don't have enough strength to push the big stone plate in the ground.\n");
  say(this_player()->query_name() + " tries to push the pedestal, but cannot get moved it even a bit.\n");
  return 1;
  }
  if(str == "stone")
  { write("Where to push it?\n"); return 1; }
  if(str == "stone on pedestal" || str == "stone on the pedestal") {
  if(stone_on_pedestal == 0) {
  write("The piece of rock starts moving amazingly easy and smooth as you start\n" + 
        "pushing it. This same operation must have been done to it several times\n" + 
        "before. As you push the stone on the pedestal it starts to descend.\n" + 
        "After a moment the descending stops and you hear a rumbling sound behind\n" + 
        "you. You turn around and notice that ladders have fallen down from the\n" + 
        "upper floor, opening you an entrance to higher floors of the tower.\n");
  say(this_player()->query_name() + " pushes a rock on the pedestal and ladders come rumbling down from the floor\n" + 
                                    "above, opening you a new entrance to upper floors.\n");
  add_exit("up", "/wizards/ahma/castle/rooms/area49");
  stone_on_pedestal = 1;
  return 1;
  }
  else { write("The stone is already on the pedestal.\n"); return 1; }
  }
}
