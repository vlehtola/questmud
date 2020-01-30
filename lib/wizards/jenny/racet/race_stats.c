/* this daemon handles all race abilities and stats // Celtron */

#define XP_RATE_D "/daemons/xp_rate_d"

mapping races;

reset(arg) {
  if(arg) return;
  races = ([ ]);
  /*                          hpr      spr    str  dex   con   int   wis   size          skc    spc     xp  prot   bg-sk */
  /* Fighters */
  races += ([ "giant":      ({"high", "low", "90", "45", "75", "30", "45", "huge",      "med", "high", "80", "",    "attack", }) ]);
  races += ([ "ogre":       ({"high", "low", "75", "60", "60", "45", "30", "large",     "low", "high", "95", "low", "stun", }) ]);
  races += ([ "orc":        ({"high", "low", "60", "60", "60", "45", "30", "normal",    "low", "high","105", "",    "blades", }) ]);
  races += ([ "troll":      ({"spec", "low", "75", "75", "75", "30", "45", "large",     "high","high", "90", "low", "bludgeons", }) ]);
  /* Semi-fighters */
  races += ([ "dwarf":      ({"high", "med", "75", "45", "60", "30", "45", "small",     "spec", "med", "90", "high","axes", }) ]);
  races += ([ "human":      ({"high", "med", "60", "60", "60", "60", "60", "normal",    "med",  "med","100", "",    "parry", }) ]);
  races += ([ "hobbit":     ({"high", "med", "45", "75", "60", "30", "45", "very small","low",  "med","100", "",    "dodge", }) ]);
  races += ([ "dark elf":   ({"med", "high", "60", "75", "60", "75", "60", "normal",    "med",  "med", "80", "",    "critical", }) ]);
  /* Clerics */
  races += ([ "ent":        ({"med", "high", "60", "30", "60", "45", "75", "huge",      "high", "spec","85", "low", "cast minor", }) ]);
  races += ([ "lizardman":  ({"med", "high", "45", "30", "45", "60", "75", "large",     "high", "low","100", "",    "chanting", }) ]);

  races += ([ "wood elf":   ({"med", "high", "30", "45", "60", "45", "90", "small",     "high", "med", "90", "",    "cast heal", }) ]);
  /* Mages */
  races += ([ "catfolk":    ({"low", "high", "30", "45", "45", "75", "45", "small",     "high", "low","105", "",    "cast essence", }) ]);
  races += ([ "high elf":   ({"low", "high", "45", "30", "60", "90", "60", "normal",    "high", "med", "85", "",    "cast bolt", }) ]);
  races += ([ "gnome":      ({"low", "high", "45", "30", "60", "75", "45", "very small","high", "spec","90", "",    "cast fire", }) ]);
  races += ([ "mind flayer":({"low", "spec", "45", "30", "45", "75", "60", "normal",    "high", "low", "90", "",    "cast ice", }) ]);

  /* REBIRTH RACES */

  races += ([ "golem":      ({"high", "med", "90", "45", "90", "45", "45", "huge",	"low", "high","90", "high","berserk", }) ]);
  races += ([ "angel":      ({"high", "high","75", "75", "75", "75", "75", "normal",	"med", "med", "90", "",	 "tumble", }) ]);
  races += ([ "lich":       ({"med",  "high","45", "45", "60", "90", "90", "normal",	"high", "low","90", "","mana control",}) ]);


/*
  races += ([ "": ({"", "", "", "", "", "", "", "", "", "", "", "", "", }) ]);
*/
/* put your tune here. */
  races["dwarf"] = ({"high", "med", "75", "45", "60", "30", "45", "small",     "spec", "med", "85", "high","axes", }); /* reason bg */

}

query_races() {
  return m_indices(races);
}

get_stat_slot(string stat) {
  string slots;
  int i;
  slots = ({ "hpr", "spr", "str", "dex", "con", "int", "wis", "size", "skill_cost", "spell_cost", "exp_rate", "resist",
		"bonus_skill", });
  if(stat == "hpregen" || stat == "hp_regen") stat = "hpr";
  if(stat == "spregen" || stat == "sp_regen") stat = "spr";
  while(i<sizeof(slots)) {
    if(slots[i] == stat) return i;
    i += 1;
  }
  return -1;
}

