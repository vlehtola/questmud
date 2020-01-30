inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("hummingbird")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/hummingbird.c"), this_object());
        }
        if(!present("badger")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/badger.c"), this_object());
        }
        if(!present("crow")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/crow.c"), this_object());
        }
        
        if(arg) return;


        add_exit("west","/wizards/jenny/mehta/huoneet/forest17.c");
        add_exit("northeast","/wizards/jenny/mehta/huoneet/forest14.c");
        add_exit("east","/wizards/jenny/mehta/huoneet/forest15.c");
        
  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see lots of trees and bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here. You can\n"+
              "find a small hut in west.\n";

 
        items = allocate(6);
        items[0] = "bushes";
        items[1] = "A few bushes are next to a path here.";
        items[2] = "trees";
        items[3] = "Some pine trees are standing near the path";
        items[4] = "hut";
        items[5] = "A fragile looking hut seems to be in west";
}
