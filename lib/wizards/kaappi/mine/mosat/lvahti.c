inherit "obj/monster";
string chat_str;
object weapon;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(30 + random(5));
  set_name("dalana");
  set_race("dwarf");
  set_alias("dwarf");
  set_gender(2);
   set_short("Dalana, the dwarven teacher");
  set_long("An old and rigorous looking dwarf, sitting\n"+
             "on her chair. She is here to watch and teach these children and\n"+
            "keep this room in order\n");
  set_al(40);

weapon = clone_object("/wizards/kaappi/mine/kamat/keppi.c");
move_object(weapon, this_object());
init_command("wield staff");
  set_aggressive(0);

if (!chat_str) {
   chat_str = allocate(2);
   chat_str[0] = "Dalana says: 'Hmm, where is it...'\n";
    chat_str[1] = "Dalana says: 'How can I teach these kids now?'\n";
}
load_chat(2, chat_str);
}
catch_tell(str) {
     string tmp1,tmp2;
     object ob;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1,tmp2) == 2) {
    ob = present("book", this_object());
  if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
   write("Dalana says:'Ooh, Thank you! Now I can teach these children.'\n");
  this_player()->set_quest("Return Dalana's book");
}
}
return 1;
}
