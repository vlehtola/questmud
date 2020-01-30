inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/hellhound");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/walla/peepseye/vorticons/entrance"); 
  add_exit("south","/wizards/walla/peepseye/vorticons/c8");
  short_desc = "In the maze";
  long_desc =
 "In the maze.\n" ;
 
  items = allocate(4);
  items[0] = "sign";
  items[1] = "you can go up here.";
 
}
init() {
  ::init();
  add_action("lite", "lite");
}
 
lite(str) {
if(!present("lantern",this_player())) {write("You need a lantern to exit.\n");return 0; }
write("As you light the lantern, it burns a hole in the roof, making it possible to climb up.\n");
say("Someone burns a hole in the roof, making it possible to climb up.\n");                  
  add_exit("up","/wizards/walla/peepseye/4");
  return 1;
}




