inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/well2.c");
        add_exit("out","/wizards/jenny/gnael/huoneet/city31_cs.c");

    short_desc = "Inside the well";
    long_desc = "You are walking in a gloomy looking dungeon\n"+
              "inside the city well. The place is very wet and there\n"+
              "are many spider webs everywhere, walls are made of some\n"+
              "unknown dark material and there are no visible light sources\n"+
              "anywhere near. You can hear some horrible screams coming\n"+
              "from deeper, this surely is not a good place for anyone.\n";

  set_not_out(1);

        items = allocate(4);
        items[0] = "webs";
        items[1] = "Terrible looking spider webs are covering almost everything here";
        items[2] = "walls";
        items[3] = "These walls look abnormal, they surely are not from this world";

}
