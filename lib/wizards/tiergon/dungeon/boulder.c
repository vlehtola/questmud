string short,long;
short() { return short; }
id(str) { return str == "boulder"; }

long(str) {
write(long);
    return;
}

init() {
    add_action("push", "push");
}

reset(arg) {
  if (arg) return;
  long = "This massive boulder prevents you from moving on.\n";
  short = "A huge boulder blocking the east wall";
}

push() {
call_other(environment(this_object()), "add_exit", "south", "/wizards/tiergon/dungeon/a7");
short = "A huge boulder";
long = "This massive boulder has been rolled against the north wall, leaving open a cave leading eastwards";
write("with a herculean effort, you roll the boulder from the wall.\n");
remove_action("push");
return 1;
}


