inherit "room/room";  

reset(arg) {
  add_exit("north","/wizards/devil/swamps/huoneet/e4.c");
  add_exit("south","/wizards/devil/swamps/huoneet/e2.c");
  short_desc = "Small path leading deeper in the swamps.";
  long_desc = "You are on a small path, which is leading deeper and deeper in the swamps.\n"+
                "The path is in a good condition around here, but continuing forward, the path looks more\n"+
                "worse on every step you take. You can see small foot steps on the ground and you get feeling\n"+   
                "that someone or something might live in the swamps.\n";
}
