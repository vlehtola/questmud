inherit "room/room";
reset(arg) {

        add_exit("curtain","/wizards/jenny/linnake/huoneet/throne5.c");

  short_desc = "Secret treasure room";
  long_desc = "You have found the secret treasure room of Roxen. When you\n"+
              "look around you see piles of gold, jewels and other valuable\n"+
              "treasures. There is open chest near the corner and a big golden\n"+
              "chandelier is hanging on the ceiling. A small carpet is on the\n"+
              "center of this room.\n";

  set_not_out();

        items = allocate(2);
        items[0] = "carpet";
        items[1] = "A small dull looking carpet is on the floor";
}
 

init() {
  ::init(); 
  add_action("pull", "pull"); 
}

pull(str) {
  if(str == "carpet") {
    write("You found a secret exit!\n"); 
    say(this_player()->query_name()+"found a secret exit!\n");
    add_exit("hideout","/wizards/jenny/linnake/huoneet/treasure2.c");
    command("look",this_player());
     }
     return 1;
 }
