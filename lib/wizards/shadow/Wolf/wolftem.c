inherit "room/room";

reset (arg) {

  add_exit("south","/wizards/shadow/Wolf/wolftem2");
  add_exit("north","/wizards/shadow/Wolf/wolftem1");
  add_exit("east","/wizards/shadow/Wolf/wolftem3");
  add_exit("west","/wizards/shadow/Wolf/wolftem4");
  add_exit("out","/wizards/shadow/Wolf/wolf7a");


  

  short_desc = "In the temple of the wolf";
  long_desc = 
"You are inside a huge temple that is carved from solid ice. The temple\n"+
"has all kinds of paintings on the walls, and they all resemble a wolf.\n"+
"That creature seems to be the reason this temple was built. In the middle of\n"+
"the room, there is a golden statue which looks like a wolf. The statue\n"+
"has ruby eyes, but the other one is missing. On the statue, there is\n"+
"an altar that the wolf seems to be holding up. There are blood stains on\n"+
"the altar. It seems to be used for sacrificing goods to the wolf.\n";
              
  items = allocate(2);
  items[0] = "statue";
  items[1] = "A golden statue of a wolf. There are some scratches on the floor as\n"+
             "if the statue has been rotated.";            
}

init() {
  ::init();
  add_action("rotate", "move");
  add_action("rotate", "rotate");

}

rotate(str) {
    write("You rotate the statue and a secret passage appears.\n");
    say(this_player()->query_name()+" rotates the statue and a secret passage appears.\n");
    add_exit("enter","/wizards/shadow/Wolf/wolftemsecr");
   return 1;
}

