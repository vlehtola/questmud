object shadow;

init() {
add_action("start_s","start_s");
add_action("stop_s","stop_s");
}

start_s() {
                write("Shadowing " + this_player()->short() + "\n");
                shadow = clone_object("/wizards/rag/misc/shadow");
                shadow->start(this_player());
                return 1;
}                         

stop_s() {
        shadow->self_destruct();
        return 1;
}
