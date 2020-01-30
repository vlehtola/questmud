#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monsu;
int bucket_found;
string invited;

extra_reset() {
    if (!monsu) {
        monsu = clone_object("/world/monsters/ant1.c");
        move_object(monsu, this_object());
    }
}

init() {
    ::init();
    if (invited != lower_case(this_player()->query_name()) &&
	    this_player()->query_name() != "Onarion" && 
	    this_player()->query_name() != "Onatest" && 
	    !this_player()->query_npc()) {
	write("You are not invited.\n");
	say(this_player()->query_name() + " tried to enter.\n");
	this_player()->move_player("X#world/city/inn");
	return 1;
    }
    add_action("search", "search");
    add_action("invite", "invite");
}

invite(str) {
    if (!str) { write("Invite who?\n"); return 1; }
    invited = str;
    write("You allow " + capitalize(str) + " to enter.\n");
    return 1;
}

long(str) {
    ::long(str);
    if (str == "sign") {
 	write("A sign.\n");
    }
    if (str == "water") {
	if (bucket_found) {
	    write("Just water.\n");
  	}
	else {
	    write("Something in it\n");
	}
    }
    if (str == "picture") {
	cat("/wizards/korel/PICTURE");
    }
}

id(str) {
    ::id(str);
    if (str == "water") { return 1; }
    if (str == "sign") { return 1; }
    if (str == "picture") { return 1; }    
}
search(str) {
    if (str == "water") {
        if (bucket_found) {
	    write("You search in the water but find nothing but mud.\n");
	    return 1;
	}
 	write("You search the water and find a rusty bucket in it!\n");
	move_object("/wizards/korel/objects/bucket.c", this_player());
	bucket_found = 1;
        return 1;
    }
    write("Search what?\n");
    return 1;
}

FOUR_EXIT("world/city/inn", "inn",
"world/hallway/hall", "hallway",
"world/city/post", "post",
"world/mage/tower1", "mage",
"Onarion's workroom",
"This is Onarion's workroom, better not to spam him.\n" +
"Especially when he is working. There is a sign.\n", 3)


