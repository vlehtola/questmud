
short() { return "A orb of light"; }

get() { return 0; }
drop() { return 1; }

id(str) { if (str == "orb") { return 1; } }

init() {
	add_action("pwho", "pwho");
}
pwho(str) {
 if(!str) { write("pwho <player>"); return 1; }
 call_other("/wizards/neophyte/_pwho.c", "cmd_pwho", str);
 return 1;
}
