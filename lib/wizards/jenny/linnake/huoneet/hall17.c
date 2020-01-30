inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("chambermaid")) {
           move_object(clone_object("/wizards/jenny/linnake/mosut/chambermaidc.c"), this_object());
        }
        if(!present("chambermaid 2")) {
           move_object(clone_object("/wizards/jenny/linnake/mosut/chambermaidb.c"), this_object());
        }
        if(!present("chambermaid 3")) {
           move_object(clone_object("/wizards/jenny/linnake/mosut/chambermaid.c"), this_object());
        }
        if(arg) return;

        add_exit("west","/wizards/jenny/linnake/huoneet/hall18.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/hall16.c");
        add_exit("southwest","/wizards/jenny/linnake/huoneet/hall15.c");

  short_desc = "You are walking in a massive hall";
  long_desc = "You are walking in a massive hall, There are huge pillars all\n"+
              "around you and some chandeliers are hanging from the ceiling.\n"+
              "A few windows have been placed high, near the ceiling and\n"+
              "there is also one small open window at the corner.\n";

 
        items = allocate(2);
        items[0] = "window";
        items[1] = "It is an open window and it might serve you as an exit..";
}


init() {
  ::init(); 
  add_action("leap", "leap"); 
}

leap(str) {
  if(str == "window") {
    write("You leap through the window!\n"); 
    say(this_player()->query_name()+" stumbled out through the window.\n");
    move_object(this_player(),"/wizards/jenny/linnake/huoneet/piha1.c");
    command("look",this_player());
     }
     return 1;
 }
