inherit "room/room";
inherit "room/door";
object monster;


reset(arg) {
if(arg) return;
monster = clone_object("/wizards/walla/northern/mobs/razindukhta.c");
move_object(monster, this_object());

     
        short_desc = "The throne room";
        long_desc = "The throne room of Razindukhta is really worthy of his status.\n"+
                    "There is a large throne on the far side of the room, and a large\n"+
                    "chandelier hanging from the ceiling provides sufficient light to the room.\n";
        items = allocate(4);
        items[0] = "throne";
        items[1] = "A large golden throne, embedded in fine jewels";
        items[2] = "chandelier";
        items[3] = "A large chandelier, hanging from the tower ceiling";

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


