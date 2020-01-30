inherit "room/room";
int i;

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/thief6.c");

        if(arg) return;
        i = 0;

        short_desc = "A hidden room";
        long_desc = "You have arrived into a small hidden room in the\n"+ 
                    "basement of the building. There is a sign hanging\n"+
                    "on the wall that reads: 'Treasure chamber'. Many\n"+
                    "piles of gold, silver, bronze and other coins are\n"+
                    "lying on the floor, some chests are placed in the\n"+
                    "corner of the room and some diamonds and other gems\n"+
                    "are glowing in open bags. You notice that one of the\n"+
                    "chests is different, it is made of wood, not gold\n"+
                    "and it seems that someone doesn't want you to pay\n"+
                    "any attention at all to it.\n";

        items = allocate(14);
        items[0] = "sign";
        items[1] = "'Treasure chamber'";
        items[2] = "coins";
        items[3] = "Loads of different type of coins are on the floor.";
        items[4] = "chests";
        items[5] = "A few golden chests are piled on the corner.";
        items[6] = "gems";
        items[7] = "Very valuable looking gems.";
        items[8] = "diamonds";
        items[9] = "Very valuable looking diamonds.";
        items[10] = "bags";
        items[11] = "The bags are filled with gems and diamonds.";
        items[12] = "chest";
        items[13] = "A wooden chest in a treasury, weird..it seems to be unlocked.";
}
 
search_finished(str) {
        if(!i && str == "chest") {
                object necklace;
                write("You open the wooden chest and discover a necklace inside it\n");
                say(this_player()->query_name()+ " found a necklace from a wooden chest\n");
                necklace = clone_object("/wizards/jenny/gnael/rojut/necklace.c");
                move_object(necklace, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "chest") {
                write("You open the wooden chest, but don't find anything inside it\n");
                say(this_player()->query_name()+ " looks frustrated\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " found nothing.\n");
        return 1;
}
