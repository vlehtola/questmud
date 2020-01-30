inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
        if(arg) return;
        add_exit("south","/guilds/warlock/warlock4");
        add_exit("north","room7");
        short_desc = "Inside the cathedral";
        long_desc = "A great power can all but be tasted in the air, hanging like an oily film over the ground. " +
                    "Webs hang like tattered shrouds from every corner, and a dessicated body of a rat hangs " +
                    "wrapped in spider silk from the roof. On one of the corpse-gray walls, is a cabinet, six feet " +
                    "high by three feet wide by two feet deep, which holds a multitude of tiny drawers, each meticulously " +
		    "labeled in a language that you cannot comprehend. A horsehide chair sits in one dimly lit corner.\n";
        items = allocate(2);
        items[0] = "cabinet";
        items[1] = "A large cabinet with labeled drawers. The cabinet looks somehow strange";
        property = allocate(1);
        property[0] = "no_summon";
}
query_startroom() { return 1; }

init() {
::init();
add_action("push", "push");
}
push(str) {
if(!str) {
write("Push what.\n");
return 1;
}
if(str != "cabinet") {
write("Push what?\n");
return 1;
}
write("You push the cabinet revealing a secret entrance to dark chamber.\n");
if(!this_player()->query_quests("Find the secret chamber of warlocks")) {
write("You have accomplished the task 'Find the secret chamber of warlocks'\n");
write("You feel like you have done a favour to the dark gods.\n");
this_player()->set_quest("Find the secret chamber of warlocks");
WARLOCK_D->add_souls(this_player()->query_real_name(), 10000);
WARLOCK_D->add_demon_xp(this_player()->query_real_name(), 1000000);
}
write("You quickly enter the chamber without nobody seeing you.\n");
move_object(this_player(), "/guilds/warlock/warlock6");
return 1;
}

