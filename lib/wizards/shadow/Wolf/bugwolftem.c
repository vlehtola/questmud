inherit "room/room";
int passage_open;

reset(arg) {
  set_light(3);
  add_exit("north","/wizards/shadow/Wolf/wolftem1");
  add_exit("south","/wizards/shadow/Wolf/wolftem2");
  add_exit("east","/wizards/shadow/Wolf/wolftem3");
  add_exit("west","/wizards/shadow/Wolf/wolftem4");
  add_exit("out","/wizards/shadow/Wolf/wolf7a");
  short_desc = "In the temple.";
  long_desc =
"You are inside a HUGE temple that is carved from solid ice. The temple\n"+
"has a has all kinds a painting on the walls, and they all resemble a wolf.\n"+
"That creature seems to be why this temple was built. In the middle of \n"+
"the room, there is a golden statue which looks like a wolf. The statue\n"+
"has ruby eyes, but the other one is missing. On the statue, there is\n"+
"an altar that the wolf seems to be holding up. There are blood stains on\n"+
"the altar. It seems to be used for sacrificing goods to the wolf.\n";
}

init() {
  add_action("rotate", "rotate");
  add_action("enter", "enter");
  add_action("move", "move");

::init();
}

move(str) {
  if(str == "statue") {
    write("The statue won't budge.\n");
      say(this_player()->query_name()+" tries to move the statue.\n");
    return 1;
    }
  }

rotate(str) {
    write("You rotate the statue and reveal a secret passage.\n");
    say(this_player()->query_name()+" reveals a secret passage.\n");
    passage_open = 1;
    return 1;
}

enter(str) {
  if(passage_open) {
    write("You enter the passage.\n");
    say(this_player()->query_name()+" enters the passage. "+
        "The statue moves back to its place.\n");
    passage_open = 0;
    move_object(this_player(), "/wizards/shadow/Wolf/wolftemsecr.c");
    say(this_player()->query_name()+" enters by a small passage.\n");
    return 1;
  }
}

long(str) {
  ::long(str);

    if(str == "passage") {
    if(passage_open) {
      write("A passage leading down.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
    if(str == "statue") {
    write("The statue looks like it could be moved or rotated.\n");
    return 1;
  }
 }  
}

id(str) {
if(str == "passage") { return 1; }
if(str == "statue") { return 1; }
}
