inherit "obj/monster";

int q;
string str;
object weapon,chat_str,a_chat_str;
reset(arg) {

    q = random(6);
    ::reset(arg);
    if(arg) { return; }

    if(q==0) str = "Lruh";
    if(q==1) str = "Murak";
    if(q==2) str = "Srahr";
    if(q==3) str = "Krama";
    if(q==4) str = "Drok";
    if(q==5) str = "Tukar";

    if(q==0) { set_name("lruh");
             }
    if(q==1) { set_name("murak");
             }
    if(q==2) { set_name("srahr");
             }
    if(q==3) { set_name("krama");
             }
    if(q==4) { set_name("drok");
             }
    if(q==5) { set_name("tukar");
             }



    set_str(query_str()*5/3);
    set_level(49);
    set_race("troll");
    set_alias("guard");
    set_short(str+" the guard of the camp");
    set_long("A strong and nimble troll guard guarding the entrance of the camp. He\n"+
             "is extremely confident about himself and it looks like nothing could\n"+
             "scare him.\n");
      
    set_al(-30);
    set_aggressive(0);
    set_al_aggr(371);
    set_gender(1);
    set_skill_chance("strike",33);
    set_skill("strike",80);
    set_skill("dodge", 100);
    set_skill("tumble", 40);
    set_skill("deceived attack", 80);


    if (!chat_str) {
        chat_str = allocate(3);
    chat_str[0] = "The troll guard grunts 'I hope you aren't here to spy on our camp, if\n"+
                  "that's true I'll have to punish you.'\n";
    chat_str[1] = "The troll guard scrathes his back and his neck.\n";
    chat_str[2] = "The troll guard swings his flail.\n";             
       }
    load_chat(2, chat_str);
 

    if (!a_chat_str) {
        a_chat_str = allocate(2);
    a_chat_str[0] = "The troll guard swing his warhammer and screams in rage!\n";
    a_chat_str[1] = "The troll guard grunts 'You won't get away with this!'\n";
       }
    load_a_chat(3, a_chat_str);
 

    weapon = clone_object("/wizards/siki/troll/eq/warhammer2");
    move_object(weapon,this_object());
    init_command("wield warhammer");


}
