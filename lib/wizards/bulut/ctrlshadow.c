object shadow;

init() {
add_action("start","start");
}

start() {
                write("shadowing " + this_player()->short() + "\n");
                shadow = clone_object("/wizards/bulut/shadow_example");
                shadow->start(this_player());
}                       
