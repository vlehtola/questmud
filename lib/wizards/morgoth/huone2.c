inherit "room/room";
 
 
reset(arg) {
  add_exit("north","/wizards/morgoth/huone2");
  add_exit("jumpup","/wizards/morgoth/huone2");
 
  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
                "Ain't it wondelful?\n";
 
  items = allocate(4);
  items[0] = "jeesmies";
  items[1] = "Jeesmies looks cool";
 
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
 
  reset() {
  if (!present("cannibal") {
     move_object(clone_object("/wizards/morgoth/monster"), this_object());
  }
}
 
 
init() {
  ::init(); 
  add_action("yeah", "yeah");
}
 
 
yeah(str) {
  if(str == "this rocks") {
    write("It sure does.\n"); 
    return 1; 
  }
