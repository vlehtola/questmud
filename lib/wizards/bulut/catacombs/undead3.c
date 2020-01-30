inherit "/obj/monster";
string who;
object ob;
int i;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(25);
    set_name("soul");
    set_alias("undead");
    set_undead(1);
    set_short("Lost soul is wandering here");
    set_long("This poor soul seems desperate, looking for a way to free himself.\n");
    set_al(0);
    set_aggressive(0);
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast bolt", 50);
    set_skill("mana control", 20);       
    set_skill("chanting", 40);
    set_spell_chance(40,"exs fla blt");   
    set_gender(1);
    set_race("human");
        chat_str = allocate(3);
         chat_str[0] =
          "Soul whines 'All I tried to do is feed my family.'\n";
	chat_str[2] =
	  "Soul whines 'I just cant leave, until I know my family will survive.'\n";
	
    load_chat(15, chat_str);

}               
                                                 
 catch_tell(str) {
if(sscanf(str,"%s gives diamond to Soul",who)) {
call_out("helb", 2);
	}
}
helb() {
tell_room(environment(find_player(lower_case(who))),"Soul says 'This is way too much!'\n");
tell_room(environment(find_player(lower_case(who))),"Soul says 'You have set me free!'\n");
call_out("jees", 1);
    }               
jees(){
tell_room(environment(find_player(lower_case(who))),"Suddenly the ground trembles!'\n");
        move_object(clone_object("/wizards/bulut/catacombs/guardian"), environment(this_object()));
environment(find_player(lower_case(who)))->add_exit("west","/wizards/bulut/catacombs/cata6");
}                                         