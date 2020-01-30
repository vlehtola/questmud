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

        add_exit("west","/wizards/jenny/mehta/huoneet/forest3.c");
        add_exit("northeast","/wizards/jenny/mehta/huoneet/forest1.c");
        add_exit("southeast","/wizards/jenny/mehta/huoneet/forest6.c");
        add_exit("south","/wizards/jenny/mehta/huoneet/forest5.c");

  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see lots of trees and bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here.\n";

 
        items = allocate(4);
        items[0] = "bushes"; 
        items[1] = "A few bushes are next to a path here.";
        items[2] = "trees";
        items[3] = "Some huge maple trees are standing here.";
}
