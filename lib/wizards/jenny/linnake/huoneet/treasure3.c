inherit "room/room";
inherit "room/door";
int i;

reset(arg) {

        if (arg) return;

        i = 0;

        short_desc = "You are in a huge vault";
        long_desc = "You have entered a huge vault, there are only few items here, but\n"+ 
                        "because they were hidden this good they must be extremely\n"+
                        "powerful or extremely valuable. There is something strange\n"+
                        "in the corner.\n";

door_reset();
        set_door_label("A huge steel door",1);
        set_door_dir("south", "/wizards/jenny/linnake/huoneet/treasure2.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/treasure2.c",1);
        set_door_code("371", 1);
        set_locked(1, 1);

}

init() {
  ::init();
  door_init();

        items = allocate(2);
        items[0] = "corner";
        items[1] = "You see something interesting in the corner...";
}

search_finished(str) {
        if(!i && str == "corner") {
                object sceptre;
                write("You search the corner and discover Sceptre of the kings.\n");
                say(this_player()->query_name()+ " found something!\n");

                sceptre = clone_object("/wizards/jenny/linnake/rojut/sceptre.c");
                move_object(sceptre, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "sceptre") {
                write("You search the corner, but there was nothing you could use.\n");
                say(this_player()->query_name()+ " looks very sad.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
