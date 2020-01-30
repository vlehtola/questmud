short() {
    return "The void";
}

long() {
    write(short() + ".\n");
    write("You come to the void if you fall out of a room, and have nowhere to go.\n");
    write("Give the command 'inn', and you will come back to the inn.\n");
    write("\nYou are transfered to the inn...\n");
    call_other(this_player(), "move_player", "X#world/city/inn");
}

init() {
    add_action("church", "inn");
}

church() {
    call_other(this_player(), "move_player", "away#world/city/inn");
    return 1;
}

reset(arg)
{
    if (arg)
	return;
    set_light(3);
}

id(str) { return str == "void"; }
