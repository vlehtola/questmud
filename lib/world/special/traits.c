mapping trait;
string property;

reset(arg) {
  if (!arg)
      set_light(3);
  property = allocate(4);
  property[0] = "no_summon";
  property[1] = "no_kill";
  property[2] = "no_skill";
  property[3] = "no_spell";
  load_trait_data();
}

query_not_out() { return 1; }

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
        this_player()->quit();
        return 1;
    }
    this_player()->reset_traits();
    add_action("list", "list");
    add_action("select","select");
    add_action("continue_creation", "continue");
}

continue_creation() {
  write("Continuing character creation..\n");
  move_object(this_player(), "/world/special/slct_gui");
  call_other("world/special/slct_gui", "long");
  return 1;
}

long() {
  write(
"You can now select some special traits for you character, if you wish.\n"+
"They will affect your stats a little if you choose to take one or more of\n"+
"them. Available commands are:\n"+
"  list             - Show what special traits are available.\n"+
"  select <trait>   - Select a trait.\n"+
"  continue         - Continue character creation.\n");
}

short() {
    return "Special trait selection room";
}

query_trait_data(string name, string bonus) {
  int str, dex, con, Int, wis;
  string desc, st;
  st = trait[name];
  if(!st) return -1;
  if(sscanf(st, "%d %d %d %d %d:%s", str, dex, con, Int, wis, desc) != 6) {
    write("Error in traits data!\n");
    return -1;
  } else {
    switch(bonus) {
    case "str": return str;
    case "dex": return dex;
    case "con": return con;
    case "int": return Int;
    case "wis": return wis;
    case "long": return desc;
    }
    write("query_trait_data() [Error in argument 2!]\n");
  }
}

load_trait_data() {
  trait = ([ ]);
  trait += (["big":   "5 -5 0 0 0:tall but clumsy"]);
  trait += (["slick": "-7 5 0 0 0:agile but weak"]);
  trait += (["macho": "3 0 0 -10 -10:strong but dumb"]);
  trait += (["genius":"-5 -5 -7 5 5:intelligent but sickly"]);
  trait += (["wise":  "0 0 0 -7 5:wise but not smart"]);
  trait += (["hardy": "0 -3 5 -5 3:resistant but slow"]);
}

list() {
  object tp;
  int i, a, ii, bonus;
  string str, tmp, stats;
  stats = ({"str","dex","con","int","wis"});
  str = m_indices(trait);
  tp = this_player();
  a = m_sizeof(trait);
  write("You can choose from the following traits:\n");
  while(i< a) {
    if(tp->query_traits(str[i])) tmp = "[X] ";
    else tmp = "[ ] ";
    tmp += str[i]+" ("+query_trait_data(str[i], "long")+") ";
    while(ii < sizeof(stats)) {
      bonus = query_trait_data(str[i], stats[ii]);
      if(bonus) tmp += stats[ii]+" "+bonus+" ";
      ii += 1;
    }
    ii = 0;
    write(tmp+"\n");
    i += 1;
  }
  return 1;
}

select(string arg) {
  if(!arg) {
    write("Select which trait?\n");
    return 1;
  }
  if(!trait[arg]) {
    write("'"+arg+"' is not a valid trait.\n");
    return 1;
  }
  if(this_player()->query_traits(arg)) {
    write("You decide to remove the trait.\n");
    this_player()->set_trait(arg);
    return 1;
  }
  this_player()->set_trait(arg);
  write("You decide to select the '"+arg+"' trait.\n");
  update_traits(this_player());
  this_player()->update_stats();
  return 1;
}

update_traits(object tp) {
  int i, a, ii;
  string str, tmp, stats;
  stats = ({"str","dex","con","int","wis"});
  str = m_indices(trait);
  a = m_sizeof(trait);
  while(i< a) {
    if(tp->query_traits(str[i])) {
      while(ii < sizeof(stats)) {
        tp->set_stat_trait(stats[ii], query_trait_data(str[i], stats[ii]));
        ii += 1;
      }
      ii = 0;
    }
    i += 1;
  }
  return 1;
}
