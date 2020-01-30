inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("badger")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/badger.c"), this_object());
        }
        if(!present("bear")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/bear.c"), this_object());
        }
        if(!present("mouse")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/mouse.c"), this_object());
        }
        if(arg) return;
 
        add_exit("southwest","/wizards/jenny/mehta/huoneet/forest12.c");

  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see an apple tree and some bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here.\n";

 
        items = allocate(4);
        items[0] = "bushes";
        items[1] = "A few bushes are next to a path here";
        items[2] = "tree";
        items[3] = "An ordinary looking apple tree is growing here, perhaps you can climb up";
}


init() {
  ::init(); 
  add_action("climb", "climb"); 
}

climb(str) {
  if(str == "tree") {
    write("You manage to climb up\n"); 
    say(this_player()->query_name()+" vanishes behind the tree\n");
    move_object(this_player(),"/wizards/jenny/mehta/huoneet/puu.c");
    command("look",this_player());
     }
     return 1;
 }
