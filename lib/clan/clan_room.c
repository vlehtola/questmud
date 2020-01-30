inherit "room/room";
#define CLAN_D "/clan/clan_d"

status command(string arg) {
  string tmp;
  if(!arg) {
    write("See the plaque for information about this command.\n");
    return 1;
  }

  /* //Celtron */
  write("Clans are disabled. Have a nice day.\n");
  return 1;

  if(sscanf(arg, "create %s", tmp) == 1) {
    CLAN_D->create_clan(tmp);
    return 1;
  }
  if(sscanf(arg, "info %s", tmp) == 1) {
    CLAN_D->info_clan(tmp);
    return 1;
  }
  if(sscanf(arg, "invite %s", tmp) == 1) {
    CLAN_D->invite_clan(tmp);
    return 1;
  }
  if(arg == "leave" || sscanf(arg, "leave %s", tmp) == 1) {
    CLAN_D->leave_clan(tmp);
    return 1;
  }
  if(arg == "join") {
    CLAN_D->join_clan(tmp);
    return 1;
  }
  if(arg == "score") {
    CLAN_D->display_scores(tmp);
    return 1;
  }
  if(arg == "history") {
    CLAN_D->display_history(tmp);
    return 1;
  }
}

status see_plaque(string arg) {
  if(arg != "at plaque") return 0;
  write("Available commands:\n");
  write("  clan create <clan name> - creates a clan, in which you are the leader\n");
  write("  clan invite <player>    - invites a player to you clan\n");
  write("  clan join               - join a clan you have been invited to\n");
  write("  clan leave              - leave your clan\n");
  write("  clan score              - shows the current scores of active clans\n");
  write("  clan info <clan name>   - shows information about a clan\n");
  write("  clan history            - displays deceased clans\n");
  return 1;
}

void init() {
  ::init();
  add_action("command", "clan");
  add_action("see_plaque", "look");
  add_action("see_plaque", "l");
}

void reset(status arg) {
  if(arg) return;
  short_desc = "The clanroom";
  long_desc =
"Several torches on walls give light to this big hall.\n"+
"There is a cleric behind a desc situated near the northern\n"+
"wall. He keeps up the records of active and deceased clans.\n"+
"A plaque is hanging from the eastern wall, it explains what\n"+
"services one can get in here.\n";
  add_exit("east", "/world/city/copper2");
}