query_race_info(string race) {
  string tmp, adj, stats, file, str;
  int value, i, tmp_xp;
  file = race;
  while(sscanf(file,"%s %s",file,tmp) == 2) {
    file = file + "_" + tmp;
  }
  file = "/data/races/"+file;
  if(file_size(file) == -1) {
    write("No such race.\n");
    return 0;
  }
  cat(file); /* Show race desc */
  write("\n");
  stats = ({ "Strength", "Intelligence", "Dexterity", "Wisdom", "Constitution", "Size", "Hpregen", "Spregen",  }); 

  str = "";
  while(i<sizeof(stats)) {
    if(stats[i] == "Size") str += "Size: "+races[race][7];
    else if(i >= 6) str += stats[i]+": "+change_adj(races[race][i-6]);
    else str += stats[i]+": "+get_adj(query_race_stat(race, lower_case(extract(stats[i],0,2))) );

    if(i/2*2 == i) {
      str += extract("                                               ", 0, 35-strlen(str));
    } else {
      write(str+"\n");
      str = "";
    }
    i += 1;
  }
  write("\n");
  tmp_xp = XP_RATE_D->query_race_xp_rate(race);
  if(!tmp_xp) tmp_xp = races[race][10];
  write("They receive "+tmp_xp+"% of experience gained.\n");
  write("They learn craft skills "+change_adj(races[race][8], 1)+".\n");
  write("They master arcane powers "+change_adj(races[race][9], 1)+".\n");
  write("They have some knowledge in skill '"+races[race][12]+"'.\n");
  if(query_race_stat(race, "can_eat_corpses"))
    write("They can survive by eating corpses.\n");
  adj = races[race][11];
  if(adj != "")
    write("They have a "+adj+" resistance against natural elements.\n");
}

change_adj(string str, int alt) {
  if(alt) {
  switch(str) {
  case "spec": return "very easily";
  case "low":  return "in short time";
  case "med":  return "with some practice";
  case "high": return "with much trouble";
  }
  }
  switch(str) {
  case "med": return "mediocre";
  case "spec": return "very high";
  }
  return str;
}

/* huom! value on numero stringina */
get_adj(int value) {
  switch(value) {
  case 30: return "poor";
  case 45: return "low";
  case 60: return "average";
  case 75: return "good";
  case 90: return "excellent";
  }
  return "invalid value";
}

query_race_stat(string race, string stat, int info) {
  int slot, value;
  string data;
  if(!race || !stat) return 0;
  if(race == "visitor" || this_player()->query_guest()) return 0;
  /* infran saa nopeesti */
  if(stat == "infra") {
    switch(race) {
    case "dark elf": return 3;
    case "mind flayer": return 2;
    case "dwarf": return 2;
    case "troll": return 2;
    case "gnome": return 2;
    case "wood elf": return 1;
    case "high elf": return 1;
    case "catfolk": return 1;
    case "orc": return 1;
    }
    return 0;
  }
  if(stat == "can_eat_corpses") {
    switch(race) {
    case "orc":
    case "troll":
    case "mind flayer":
    case "catfolk": return 1;
    }
    return 0;
  }
  if(stat == "rebirth") {
    switch(race) {
    case "golem":
    case "angel":
    case "lich": return 1;
    }
    return 0;
  }
  slot = get_stat_slot(stat);
  if(!race || slot == -1)
    log_file("RACE_STATS", ctime(time())+" "+this_player()->query_name()+" race: "+race+" slot: "+slot+" stat: "+stat+
		" prev_ob: "+file_name(previous_object())+"\n", 1);

  data = races[race][slot];
  slot += 1;
  /* hp & sp regen */
  if(slot == 1 || slot == 2) {
    if(info) return data;
    switch(data) {
    case "low": return 30;
    case "med": return 80;
    case "high": return 150;
    case "spec": return 200;
    }
    return -1;
  }
  /* stats */
  if(slot >= 3 && slot <= 7) {
    if(sscanf(data, "%d", value) != 1) return -1;
    return value;
  }
  /* size */
  if(slot == 8) {
    if(info) return data;
    switch(data) {
    case "very small": return 25;
    case "small": return 40;
    case "normal": return 60;
    case "large": return 80;
    case "huge": return 100;
    }
    return -1;
  }
  /* skill and spellcosts in percents */
  if(slot == 9 || slot == 10) {
    if(info) return data;
    switch(data) {
    case "high": return 300;
    case "med":  return 180;
    case "low":  return 100;
    case "spec": return 75;
    }
    return -1;
  }
  /* xprate */
  if(slot == 11) {
    int tmp_rate;
    if(sscanf(data, "%d", value) != 1) return -1;
    tmp_rate = XP_RATE_D->query_race_xp_rate(race);
    if(tmp_rate) return tmp_rate;
    return value;
  }
  /* nat prot */
  if(slot == 12) {
    if(info) return data;
    switch(data) {
    case "low": return 20;
    case "high": return 33;
    default: return 0;
    }
  }

  /* background skill */
  if(slot == 13) return data;

  /* should not end here */
  return -1;
}

