inherit "room/room";
int i;
reset(arg)
{
if(arg) return;
i = 0;

short_desc = "Duranghom's windmill.";
long_desc =
"You are standing in a large windmill. There are\n" +
"few windows for daylight to shine in. Several sacks of\n" +
"flour are piled in every corner here. Dark figure of a\n" +
"a mill mechanism can be seen ahead.\n";
add_exit("out", "wm7.c");
add_exit("north", "wm9.c");

items = allocate(2);
        items[0] = "sack";
        items[1] = "You see many flour sacks everywhere.";
}
search_finished(str) {
        if(!i && str == "sacks") {
                object sack;
                write("You finish searching and find a sack with name village's baker on it.\n");
                say(this_player()->query_name()+ " starts to search the room.\n");
                sack = clone_object("/wizards/yodin/areas/windmill/obj/floursack.c");
                move_object(sack, this_player());
                i = 1;
                return 1;
        }
        if(i && str == "sacks") {
                write("You search from everywhere, but don't find the right sack.\n");
                say(this_player()->query_name()+ " seems to be covered with white flour.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
