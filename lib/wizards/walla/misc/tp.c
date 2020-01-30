mapping list;
int i=0;
 
reset(arg) {
  if (!arg) { return; }
  restore_object("/wizards/walla/misc/warlock_signup.o");
  if (!list) {
    list = ([ ]);
  }
}
 
short() { return "Warlock sign up plaque"; }
long() {
write("Warlocks as of 30.01.03 \n");
write("----------------\n");
write("|1. Shadowman  |\n");
write("|2. Hemies     |\n");
write("|3. Razarac    |\n");
write("|4. Bloodstorm |\n");
write("|5. Terror     |\n");
write("----------------\n");
write("This is the Warlock signup plaque. You may add your name here,\n");
write("and be added to the queue in joining the Warlock guild. Only\n");
write("5 warlocks are allowed in the game at the same time. When\n");
write("someone reincs out of warlocks, the person next in line will\n");
write("be granted an option to join the warlock guild. Admittance\n");
write("will be selected in order of signing up. A player may decline\n");
write("the honor of joining, if for some reason he does not wish to\n");
write("join the Warlock guild at that time. The player next in line\n");
write("is then the one that may join the guild.\n");
write("Available commands: list, signup\n");
}
 
id(str) { if (str == "plaque") { return 1; } }
 
init() {
  add_action("list","list");
  add_action("signup","signup");
}
 
signup(str) {
  string name;
  name = this_player()->query_name();
  if (list[name]) { write("You already are signed up.\n"); }
  if (!str) { str = "coming"; } 
  if (strlen(str) > 30) { write("Too long argument.\n"); }
  list[name] = str;
  write("You join the queue for the warlock guild.\n");
 
  save_file("/wizards/walla/misc/warlock_signup.o");
  return 1;
}
 
list() {
  string names, args;
  names = m_indices(list);
  write("Warlock queue:\n");
  while (i < sizeof(list)) {
    write(names[i]+", "+args[i]+"\n");
    i += 1;
  }
  return 1;
}

