inherit "room/room";

reset(arg) {


  add_exit("north","/wizards/siki/lizard/room10");
  add_exit("east","/wizards/siki/lizard/room2");
  add_exit("south","/wizards/siki/lizard/room5");
  add_exit("west","/wizards/siki/lizard/room11");

  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. You can feel the humidity\n"+
              "of the air as it fills your lungs. An uncomfortable feeling\n"+
              "fills you.\n";
}
