inherit "room/room";
object monster,monster2;

reset(arg) {
        if(!present("spider")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/spider.c"), this_object());
        }      

        if(!present("spider 2")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/spider.c"), this_object());
        }      

if(arg) return;

        add_exit("southeast","/wizards/jenny/mehta/huoneet/luola2.c");
        
  short_desc = "In a dark cave";
  long_desc = "You are walking in a mysterious looking old cave.\n"+
              "You can see cobwebs everywhere and there are bones\n"+
              "lying on the floor. The cave is pretty dark since\n"+
              "there aren't many light sources. Some worms are\n"+
              "crawling near your legs and something in this cave\n"+
              "stinks.\n";

        set_not_out();
 
        items = allocate(6);
        items[0] = "cobwebs";
        items[1] = "Very sticky looking cobwebs are hanging on the ceiling";
        items[2] = "bones";
        items[3] = "Some gnawed bones are lying on the floor.";
        items[4] = "worms";
        items[5] = "Disgusting looking maggots crawling on the floor.";
        
}
