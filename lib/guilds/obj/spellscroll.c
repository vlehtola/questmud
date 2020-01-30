string spell, words, short;
int value;

short() { return short; }

long() {
    write("This scroll contains the magical runes '"+words+"' for the spell '"+spell+"'.\n");
    write("Maybe you could try to 'merge' it to your spellbook if you have one.\n");
    write("You could also read the scroll for information about the spell.\n");
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_no_save() { return 1; }

reset(arg) {
   if (arg) { return; }
   get_words();
   set_short();
}

init() {
   add_action("merge", "merge");
   add_action("read", "read");
}

merge(str) {
   if (str != "scroll") {
	write("Merge what?\n");
	return 1;
   }
   if (!present("spellbook", this_player())) {
	write("You don't have a spellbook where to merge the scroll.\n");
	return 1;
   }
   if (present("spellbook", this_player())->add_spell(spell,words)) {
   	write("You merge the scroll to your spellbooks.\n");
   } else {
	write("Nothing happens.\n");
	return 1;
   }
   destruct(this_object());
   return 1;
}

set_short() {
   short = "An old and yellowed scroll";
}
query_long() { return "An old and yellowed scroll.\n"; }
query_value() { return value; }

get_words() {
  int i;
  spell = "";
  words = "exs ";
  value = 500;
  i = random(4) + 1;
  if(i == 1) {
    i = random(4) +1;
    if(i==1) { words += "fla"; spell = "fire"; }
    if(i==2) { words += "brr"; spell = "ice"; }
    if(i==3) { words += "zzt"; spell = "electric"; }
    if(i==4) { words += "sol"; spell = "earth"; }
    if(!random(4)) {
      words += " strm";
      spell += " storm";
    } else {
      words += " blt";
      spell += " bolt";
    }
    return;
  }
  words += get_random_pref();
  words += get_random_type();
  get_spell_name();
  return 1;
}

get_random_type() {
  int i;
  i = random(6) +1;
  switch(i) {
    case 1: return " huh";
    case 2: return " cre";
    case 3: return " trn";
    case 4: return " ils";
    case 5: return " rha";
    case 6: return " loc";
  }
}

get_random_pref() {
  int i;
  i = random(4) +1;
  switch(i) {
    case 1 : return "fla";
    case 2 : return "brr";
    case 3 : return "zzt";
    case 4 : return "sol";
  }
}
get_spell_name() {
  string tmp,tmp2,tmp3;
  if(sscanf(words, "exs %s %s", tmp,tmp2) != 2) return;
  spell = get_skitso(tmp,tmp2);
}
get_skitso(string tmp,string tmp2) {
  if(tmp2 == "rha") {
    switch(tmp) {
    case "fla" : return "floating disc";
    case "brr" : return "transform";
    case "zzt" : return "money to power";
    case "sol" : return "unlock box";
    }
  }
  if(tmp2 == "zum") {
    switch(tmp) {
    case "sol": return "shelter";
    case "brr": return "anti-magic field";
    case "fla": return "force field";
    case "zzt": return "dispel field";
    }
  }
  if(tmp2 == "huh") {
    switch(tmp) {
    case "fla" : return "identify weapon";
    case "brr" : return "identify armour";
    case "sol" : words = "exs zzt huh"; return "identify monster";
    case "zzt" : return "identify monster";
    }
  }
  if(tmp2 == "ils") {
    switch(tmp) {
    case "fla" : return "true seeing";
    case "brr" : return "invisibility";
    case "zzt" : return "mirror image";
    case "sol" : return "create illusion";
    }
  }
  if(tmp2 == "trn") {
    switch(tmp) {
    case "fla" : return "relocate";
    case "brr" : return "summon";
    case "zzt" : return "teleport";
    case "sol" : return "heavy weight";
    }
  }
  if(tmp2 == "cre") {
    switch(tmp) {
    case "fla" : return "create light";
    case "brr" : return "summon darkness";
    case "zzt" : return "create item";
    case "sol" : return "create food";
    }
  }
  if(tmp2 == "loc") {
    switch(tmp) {
    case "fla" : return "banish";
    case "brr" : return "show coordinates";
    case "zzt" : return "outworld party teleport";
    case "sol" : return "outworld teleport";
    }
  }
  if(tmp2 == "prc") {
    switch(tmp) {
    case "fla" : return "protection from fire";
    case "brr" : return "protection from cold";
    case "zzt" : return "protection from electric";
    case "sol" : return "physical protection";
    }
  }
}

get_cleric_words() {
}

read(arg) {
 string str, temp;
 if (arg != "scroll") { return; }
 str = spell;
 while(sscanf(str, "%s %s", str, temp) == 2) {
   str = str +"_"+ lower_case(temp);
 }
 if (file_size("/guilds/spell_descs/essence/"+str) != -1) {
   cat("/guilds/spell_descs/essence/"+str);
   return 1;
  }
}
