inherit "obj/monster";
int done;

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(22);
  set_name("terran");
  set_alias("overseer");
  set_race("dwarf");
  set_gender(1);
  set_short("Terran, the overseer of tunnels of Kohr");
  set_long("Terran is the overseer of the snowy tunnels of Kohr. The overseer seems\n" +
           "to be particularly big for a Dwarf, and no wonder why he has been chosen\n" +
           "to watch over the tunnels. Terran has a thick, long beard covering most\n" +
           "of the lower part of his face. He is clad in clothes made of leather.\n" +
           "Terran seems to posses considerable amount of strength in his arms.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Terran looks at you consideringly and smiles.\n";
    chat_str[1] = "Terran says: 'Two of our habitants caused so much trouble that we had to\n" +
                  "              banish them in the lower levels of the tunnels. It's so sad.'\n";
    chat_str[2] = "Terran says: 'I've heard the Harald and Serak living in the second level\n" +
                  "              have had some disagreements with each other due to their pets.'\n";
    chat_str[3] = "Terran says: 'My son left almost a day ago and haven't returned. If you happen\n" +
                  "              to see him, please let him know that I already miss him and he\n" +
                  "              should return to home immediately.'\n";
}
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Terran curses at you and strikes.\n";
    a_chat_str[1] = "Terran kicks the snow at your face.\n";
 }
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_resists("cold", 50);
  set_str(query_str() + 50);
  set_exp(query_exp() + 5000);
  move_object(clone_object("/wizards/ahma/ice/eq/lpants"), this_object()); init_command("wear pants");
  move_object(clone_object("/wizards/ahma/ice/eq/lshoes"), this_object()); init_command("wear slippers");
  move_object(clone_object("/wizards/ahma/ice/eq/lcap"), this_object()); init_command("wear cap");
  move_object(clone_object("/wizards/ahma/ice/eq/lgloves"), this_object()); init_command("wear mittens");
  move_object(clone_object("/wizards/ahma/ice/eq/ljacket"), this_object()); init_command("wear jacket");
}
 
catch_tell(str) {
   string giver,item,tmp;
   object ob, item_ob;
   if(!str) { return 1; }
    if(sscanf(str, "%s gives %s to you.", giver, item) == 2) {
     ob = present(lower_case(giver), environment(this_object()));
     if(!ob) { return; }
     item_ob = present("skull", this_object());
     if(!item_ob) { return; }
     if(item_ob->short() != "A bloody skull" && !item_ob->query_no_save()) {
       tell_object(ob, "Terran shouts: 'What the hell are you trying to prove? That my son is dead?'\n");
       tell_object(ob, "Terran gives your " +capitalize(item)+ " back to you.\n");
       move_object(present(item,this_object()), ob);
       return;
    }
   
    if(ob && item_ob && item_ob->short() == "A bloody skull" &&
      !ob->query_quests("Finding Terran's son")) {
      
      tell_object(ob, "Congratulations! You completed the quest 'Finding Terran's son'\n");
      call_other(ob, "set_quest", "Finding Terran's son");
      }
    else { write("You have already completed this quest.\n"); }
    destruct(item_ob);
    return 1;
    }
 }
