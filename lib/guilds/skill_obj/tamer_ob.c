object tmp;
start(object ob) {
tmp = ob;
}

id(str) { return str == "tamer_obj"; }

get() { return 1; }
drop() { return 1; }
move_test() {
        move_object(tmp, environment(this_player()));
        tell_room(environment(tmp), tmp->short()+" arrives from somewhere.\n");
        return 1;
}
