inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("hummingbird")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/hummingbird.c"), this_object());
        }
        if(!present("owl")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/owl.c"), this_object());
        }
        if(!present("crow")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/crow.c"), this_object());
        }
        
        if(arg) return;


        add_exit("east","/wizards/jenny/mehta/huoneet/forest16.c");
        add_exit("hut","/wizards/jenny/mehta/huoneet/hut.c");
        
  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see lots of trees and bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here. There is\n"+
              "an old looking hut next to some trees.\n";

 
        items = allocate(6);
        items[0] = "bushes";
        items[1] = "A few bushes are next to a path here.";
        items[2] = "trees";
        items[3] = "Some pine trees are standing near the path";
        items[4] = "hut";
        items[5] = "An old looking hut, you can see lantern burning inside it.";
}
