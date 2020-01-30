inherit "room/room";
inherit "room/door";
reset(arg) {

        add_exit("out","/wizards/jenny/linnake/huoneet/treasure1.c");

        short_desc = "The secret hideout";
        long_desc = "You have found a secret hideout, there are some torches burning\n"+
                    "on the wall and you can see huge steel door next to you. Some\n"+
                    "worms are crawling on the floor and the air smells awful. If\n"+
                    "you listen closely, you can hear the moaning coming from the\n"+
                    "prison.\n";

        door_reset();
        set_door_label("A huge steel door",1);
        set_door_dir("north", "/wizards/jenny/linnake/huoneet/treasure3.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/treasure3.c",1);
        set_door_code("371", 1);
        set_locked(1, 1);

}

init() {
  ::init();
  door_init();
}
