inherit "room/room";
status cavern;

reset(arg) {
            add_exit("south", "/wizards/irmeli/nyx/ruins2.c");
            remove_exit("cavern");
            cavern = 0;

            short_desc = "A small terrance on a descent mountainside";
long_desc = "A small terrance has been carved on a descent mountainside. The lava rock\n"+
            "field spreads as far as your eyes can reach, covering everything beneath.\n"+
            "The bedrock is stony, dull and contaminated. A huge ash-coloured rock is\n"+
            "on the terrance. A pair of hardened footsteps ends to the rock.\n";

items = allocate(4);
items[0] = "rock";
items[1] = "A huge, ash-coloured rock has been here for ages. The lava flow moved the rock to here, from the top of the mountain, when the volcano throwed belches out fire and ashes";
items[2] = "footsteps";
items[3] = "A pair of medium-sized, hardened footsteps ends to the huge rock";

}
int rock_pushed;        
init() {
    ::init();
add_action("push", "push");
}

push(str)  {
    if(str != "rock" || cavern) return;
    write("You push the huge rock aside and a mouth of a cavern, carved on the mountainside, reveals behind the rock.\n");
    say(this_player()->query_name()+" pushes the huge rock aside, revealing a cavern behind it.\n");
    cavern = 1;
    add_exit("cavern", "/wizards/irmeli/nyx/cavern.c");
    this_player()->set_quest("find_cavern", 2);
    return 1;
}
