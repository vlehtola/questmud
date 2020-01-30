inherit "room/room";
inherit "room/door";
int door_number;
reset (arg) {
    if(arg) return;                                                                     
        short_desc = "Navigator street";
        long_desc = "+#####+ You are walking on the navigator street, which\n"+
                    "|##G##| continues to east and west. The street is very\n"+
                    "+--*--+ clean and in good condition. Brick houses are\n"+
                    "|#####| built in the south block. To the north is the\n"+
                    "+#####+ entrance to a graveyard. The graveyard is\n"+
                    "        surrounded by high fence. There is a gate\n"+
                    "        leading to the graveyard. Beside the gate is\n"+
                    "        a sign.\n";
     add_exit("west","/wizards/neophyte/city/schooner3");
     add_exit("east","/wizards/neophyte/city/sailor3");
    door_reset();
    door_number = 1;
    set_door_label("bone door", 1);
    set_door_dir("north", "/wizards/neophyte/city/graveyard/room1", 1);
    set_door_link("/wizards/neophyte/city/graveyard/room1", 1);
    set_door_code("4632", 1);
}

init() {
   ::init();
   door_init();
   add_action("map", "map");
   add_action("knock_door", "knock");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/neophyte/city/map");
   return 1;
}
knock_door(str) {
        if(!str || str != "door") { write("Knock what?\n"); return 1; }
        write("You knock on the door.\n");
        say(this_player()->query_name()+" knocks on the door.\n");
        tell_room("/wizards/neophyte/city/graveyard/room1", "Somebody knocks the door.\n");
        return 1;
}
