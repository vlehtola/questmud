inherit "room/room";
int i;

reset(arg) {

        if(!present("knight")) {
                move_object(clone_object("/wizards/jenny/linnake/mosut/knight.c"), this_object());
        }

        if(arg) return;
        i = 0;

        add_exit("east","/wizards/jenny/linnake/huoneet/piha22.c");
        add_exit("southeast","/wizards/jenny/linnake/huoneet/piha18.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/piha17.c");

        short_desc = "You are outside the castle";
        long_desc = "You are walking outside the castle, there are trees around you\n"+ 
                        "and it looks like knights are using this place as their training\n"+
                        "zone. There are also some odd looking bushes nearby, who knows what\n"+
                        "there might be.\n";

        items = allocate(2);
        items[0] = "bushes";
        items[1] = "You see something glimmering in the bushes";
}

search_finished(str) {
        if(!i && str == "bushes") {
                object key;
                write("You search the bushes and find a key.\n");
                say(this_player()->query_name()+ " found something from the bushes.\n");
                key = clone_object("/wizards/jenny/linnake/rojut/pihakey.c");
                move_object(key, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "bushes") {
                write("You search the bushes, but there was only a piece of glass\n");
                say(this_player()->query_name()+ " looks very sad.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
