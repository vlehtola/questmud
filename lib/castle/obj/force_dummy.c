string who;
drop() { return 1; }
get() { return 0; }
long() { write("plop"); return 1; }
short() { return "plop"; }
id(str) { return (str == "forcedummy"); }
set_who(arg) { who = arg; }
who() { return who; }
