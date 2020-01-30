reset(arg) {
        if(arg) return;
}
short() {
        return "A circle of chaos";
}
id(str) {
        return str == "circle" || str == "circle_of_chaos";
}

long() {
write("Some one has carved on the floor a somekind of circle.\n");
}

drop() {
return 1;
}

get() {
return 0;
}

start_symbol(int i) {
call_out("dest_me", i);
}

dest_me() {
say("The circle fades away.\n");
destruct(this_object());
}
