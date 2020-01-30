inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) {
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"),
    this_object());
}
 
  if(arg) return;
 
  add_exit("north","/wizards/irmeli/pena/ruum12.c");
  add_exit("south","/wizards/irmeli/pena/ruum14.c");
  set_not_out(1);

  short_desc = "Small corridor leading you down under the surface";
  long_desc = "This small corridor is smaller than earlier ones. There is a small hole\n"+
              "on eastern wall. There is coming water from the hole.\n";

  items = allocate(4);
  items[0] = "hole";
  items[1] = "Water is coming from this hole";
  items[2] = "wall";
  items[3] = "There is a small hole on easternwall";
}

init() {
  ::init(); 
  add_action("crawl", "crawl");
}

crawl(str) {
  if(str == "hole") {
    write("When you crawl the hole a bit you notice that there is a secret room.\n"); 
    this_player()->move_player("the hole","/wizards/irmeli/pena/ruum31.c");
    this_player()->set_quest("angel_valley_hole", 2);
    return 1; 
}
    write("What ?\n");
    return 1;
}

