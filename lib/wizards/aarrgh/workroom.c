inherit "room/room";

reset(arg) {
            add_exit("cs", "/world/city/cs");
            add_exit("nyx", "/wizards/aarrgh/nyxi/entrance.c");
            short_desc = "Void()";
            long_desc = "\n\n\n\n"
                        "\t\t   !!!!!  \n"
                        "\t\t  (.) (.) \n"
                        "\t\t     *    \n"
                        "\t\t    |||\n\n\n\n";

  /*
items = allocate(4);
items[0] = "nappula";
items[1] = "Paina nappulaa niin jotain tapahtuu\n";

}

init() {
    ::init();
add_action("paina", "paina");
}

paina(str) {
    if(str != "nappulaa") return;
    write("painat nappulaa ja jotain hassua tapahtuu.\n");
write("seinaan tuli reika!.\n");
    say("hoovee!\n");
    add_exit("reika", "/wizards/aarrgh/reika");
    return 1;
*/

}
