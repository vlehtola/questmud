inherit "room/room";

reset(arg) {
            add_exit("east", "/wizards/aarrgh/pyramid/pyra25");
            short_desc = "In the puzzle";
            long_desc = "You are standing in the hall of puzzles...\n"+
                        "Walls are red and made of smooth bricks.\n"+
                        "They glow with blue light...\n"+
                        "You notice a handle in the center of the room.\n";


items = allocate(4);
items[0] = "handle";
items[1] = "A handle.\n";

}

init() {
    ::init();
add_action("squeeze", "squeeze");
}

enter(str)  {
    if(str != "handle") return;
    write("Gongratulations, You made it!.\n");
    write("As you squeeze the handle, rear wall moves aside!");
    say("The read wall moves aside!");
    add_exit("west", "/wizards/aarrgh/pyramid/osiris.c");
    return 1;

}
