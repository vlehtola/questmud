inherit "room/room";
object monster,monster2,monster3;

reset(arg) {

        if(!present("badger")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/badger.c"), this_object());
        }
        if(!present("bear")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/bear.c"), this_object());
        }
        if(!present("owl")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/owl.c"), this_object());
        }
        if(arg) return;
 
        add_exit("northwest","/wizards/jenny/mehta/huoneet/forest6.c");
        add_exit("northeast","/wizards/jenny/mehta/huoneet/forest8.c");
        add_exit("southeast","/wizards/jenny/mehta/huoneet/forest10.c");

  short_desc = "In a peaceful forest";
  long_desc = "There are insects flying and crawling all around you,\n"+
              "also, you can see lots of trees and bushes near you.\n"+
              "forest looks very calm and peaceful, a small gust of\n"+
              "wind is blowing your hair nicely. A small path is\n"+
              "leading to several directions from here.\n";

 
        items = allocate(4);
        items[0] = "bushes";
        items[1] = "Some branches have been torn, you see something behind the bushes";
        items[2] = "trees";
        items[3] = "Some maple and oak trees are standing near the path";
}


init() {
  ::init(); 
  add_action("enter", "enter"); 
}

enter(str) {
  if(str == "bushes") {
    write("You tear your way through the bushes\n"); 
    say(this_player()->query_name()+" vanished behind the bushes.\n");
    move_object(this_player(),"/wizards/jenny/mehta/huoneet/luola1.c");
    command("look",this_player());
     }
     return 1;
 }
