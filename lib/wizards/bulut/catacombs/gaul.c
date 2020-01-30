inherit "/obj/monster";
int i;

init() {
::init();
i=random(2);

if(!i) {
move_object("/wizards/bulut/catacombs/amulet",this_object());
this_object()->init_command("wear amulet");
}

if(i=1) {
move_object("/wizards/bulut/catacombs/gauntlets",this_object());
this_object()->init_command("wear gloves");
}




}

object ob;
string who;
string short;
reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(63 + random(5));
    set_name("gaul");
    set_alias("man");
    set_short("Gaul Yn'ngrah, harness of the weak and despair");
    set_long("This large man looks a bit pale, the sunlight has not touched him \n" +
	     "for a long while. You can tell from his eyes that he lives\n" +
	     "his life for evil purposes. \n");
    set_al(-100);
    set_aggressive(0);
    set_gender(1);
    set_mage(1);
    set_str(300 + random(150));
    set_log();
    set_race("human");
        chat_str = allocate(2);
         chat_str[0] =
          "Gaul storms 'You have released me!'\n";
        chat_str[1] =
          "Gaul storms 'The paladins trapped me inside this statue years ago.'\n";
    load_chat(2, chat_str);

}               



catch_tell(str) {
if(sscanf(str,"%s is DEAD, R.I.P.",who)) {
if(!find_player(lower_case(who))) { return 1; }
tell_room(environment(this_object()), "Gaul's eyes flash dark red. Lightning strikes!\n" +
"The soul of " + who + " materializes and starts to fight on its masters side!\n");

short=find_player(lower_case(who))->short();
if( who == "Soul" ) return 1;
ob = clone_object("/obj/monster");
ob->set_level(20);
ob->set_aggressive(1);
ob->set_undead(1);
ob->set_alias("soul");
ob->set_name("soul");
ob->set_mage(1);
ob->set_short("Wailing soul of " + short);
move_object(ob,environment(this_object()));
		}                 
}       
                                 
