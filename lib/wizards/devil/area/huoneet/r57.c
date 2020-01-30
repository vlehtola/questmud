inherit "room/room";  

reset(arg) {
  add_exit("east","/wizards/devil/area/huoneet/r58.c");
  add_exit("west","/wizards/devil/area/huoneet/r56.c");

  short_desc = "Decorated aisle in the huge temple";
  long_desc = "You are walking in beautifully decorated aisle leading deeper into temple.\n"+
                "Walls has painted with white paint and therefore they look like just\n"+
                "painted. The floor is slippery because it's made from marble. A large crypt is\n"+
                "built in here.\n";

items = allocate(4);
  items[0] = "crypt";
  items[1] = "Very large sized crypt stands here, some writings can be seen on the walls"; 
  items[2] = "writing";
  items[3] = "Crypt of old rules from temple, you should not enter there"; }
  
init() {
  ::init(); 
  add_action("enter", "enter");
}

enter(str) {
  if(str == "crypt") {
    write("You enter in the crypt.\n"); 
    say(""+this_player()->query_name()+" enters in the crypt.\n");    
    move_object(this_player(),"/wizards/devil/area/huoneet/r61.c");
    return 1; 
 }
}
