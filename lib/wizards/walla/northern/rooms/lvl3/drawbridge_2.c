inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {

if(arg) return;
       if (!monster) {
               monster = clone_object("/wizards/walla/northern/mobs/arukhelban.c");
               move_object(monster, this_object());
       }


        add_exit("east","/wizards/walla/northern/rooms/lvl3/drawbridge_1.c");

        short_desc = "You are outside the castle";
        long_desc = "You are walking outside the castle, there are trees around you\n"+
                    "and it looks like knights are using this place as their training\n"+
                    "zone. There are also some odd looking bushes nearby, who knows what\n"+
                    "there might be.\n";

        door_reset();
        set_door_label("Small wooden door",1);
        set_door_dir("west", "/wizards/walla/northern/rooms/lvl3/king_room.c",1);
        set_door_link("/wizards/walla/northern/rooms/lvl3/king_room.c",1);
        set_door_code("221", 1);
        set_locked(1, 1);

}

init() {
  ::init();
  door_init();
}

