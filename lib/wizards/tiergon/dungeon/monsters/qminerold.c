inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(8);
    set_exp(1);
    set_name("Miner");
    set_alias("miner");
    set_race("human");
    set_gender(1);
    set_short("A grievously wounded miner");
    set_long("The miner appears to have poisoned by some fell creature before he was trapped behind the rockfall.\n");
    set_al(15);
    if(!chat_str) {
       chat_str = allocate(1);
       chat_str[0] = "The miner convulses from the effects of some horrible poison!\n";
}
load_chat(20, chat_str);
  }
catch_tell(str) {
    string giver, item;
     object ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to Miner.", giver, item) == 2) {
ob = present(lower_case(giver),environment(this_object()));
if (!ob) { return; }
if (!present("herbs",this_object())) {
         say("The miner says that the "+(item)+" cannot help him.\n");
         write("The miner sadly hands the "+(item)+" back to you.\n");
         say("The miner sadly hands the "+(item)+" back to "+capitalize(giver)+".\n",this_player());
         move_object(present(item,this_object()), ob);
         return 1;
}
        call_out("jatko", 1, giver);  
}
}

jatko(giver) {
      init_command("eat herbs");
      write("The miner thanks you for your help.\n");
      say("The miner thanks "+capitalize(giver)+" for his help.\n",this_player());
      write("The miner hands you a pendant as a token of his gratitude.\n");
      say("You notice that the miner gives "+capitalize(giver)+" something.\n",this_player());
      move_object(clone_object("/wizards/tiergon/eq/pendant"), this_player());
      say("The miner swears to leave the mines and never come back and runs out.\n");
      if (giver && !giver->query_quest("Poisoned miner")) {
         write("Congratulations, you have completed the 'Poisoned miner' quest");
      giver->set_quests("Poisoned miner", 15);      
       }
      destruct(present("coins",this_object()));
      destruct(this_object());     
      return 1;  
  } 


