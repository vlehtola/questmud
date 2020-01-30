#define SAVEDIR "/data/spellbook/"

string spell_words, long_desc;
static string owner;

reset(arg) {
   if (arg) { return; }
   if (!this_player()) { return; }
   if (restore_object(SAVEDIR+lower_case(this_player()->query_real_name()))) {
   }
   else {
      spell_words = allocate(100);
   }
   owner = capitalize(this_player()->query_real_name());
}

long() {
   long_desc = "";
   long_desc += "The covers are made of fine leather, and the paper seems\n";
   long_desc += "to be in a good conditition. It has a "+get_book_rank()+" on it.\n";
   long_desc += "Maybe you should read it.\n";
   write(long_desc);
}
query_long() { return long_desc; }

get_book_rank() {
   int i, counter;
   string rank;
   while (spell_words[i]) {
       counter += 1;
       i += 2;
   }
   if (counter >= 30) { return "mithril star"; }
   if (counter >= 15) { return "platinum star"; }
   if (counter >= 5) { return "golden star"; }
   return "silver star";
}

drop() { return 1; }

get() { return 1; }

short() {
   string desc;
   desc = owner + "'s spellbook with " + get_book_rank() + " on it";
   return desc;
}

query_auto_load() {
    return "guilds/obj/spellbook:";
}

init() {
   add_action("read", "read");
}

id(str) {
// Fixed by Gynter, removed str == "book"
   if (str == "spellbook") { return 1; }
}

check_spell(spell) {
   int i;
   while(i < sizeof(spell_words)) {
     if (spell_words[i] == spell) { return 1; }
     i += 2;
   }
   return 0;
}

read(str) {
 string spell,temp;
 int i, passed;
 if (!str) { return; }
// Fixed by Gynter, removed str == "book"
 if (str == "spellbook") {
   show_spells();
   write("You could 'read spellbook [spellname]' for more information.\n");
   return 1;
 }
// Fixed by Gynter, removed (sscanf(str, "book %s", spell)) } and modified line 82 from if(sscanf(str, "spellbook %s", spell) || to current 
if (sscanf(str, "spellbook %s", spell)) {
   if (!check_spell(spell)) {
     write("You don't have such a spell in your spellbook.\n");
     return 1;
   }
   write("You turn to the page describing ");
   write(capitalize(spell)+":\n");

   while(sscanf(spell, "%s %s", spell, temp) == 2) {
     spell = spell +"_"+ lower_case(temp);
   }
   if (file_size("/guilds/spell_descs/essence/"+spell) != -1) {
     cat("/guilds/spell_descs/essence/"+spell);
     return 1;
   }
   write("No description available.\n");
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
   if (sscanf(words, "exs %s", tmp) != 1) {
     write("Not a mage spell.\n");
     return 0;
   }
   while (spell_words[i] && i < 110) {
     if (spell_words[i+1] == words) {
       write("You already have the spell in your spellbook.\n");
       return 0;
     }
     i += 2;
   }
   if(i>105) {
     write("Too many spells.. execution aborted.\n");
     return 0;
   }
   spell_words[i] = spell;
   spell_words[i+1] = words;
   write("Your spellbook glows for a moment.\n");
   file = SAVEDIR + lower_case(this_player()->query_name());
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

