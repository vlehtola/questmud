inherit "room/room";
inherit "room/door";
object guard;

reset(arg) {
   
    if(!present("guard")) {
      move_object(clone_object("/wizards/jenny/linnake/mosut/hallguard.c"), this_object());
        }

        add_exit("north","/wizards/jenny/linnake/huoneet/kaytava2.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/kaytava1.c");

        short_desc = "You are walking in a hallway";
        long_desc = "You are walking in a hallway and you see stairs leading\n"+
                    "up in north and a big clean looking hall in south.\n"+
                    "You hear some chambermaids giggling somewhere near.\n";
 
        door_reset();
        set_door_label("Small wooden door",1);
        set_door_dir("east", "/wizards/jenny/linnake/huoneet/ulkoovi.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/ulkoovi",1);
        set_door_code("471",1);
        set_locked(1,1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
