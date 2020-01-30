inherit "room/room";
int i;

reset(arg) {

        if(!present("hummingbird")) {
                move_object(clone_object("/wizards/jenny/mehta/mosut/hummingbird.c"), this_object());
        }

        if(arg) return;
        i = 0;

        add_exit("down","/wizards/jenny/mehta/huoneet/forest13.c");
 
        short_desc = "An appletree";
        long_desc = "You are hanging from some branches on a huge appletree. There\n"+ 
                        "might be some apples somewhere in this tree if you can find\n"+
                        "them. Some birds are singing beautifully and the air is warm.\n"+
                        "You can see miles and miles away in every direction from here.\n";

        items = allocate(2);
        items[0] = "birds";
        items[1] = "Some robins are singing nearby.";

}

search_finished(str) {
        if(!i && str == "apples") {
                object apple;
                write("You look around and notice an apple and decide to pick it.\n");
                say(this_player()->query_name()+ " picks an apple.\n"); 
                apple = clone_object("/wizards/jenny/mehta/rojut/apple.c");
                move_object(apple, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "apples") {
                write("You look around, but cant find any apples.\n");
                say(this_player()->query_name()+ " bursts into tears.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " found nothing.\n");
        return 1;
}
