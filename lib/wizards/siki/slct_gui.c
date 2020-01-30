#define GUILD "/guilds/guilds/guild"
#define WARLOCK_D "/daemons/warlock_d"
string *property;
mapping guilds;

successful_select();

void reset(status arg) {
  if(arg) return;
  set_light(3);
  property = ({ "no_summon", "no_kill", "no_skill", "no_spell", });
  guilds = ([ "fighter":"Fighters";"/guilds/fighter/fighter";"/guilds/fighter/description";0;0,
              "mage":"Apprentice Mages";"guilds/mage/apprmage";"/guilds/mage/description";0;0,
              "necromancer":"necromancers";"guilds/necro/base_guild";"/guilds/necro/description";1000000;0,
              "abjurer":"abjurers";"guilds/abjurer/abjurers";"/guilds/abjurer/description";1000000;0,
              "cleric":"Apprentice clerics";"guilds/channel/appr_cleric";"/guilds/channel/description";0;0,
              "psionic":"Psionicists";"guilds/psi/psiguild";"/guilds/psi/description";0;0,
              "warlock":"Warlocks";"guilds/warlock/warlock";"/guilds/warlock/description";0;0,
           ]);
}
status query_not_out() { return 1; }
query_property(str) {
    int i;
    if (str == 0)
        return property;
    if (!property)
        return 0;
    if (stringp(property))
        return str == property;
    while(i < sizeof(property)) {
        if (property[i] == str)
            return 1;
        i += 1;
    }
    return 0;
}

init() {
    if(this_player()->query_level() > 2 &&
        !this_player()->query_wiz()) {
        write("You already have a guild.\n");
        this_player()->quit();
        return 1;
    }
    add_action("info","info");
    add_action("select","select");
    add_action("list","list");
    add_action("alignment", "alignment");
}

void long() {
  write(
"You must select a base guild for your character. There are several different\n"+
"possibilities. Your guild determinates what skills you will be able\n"+
"to train. However, it's possible to join into multiple guilds.\n"+
"It's recommanded to see 'help guilds' for general information.\n"+
"Some brief information can be seen with 'info <guild>'.\n"+
"When you have decided, type: select <guild>.\n"+
"You can also select your alignment: alignment <good|neutral|evil>\n\n"+
"See the available guilds by typing: list\n");
}

alignment(string str) {
if(!str) {
write("Usage:  alignment <good|neutral|evil>\n");
return 1;
}
if(lower_case(str) == "good") {
this_player()->set_al(50);
write("Your alignment is now good.\n");
return 1;
}
if(lower_case(str) == "neutral") {
this_player()->set_al(0);
write("Your alignment is now neutral.\n");
return 1;
}
if(lower_case(str) == "evil") {
this_player()->set_al(-50);
write("Your alignment is now evil.\n");
return 1;
}
write("Usage:  alignment <good|neutral|evil>\n");
return 1;
}
string short() {
    return "Guild selection room";
}

status list() {
  string *tmp;
  int i;
  tmp = m_indices(guilds);
  write("These guilds are currently available to select:\n");
  for(i=0;i<sizeof(tmp);i++) write(tmp[i]+"\n");
  write("Select one of these with select <guild> command.\n");
  return 1;
}

status info(string str) {
  int req, limit;
  if(str) str = lower_case(str);
  if(!guilds[str]) {
    write("There's no such guild.\n");
    return 1;
  }
if(file_size(guilds[str,2]) > 10) write(read_file(guilds[str,2]));
else write("No information available.\n");
req = guilds[str,3];
if(req) {
req = req/1000000;
write("This guild requires "+req+"M points of experience.\n");
}
limit = guilds[str,4];
if(limit) {
write("This guild don't accept joiners if they have totals above the "+limit+"G points of experience.\n");
}
return 1;
}

status select(string str) {
	int free_exp;
  if(!str) { write("Select which guild?\n"); return 1; }
  str = lower_case(str);
  if(!guilds[str]) {
    write("There's no such guild.\n");
    return 1;
  }
  if(strlen(""+guilds[str,3]) > 2 && strlen(this_player()->query_free_exp()) < strlen(""+guilds[str,3])) {
    write("Sorry, but you aren't experienced enough.\n");
    return 1;
  }
  if(capitalize(str) == "Warlock" && WARLOCK_D->query_invite(this_player()->query_real_name()) == 0) {
  write("You can't join the warlock guild because you don't got the invition.\n");
  return 1;
  }
  if(capitalize(str) == "Warlock" && this_player()->query_alignment() > -1) {
  write("Warlocks don't accept pure hearted joiners.\n");
  return 1;
  }

  if(this_player()->query_tester()) write("Starter guild set as "+guilds[str, 1]+".\n");
  this_player()->set_starter_guild( ({ guilds[str, 0], guilds[str, 1], }) );

  this_player()->advance_guild_level(guilds[str,0]);
  GUILD->starter_guild_advance(guilds[str, 0], ({ guilds[str, 0], guilds[str, 1], }), this_player());

  write("You are now a member of the "+capitalize(str)+" guild!\n");
  write("Remember that you can always join other guilds, if you pass\n");
  write("their joining requirements!\n");

  successful_select();
  move_object(this_player(),guilds[str,1]);
  this_player()->look();
  return 1;
}

successful_select() {
    this_player()->drink_soft(1000000);
    this_player()->eat_food(1000000);
    this_player()->heal_self(1);
    write("First of all read HELP NEWBIE by typing 'help newbie'.\n\n");
  this_player()->set_skill("/daemons/race_stats"->query_race_stat(this_player()->query_race(), "bonus_skill"), 20);
}

query_guilds() { return guilds; }


