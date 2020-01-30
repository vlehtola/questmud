/* This file is no longer in use as clerics don't have books anymore */ 


string spell_words; 
static string owner;

reset(arg) {
   if (arg) { return; }
   if (restore_object("world/cleric/spellboo/" + lower_case(this_player()->query_real_name()))) {
   }
   else {
      spell_words = allocate(100);
   }
   owner = this_player()->query_name();
}

long() {
   write("The covers are made of some soft, gray material, and the paper\n" + 
         "seems to be in good condition.\n");
   write("Maybe you should read it.\n");
}

drop() { return 1; }

get() { return 1; }

short() {
   string desc;
   desc = owner + "'s holy spellbook";
   return desc;
}

query_auto_load() {
    return "guilds/obj/clericbook:";
}

init() {
   add_action("read", "read");
}

id(str) {
   if (str == "spellbook" || str == "book") { return 1; }
}

read(str) {
   if (str == "book" || str == "spellbook") {
      show_spells();
      return 1;
   }
}

show_spells() {
   int i;
   while (i < sizeof(spell_words)) {
       if (spell_words[i]) {
           write(spell_words[i] + ": '"); 
           write(spell_words[i+1] + "'\n");       
       }
       i += 2;
   }
   if (spell_words[0]) { return 1; }
   return 0;
}

add_spell(spell, words) {
   string file, tmp;
   int i;
   if (sscanf(words, "chl %s", tmp) != 1) {
	return;
   }
   while (spell_words[i]) {
       if (spell_words[i+1] == words) { return; }
       i += 2;
   }
   spell_words[i] = spell;
   spell_words[i+1] = words;
   write("Your spellbook glows for a moment.\n");
   file = "world/cleric/spellboo/" + lower_case(this_player()->query_name());
   save_object(file);
   return 1;
}

query_words(str) {
   int i;
   while (i < sizeof(spell_words)) {
       if (spell_words[i]) {
           if (str == spell_words[i+1]) {
                return 1;
           }
       }
       i += 2;
   }
   return 0;
}

query_weight() { return 300; }
