object shadow;

init() {
add_action("start","start");
}

start() {
                write("shadowing " + this_player()->short() + "\n");
                shadow = clone_object("/wizards/belar/shadow_example");
                shadow->start(this_player());
}                         
