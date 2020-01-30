inherit "room/room";
object monster,monster2;

reset(arg) {

        if(!present("owl")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/owl.c"), this_object());
        }
        if(!present("mouse")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/mouse.c"), this_object());
        }
        
        if(arg) return;

        add_exit("out","/wizards/jenny/mehta/huoneet/jokupaikka.c");
        add_exit("southeast","/wizards/jenny/mehta/huoneet/forest7.c");
        add_exit("southwest","/wizards/jenny/mehta/huoneet/forest2.c");

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
        items[3] = "Some huge oak trees are standing here.";
}
