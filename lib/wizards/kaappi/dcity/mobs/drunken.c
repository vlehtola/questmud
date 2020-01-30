inherit "obj/monster";
string chat_str;

reset(arg) {
  ::reset(arg);
   if(arg) { return; }
   set_level(10+random(10));
   set_name("dwarf");
   set_race("dwarf");
   set_gender(1);
   set_short("A drunken dwarf");
   set_long("A short but fat dwarf sitting on the chair.\n"+
            "The table next to him is filled with empty glasses\n"+
            "and bottles. His nose is bright red and it seems that\n"+
            "he has problems to keep his head up.\n");
   set_al(40);
   set_aggressive(0);

if(!chat_str) {
   chat_str = allocate(3);
   chat_str[0] = "Dwarf hiccups and mumbles: 'Fhiinally Thhordim hasss returned.'\n";
   chat_str[1] = "\n";
   chat_str[2] = "\n";

}
load_chat(3, chat_str);
}
