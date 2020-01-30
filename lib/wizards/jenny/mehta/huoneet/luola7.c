inherit "room/room";
object monster,monster2;

reset(arg) {
if(arg) return;
        if(!present("spider")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/spider.c"), this_object());
        }      

        if(!present("spider 2")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/spider.c"), this_object());
        }      



        add_exit("north","/wizards/jenny/mehta/huoneet/luola6.c");
        
  short_desc = "In a dark cave";
  long_desc = "You are walking in a mysterious looking old cave.\n"+
              "You can see cobwebs everywhere and there are bones\n"+
              "lying on the floor. The cave is pretty dark since\n"+
              "there aren't many light sources. Some worms are\n"+
              "crawling near your legs and something in this cave\n"+
              "stinks. There is something lurking in the shadows.\n";

        set_not_out();
 
        items = allocate(8);
        items[0] = "cobwebs";
        items[1] = "Very sticky looking cobwebs are hanging on the ceiling";
        items[2] = "bones";
        items[3] = "Some gnawed bones are lying on the floor.";
        items[4] = "worms";
        items[5] = "Disgusting looking maggots crawling on the floor.";
        items[6] = "shadows";
        items[7] = "There surely is someone there, but how could u lure it out?";
}

bone_location() {
  return 1;

}
