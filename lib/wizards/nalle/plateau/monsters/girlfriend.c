inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21+random(3));
    set_gender(2);
    set_race("human");
    set_name("eva");
    set_alias("Eva");
    set_short("Eva, a blonde girl smirking wryly");
    set_long	(
	"Eva is a young blonde girl, with a kinky smile on her face. She\n"+
	"is clad in a school costume and her long blonde hair reaches\n"+
	"the lower part of her back.\n"
		);

    set_al(1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
 chat_str = allocate(4);
 chat_str[0] ="Eva sighs 'Armin was such a wimp.'\n";
 chat_str[1] ="Eva says 'Armin gave me this bottle at least, but i still won't come back.'\n";
 chat_str[2] ="Eva whines 'Did Armin send you?!?'\n";
 chat_str[3] ="Eva sobs 'Now I need to find a new guy.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
a_chat_str[0] = "Eva growls 'Another wimp, just like Armin!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

 move_object( clone_object("/wizards/nalle/plateau/eq/salmaripullo"), this_object());

}

ask_question(string str)
{
 string *messuja;

 if(!str) return 1;
 str = lower_case(str);

 messuja = 	({ 
	"Are you trying to get me to return to Armin!?!?",
	"No way I'm returning to that wimp!!!",
	"OMG!!! He gave me this bottle to return to him, but i WON'T!",
	"LOL!!! Armin gave me this bottle to come back to him, but i won't!",
	"Hehee, are you one of his pussy friends!!?!11!! LOL!",
		});

 if(str == "armin")
   {
    write("Eva says '"+messuja[ random( sizeof(messuja) )  ]+"'\n");
    return 1;
   } 
}
