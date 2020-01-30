inherit "room/room";
inherit "room/door";
object guard;

reset(arg) {
   
    if(!present("guard")) {
      move_object(clone_object("/wizards/walla/viivi.c"), this_object());
        }

        short_desc = "kunkun huone";
        long_desc = "taa on kunkun huone\n"+
                    "talla asustelee joku jannu\n"+
                    "mut nyt viivi chillailee taalla.\n";
 
        door_reset();
        set_door_label("Small wooden door",1);
        set_door_dir("east", "/wizards/walla/northern/rooms/lvl3/drawbridge_2.c",1);
        set_door_link("/wizards/walla/northern/rooms/lvl3/drawbridge_2.c",1);
        set_door_code("221",1);
        set_locked(1,1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
