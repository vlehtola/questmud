inherit "room/room";
int vehke;

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/wolfpriest");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/shadow/Wolf/wolftem1");
  add_exit("south","/wizards/shadow/Wolf/wolftem2");
  add_exit("east","/wizards/shadow/Wolf/wolftem3");
  add_exit("west","/wizards/shadow/Wolf/wolftem4");
  add_exit("out","/wizards/shadow/Wolf/wolf7a");
  short_desc = "In the temple.";
  long_desc =
"You are inside a HUGE temple that is carved from solid ice. The temple\n" +
"has a has all kinds a painting on the walls, and they all resemble a wolf.\n" +
"That creature seems to be why this temple was built. In the middle of \n" +
"the room, there is a golden statue which looks like a wolf. The statue\n" +
"looks like it could possibly be move, or perhaps rotated. The statue\n" +
"has ruby eyes, but the other one is missing. On the statue, there is\n" +
"an altar that the wolf seems to be holding up. There are blood stains on\n" +
"the altar. It seems to be used for sacrificing goods to the wolf.\n";
}

init() {
    ::init();
   add_action("enter", "enter");
   add_action("rotate", "rotate");
   vehke = 1;
}

rotate(str) {
if ((str) == "statue") {
        if (vehke == 0) {
        write("You replace the statue.\n");
        say(this_player()->query_name()+" replaces the statue.\n");
        vehke = 1;
        }
        write("You reveal a secret passage\n");
        say(this_player()->query_name()+" reveals a secret passage.\n");
        vehke = 0;
 }
}

enter(str) {
  if ((str) == "passage") {
  if (vehke == 1) {
  write("What?\n");
  return 1;
  }
  say(this_player()->query_name()+" enters the passage.\n");
  write("You enter the passage and arrive into another room.\n");
  move_object(this_player(),"/wizards/shadow/Wolf/wolftemsecr.c");
  say(this_player()->query_name()+" arrives from the passage.\n");
  return 1;
 }
}
