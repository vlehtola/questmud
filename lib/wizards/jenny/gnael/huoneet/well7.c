inherit "room/room";
inherit "room/door";
reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/well6.c");        

    short_desc = "Inside the well";
    long_desc = "You are walking in a gloomy looking dungeon\n"+
              "inside the city well. The place is very wet and there\n"+
              "are many spider webs everywhere, walls are made of some\n"+
              "unknown dark material and there are no visible light sources\n"+
              "anywhere near. You can hear some horrible screams coming\n"+
              "from deeper, this surely is not a good place for anyone.\n";

        door_reset();
        set_door_label("A huge door made of gold",1);
        set_door_dir("south", "/wizards/jenny/gnael/huoneet/well8.c",1);
        set_door_link("/wizards/jenny/gnael/huoneet/well8.c",1);
        set_door_code("803", 1);
        set_locked(1, 1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
