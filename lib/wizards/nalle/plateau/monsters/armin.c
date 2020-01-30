inherit "obj/monster";

int depressed=1;

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21+random(3));
    set_gender(1);
    set_race("human");
    set_name("armin");
    set_alias("man");
    set_short("Armin, a depressed young man");
    set_long	(
	"Armin is a young man in his twenties, clad in unexpensive clothes.\n"+
	"He seems to be rather sad, sobbing and wiping away tears constantly.\n"
		);

    set_al(1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
 chat_str = allocate(4);
 chat_str[0] ="Armin sighs 'Nyyh, my girlfriend left me.'\n";
 chat_str[1] ="Armin says 'Puuh, I really could use a drink now.'\n";
 chat_str[2] ="Armin whines 'You could try to help me out, not just stand there.'\n";
 chat_str[3] ="Armin sobs 'Rutger used to have that nice herbal liquor.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
a_chat_str[0] = "Armin growls: 'Ah, this is a good way to deal with my aggressions'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}


catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    int i;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }

   item_ob = present("jekkupullo", this_object());
   if (!item_ob) item_ob = present("salmaripullo", this_object()); 
   if (!item_ob) return;

   if(item_ob->query_no_save()) return;

      if (!((item_ob->short() != "A bottle of herbal liquor") ||
           (item_ob->short() != "A bottle of liquorice liquor"))) {
 tell_object(ob, "Armin says 'This is no good.'\n");
 tell_object(ob, "Armin gives the "+capitalize(item)+" back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
if(present("jekkupullo", this_object()) && !present("salmaripullo", this_object()))
say("Armin says 'Gee, thanks. I could use some different brand to mix this with too.'\n");

if(!present("jekkupullo", this_object()) && present("salmaripullo", this_object()))
say("Armin says 'Gee, thanks. I could use some different brand to mix this with too.'\n");

   if(present("jekkupullo", this_object()) && 
      present("salmaripullo", this_object()) )
      if (!ob->query_quests("Help Armin")) {
say("Armin opens up the bottles and mixes a drink, then drinks it up.\n");
say("Armin says 'Thanks, you've been a great help, I feel better already.'\n");
set_short("Armin, a young man");
         tell_object(ob, "You complete the 'Help Armin' quest.\n");
         call_other(ob, "set_quest", "Help Armin");
 
  if(present("jekkupullo", this_object())) 
    destruct(present("jekkupullo",this_object()));
  if( present("salmaripullo", this_object()) ) 
    destruct( present("salmaripullo",this_object()));

      } 
    }
}

ask_question(string str)
{
 string *messuja;

 if(!str) return 1;
 str = lower_case(str);

 messuja =      ({
        "I'm sooo lonely now...",
        "Sniff, Eva left me. Please help me...",
        "I wish I'd feel a bit better...",
        "I don't know if Eva will return to me...",
                });

 if(str == "eva" || str == "help")
   {
    write("Armin sighs '"+messuja[ random( sizeof(messuja) )  ]+"'\n");
    return 1;
   }
}
