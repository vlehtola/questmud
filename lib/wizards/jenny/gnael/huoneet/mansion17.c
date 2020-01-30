inherit "room/room";
int i;

reset(arg) {

        add_exit("up","/wizards/jenny/gnael/huoneet/mansion16.c");

        if(arg) return;
        i = 0;

        short_desc = "In the basement";
        long_desc = "You have arrived into a dark basement, it seems like no one has\n"+ 
                        "cleaned in here ages. There are some barrels in the corner\n"+
                        "and a rotten smell comes from them. Many spider webs are covering\n"+
                        "the basement and you can hear a few rats running on the floor.\n"+
                        "It is hard to breath in here because the air is so old and dusty,\n"+
                        "you don't feel very comfortable here.\n";

        items = allocate(6);
        items[0] = "barrels";
        items[1] = "Wooden barrels, some of them are open";
        items[2] = "rats";
        items[3] = "You can hear the rats running on the floor";
        items[4] = "webs";
        items[5] = "Ancient looking spider webs are covering the whole room";

}
 
search_finished(str) {
        if(!i && str == "barrels") {
                object meat;
                write("You take a piece of rotten meat from one of the barrels\n");
                say(this_player()->query_name()+ " takes a piece of rotten meat from a barrel\n");
                meat = clone_object("/wizards/jenny/gnael/rojut/meat.c");
                move_object(meat, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "barrels") {
                write("You open few barrels, but you only find dead rats inside them\n");
                say(this_player()->query_name()+ " got a disgusting look on his face\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
