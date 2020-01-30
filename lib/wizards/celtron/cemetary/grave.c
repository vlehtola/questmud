inherit "room/outroom";
int guild_exit;

set_guild_exit() {
  guild_exit = 1;
}

init() {
  ::init();
  if(guild_exit) add_action("do_guild_exit", "push");
}

do_guild_exit(string str) {
  if(str != "tombstone") return 0;
  write("You push the tombstone and a hole opens beneath you. You fall down!\n");
  say("A hole opens beneath "+this_player()->query_name()+" and "+this_player()->query_pronoun()+" falls down!\n");
  say("The hole closes as quickly as it had appeared.\n");
  move_object(this_player(), "/guilds/necro/control2");
  return 1;
}

start() {
  mapfile = "/wizards/celtron/cemetary/virtual_map";
  short_desc = "An old grave";
  long_desc = "A spooky tombstone stands alone on the ground.\n"+
	      "Some rocks has been piled near it to cover an old grave.\n";
}
reset() {
  ::reset();
  if(!present("undead") && !random(3)) {
    move_object(clone_object("/wizards/celtron/cemetary/undead"), this_object());
  }
}

