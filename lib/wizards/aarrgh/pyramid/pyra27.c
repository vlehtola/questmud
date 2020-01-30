inherit "room/room";

reset(arg) {
            add_exit("northeast", "/wizards/aarrgh/pyramid/pyra25");
            short_desc = "In the puzzle";
            long_desc = "You are standing in the hall of puzzles...\n"+
                        "Walls are red and made of smooth bricks.\n"+
                        "They glow with blue light...\n"+
                        "You notice a rope hanging from the roof.\n";




items = allocate(4);
items[0] = "rope";
items[1] = "This rope is hanging from the roof.\n";

}

init() {
    ::init();
add_action("pull", "pull");
}

enter(str)  {
    if(str != "rope") return;
    write("As you pull the rope, you notice that it was mistake!.\n");
    write("Exit behind you closes!");
    say("The read wall moves aside!");
    remove_exit("northeast", "/wizards/aarrgh/pyramid/pyra25.c");
    return 1;

}
