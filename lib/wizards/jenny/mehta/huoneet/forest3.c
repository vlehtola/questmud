inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("owl")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/owl.c"), this_object());
        }
        if(!present("badger")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/badger.c"), this_object());
        }
        if(!present("crow")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/crow.c"), this_object());
        }
        
        if(arg) return;

        add_exit("northwest","/wizards/jenny/mehta/huoneet/forest4.c");
        add_exit("east","/wizards/jenny/mehta/huoneet/forest2.c");
        add_exit("southeast","/wizards/jenny/mehta/huoneet/forest5.c");
        
  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see a huge tree and bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here.\n";

 
        items = allocate(4);
        items[0] = "bushes";
        items[1] = "A few bushes are next to a path here.";
        items[2] = "tree";
        items[3] = "An oak tree that seems to be centuries old.";
}
