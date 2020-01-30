inherit "room/room";

reset(arg) {
            add_exit("south", "/wizards/aarrgh/pyramid/pyra15");
            short_desc = "In The Pyramid";
            long_desc = "You are standing in the pyramid of Osiris...\n"+
                        "Walls are very old and made of smooth bricks.\n"+
                        "They are full of strange writing...\n"+
                        "You must admit, that this pyramid is one of the\n"+
                        "finest building you have ever seen. You notice\n"+
                        "something strange in one of the bricks...\n";
items = allocate(4);
items[0] = "brick";
items[1] = "This brick seems to be loose...\n";

}

init() {
    ::init();
add_action("push", "push");
}

push(str)  {
    if(str != "push") return;
    write("You push the brick and the whole wall crumbles to dust.\n");
    say("The wall crumbles to dust");
add_exit("north", "/wizards/aarrgh/pyramid/pyra21.c");
    return 1;

}
