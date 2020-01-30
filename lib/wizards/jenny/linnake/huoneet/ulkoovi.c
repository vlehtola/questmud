inherit "room/room";
inherit "room/door";
reset(arg) {
object monster;
        if(!present("knight")) {
            move_object(clone_object("/wizards/jenny/linnake/mosut/knight.c"), this_object());
        }
        if(arg) return;

        add_exit("east","/wizards/jenny/linnake/huoneet/piha8.c");

        short_desc = "You are outside the castle";
        long_desc = "You are walking outside the castle, there are trees around you\n"+
                    "and it looks like knights are using this place as their training\n"+
                    "zone. There are also some odd looking bushes nearby, who knows what\n"+
                    "there might be.\n";

        door_reset();
        set_door_label("Small wooden door",1);
        set_door_dir("west", "/wizards/jenny/linnake/huoneet/sisaovi.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/sisaovi.c",1);
        set_door_code("471", 1);
        set_locked(1, 1);

}

init() {
  ::init();
  door_init();
}
