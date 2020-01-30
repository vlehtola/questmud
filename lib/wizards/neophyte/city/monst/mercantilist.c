inherit "obj/monster";
string chat_str;
status q;
object head,amu;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("mercantilist");
        set_alias("cereon");
        set_level(60+random(6));
        set_gender(1);
        set_race("human");
        set_al(-10);
        set_short("Cereon the merchant, mortal enemy of the Lowie family");
        set_long("An elegant looking man with grey, long hair and grey, bushy eyebrows. He\n"+
                 "is old but strong, independent gentleman who owns the general shop. He has\n"+
                 "lost his entire family in shipwreck. People say that he is the mortal enemy\n"+
                 "of the Lowie family. The Lowie family owns the both weapon and armour shops.\n");

        set_log();
        set_skill("mana control", 100);
        set_skill("cast essence", 100);
        set_skill("cast fire", 100);
        set_skill("cast force field", 100);
        set_skill("cast locate", 100);
        set_skill("abjuration", 100);
        set_skill("cast storm", 100);
        set_spell_chance(5, "exs fla zum");
        set_spell_chance(5, "exs fla loc");
        set_spell_chance(1, "exs fla strm");
        set_dead_ob(this_object());
        set_max_hp(query_hp()+20000);
        set_hp(query_max_hp());
                if(!chat_str) {
                  chat_str = allocate(2);
                  chat_str[0] = "Cereon says something about job and orb.\n";
                  chat_str[1] = "Cereon arranges some of the items.\n";
                }
                load_chat(2, chat_str);
                if(!random(2)) {
head = clone_object("/wizards/neophyte/city/eq/chead");
move_object(head, this_object());
}
if(!random(1)) {
amu = clone_object("/wizards/neophyte/city/eq/camu");
move_object(amu,this_object());
}
init_command("wear all");
}

ask_question(str) {
        if(str == "orb") {
                say("Cereon says: 'I have managed to found one of the orbs but i haven't got any clue about what it does.'\n");
                return 1;
        }
        if(str == "job") {
                        say("Cereon says: 'Go and kill both lowies and come back here and ask reward, remember you have to got the final blow.'\n");
                        return 1;
                }
        if(str == "help") {
			say("Cereon says: 'I might have a job for you.'\n");
		return 1;
	}
                if(str == "reward") {
                        say("Cereon hmms carefully\n");
                        perform();
                        return 1;
                }
say("Cereon says: 'I don't know anything about that.'\n");
return 1;
}
perform() {
        object orb;
        if(!call_other("/wizards/neophyte/city/armour_shop.c", "query_killer",0)) {
        say("Cereon says: 'But the Loxie is still living.\n");
        return 1;
}
        if(!call_other("/wizards/neophyte/city/weapon_shop.c", "query_killer",0)) {
        say("Cereon says: 'But the Caulos is still living.\n");
        return 1;
}
if(call_other("/wizards/neophyte/city/weapon_shop.c", "query_killer",0) != call_other("/wizards/neophyte/city/armour_shop.c", "query_killer",0)) {
        say("Cereon says: 'Yes they are dead but how i am suppose to break half the reward?'\n");
        return 1;
}
if(q) { say("Cereon says: 'But i don't require anymore help.'\n"); return 1; }

if(!random(1)) {
        say("Cereon says: 'Here is something for you.'\n");
        orb = clone_object("/wizards/neophyte/city/obj/orb");
        move_object(orb, this_player());
        say("Cereon gives something to "+this_player()->query_name()+".\n");
        write("Cereon gives you the orb.\n");
        q = 1;
        return 1;

} else { q = 1;
say("Cereon says: 'I am sorry but i managed to lost the orb.'\n"); return 1; }

say("Cereon ponder something.\n");
return 1;
}

monster_died() {
	if(!random(3) && amu) { destruct(amu); say("Cereon somehow manages to release the magic of amulet and the amulet is ruined.\n"); return 0; }
	return 0;
}