inherit "room/room";

int looked;
string portaali;

reset(arg) {
set_light(1);
set_not_out(1);
set_water(3);
            add_exit("up", "/wizards/aarrgh/nyxi/pool.c");
            short_desc = "In the pool";
long_desc = "This is the center of pool filled with blood and guts. The pool is made of a\n"
            "pure marble and is decorated with human skulls. The pool is not deep and a\n"
	    "strange red orb attached on the floor can be noticed. It stands on a pedestal\n"
            "made of stone. The orb emits red light.\n";

items = allocate(4);
items[0] = "orb";
items[1] = "This orb seems to be made of some magical crystal";

}

init() {
    ::init();
add_action("turn1", "turn");
}

turn1(str)  {
    if(str != "orb"  ) {

	write("Turn what?\n");
	return 1;
	}

    if(str == "orb" && portaali == 1) {

	write("The portal is already opened.\n");
	return 1;
}

    if(str == "orb" || portaali != 1 ) {
write("You turn the orb and a fiery portal appears to the north wall!\n");
say("As "+this_player()->query_name()+" turns the orb, a fiery" +
    " portal appears to the north wall.\n");
this_player()->set_quest("Open the flaming portal");
    call_other("/wizards/aarrgh/nyxi/volcano8.c",
	"add_exit","portal","/wizards/aarrgh/nyxi/portal.c");
    tell_room("/wizards/aarrgh/nyxi/volcano8.c",
	"Suddenly the north wall bursts in flames and a portal opens!\n");
    call_out("remove_portal", 60);

	portaali = 1;

    return 1;

}
}
//set_looked() { looked = 1; }

remove_portal() {
    call_other("/wizards/aarrgh/nyxi/volcano8.c",
	"remove_exit","portal");
    tell_room("/wizards/aarrgh/nyxi/volcano8.c",
	"The flames in the portal die and it vanishes.\n");

	portaali = 0;
}
